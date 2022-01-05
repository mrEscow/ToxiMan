#include "JsonSaveMenager.h"

//#pragma warning(disable : 4996)

void JsonSaveMenager::SaveMap(string name_file, Map &map, UINT32 GameLevel)
{
	m_json.clear();

	if (!map.GetName().empty())
		m_json["Name"] = map.GetName();			// string
	else
		m_json["Name"] = "TEST";

	m_json["MapSizeX"] = map.GetMapSize().x;	// int
	m_json["MapSizeY"] = map.GetMapSize().y;	// int

	m_json["MapStartPosX"] = map.GetStartPos().x;	// float
	m_json["MapStartPosY"] = map.GetStartPos().y;	// float

	m_json["MapFinalPosX"] = map.GetFinalPos().x;	// float
	m_json["MapFinalPosY"] = map.GetFinalPos().y;	// float

	m_serializedString = m_json.dump();

	//m_fout.open("Resources/JsonSave/maps/" + to_string(GameLevel) + "/" + name_file, ofstream::app);
	m_fout.open("Resources/JsonSave/maps/map_" + to_string(GameLevel) + ".json", ofstream::app);
	m_fout << m_serializedString << "\n";
	m_fout.close();
}

Map JsonSaveMenager::LoadMap(string name_file, UINT32 GameLevel)
{
	string temp = "Resources/JsonSave/maps/map_" + to_string(GameLevel) + ".json";

	Map temp_map;
	
	m_fin.open(temp);

	if (!m_fin.is_open()) {
		cout << "error: " << temp << " not open!" << endl;
		cout << "Create default map" << endl;

		temp_map.SetName("NEW");		// string
		// Logic
		temp_map.SetMapSize(v2i(120,50));	// int
		// View
		temp_map.SetStartPos(v2f(0.0f,0.0f));	// S
		temp_map.SetFinalPos(v2f(0.0f, 0.0f));	// F
	}
	else {

		string line;


		while (std::getline(m_fin, line))
		{
			m_json = Json::parse(line);

			temp_map.SetName(m_json["Name"].get<string>());		// string


			// Logic
			temp_map.SetMapSize(v2i(m_json["MapSizeX"].get<int>(), 
									m_json["MapSizeY"].get<int>()));	// int


			// View
			temp_map.SetStartPos(v2f(m_json["MapStartPosX"].get<float>(), 
									 m_json["MapStartPosY"].get<float>()));	// S

			temp_map.SetFinalPos(v2f(m_json["MapFinalPosX"].get<float>(), 
									 m_json["MapFinalPosY"].get<float>()));	// F

		}
	}

	m_fin.close();
	return temp_map;
}

void JsonSaveMenager::SaveObject(ObjectManager &obj, string name_file, UINT32 GameLevel)
{
	m_json.clear();

	m_json["ID"] = obj.GetObjectID();
	m_json["Name"] = obj.GetName();

	m_json["PosX"] = obj.GetShape().getPosition().x;
	m_json["PosY"] = obj.GetShape().getPosition().y;

	m_json["SizeX"] = obj.GetShape().getSize().x;
	m_json["SizeY"] = obj.GetShape().getSize().y;

	m_serializedString = m_json.dump();

	m_fout.open("Resources/JsonSave/" + to_string(GameLevel) + "/" + name_file, ofstream::app);
	m_fout << m_serializedString << "\n";
	m_fout.close();
}

vector<ObjectManager> JsonSaveMenager::LoadVecObject(string name_file, UINT32 GameLevel)
{

	vector<ObjectManager> vec;
	string temp = "Resources/JsonSave/" + to_string(GameLevel) + "/" + name_file;

	m_fin.open(temp);
	if (!m_fin.is_open()) 
		cout << "error: " << temp << " not open!" << endl;
	else {
		string line;
		ObjectManager object;
		while (std::getline(m_fin, line))
		{
			m_json = Json::parse(line);
			if (name_file == "file_back.json") {
				object.CreateTextureBoxBack(m_json);
				vec.push_back(object);
			}
			if (name_file == "file_zero.json") {
				object.CreateStaticBox(m_json);
				vec.push_back(object);
			}
			if (name_file == "file_front.json") {
				object.CreateTextureBoxFront(m_json);
				vec.push_back(object);
			}
			if (name_file == "Save/file_back.json") {
				object.CreateTextureBoxBack(m_json);
				vec.push_back(object);
			}
			if (name_file == "Save/file_zero.json") {
				object.CreateStaticBox(m_json);
				vec.push_back(object);
			}
			if (name_file == "Save/file_front.json") {
				object.CreateTextureBoxFront(m_json);
				vec.push_back(object);
			}
		}
	}
	m_fin.close();
		
	return vec;
}

void JsonSaveMenager::DeleteJsonFile(string name_file, UINT32 GameLevel)
{
	string str_temp = "Resources/JsonSave/" + name_file + to_string(GameLevel) + ".json";
	remove(str_temp.c_str());
	cout << "DeleteJsonFile" << endl;
}
