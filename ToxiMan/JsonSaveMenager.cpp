#include "JsonSaveMenager.h"

//#pragma warning(disable : 4996)

void JsonSaveMenager::SaveObject(ObjectManager &obj, string name_file, LevelNumber& number)
{
	m_json["ID"] = obj.GetObjectID();
	m_json["Name"] = obj.GetName();

	m_json["PosX"] = obj.GetShape().getPosition().x;
	m_json["PosY"] = obj.GetShape().getPosition().y;

	m_json["SizeX"] = obj.GetShape().getSize().x;
	m_json["SizeY"] = obj.GetShape().getSize().y;

	m_serializedString = m_json.dump();

	m_fout.open("Resources/JsonSave/" + to_string((int)number) + "/" + name_file, ofstream::app);
	m_fout << m_serializedString << "\n";
	m_fout.close();
}

vector<ObjectManager> JsonSaveMenager::LoadVecObject(string name_file, LevelNumber& number)
{

	vector<ObjectManager> vec;
	string temp = "Resources/JsonSave/" + to_string((int)number) + "/" + name_file;

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

void JsonSaveMenager::DeleteJsonFile(string name_file, LevelNumber& number)
{
	string str_temp = "Resources/JsonSave/" + to_string((int)number) + "/" + name_file;
	//char* char_temp = new char[str_temp.size()];
	//strcpy(char_temp, str_temp.c_str());
	remove(str_temp.c_str());
	cout << "DeleteJsonFile" << endl;
}
