#include "JsonSaveMenager.h"

#pragma warning(disable : 4996)

void JsonSaveMenager::SaveObject(ObjectManager &obj, string name_file, LevelNumber& number)
{
	m_json["ID"] = obj.m_ID;
	m_json["Name"] = obj.m_name;

	m_json["PosX"] = obj.m_shape.getPosition().x;
	m_json["PosY"] = obj.m_shape.getPosition().y;

	m_json["SizeX"] = obj.m_shape.getSize().x;
	m_json["SizeY"] = obj.m_shape.getSize().y;

	m_serializedString = m_json.dump();

	m_fout.open("Resources/JsonSave/" + to_string((int)number) + "/" + name_file, ofstream::app);
	m_fout << m_serializedString << "\n";
	m_fout.close();
}

vector<ObjectManager> JsonSaveMenager::LoadVecObject(string name_file, LevelNumber& number)
{

	vector<ObjectManager> vec;
	string temp = "Resources/JsonSave/" + to_string((int)number) + "/" + name_file;
	//string temp2 = "Resources/JsonSave/" + to_string((int)number) + "/" + "Save/" + name_file;
	m_fin.open(temp);
	if (!m_fin.is_open()) {
		cout << "error: " << temp << " not open!" << endl;
		//cout << name_file << endl;
		//if (name_file != "Save/file_beck.json" && name_file != "Save/file_zero.json" && name_file != "Save/file_front.json")
		//	LoadVecObject("Save/" + name_file, number);
	}
	else {
		//cout << "file open!" << endl;
		string line;
		ObjectManager object;
		while (std::getline(m_fin, line))
		{
			m_json = Json::parse(line);
			if (name_file == "file_beck.json") {
				object.CreateTextureBoxBeck(m_json);
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
			if (name_file == "Save/file_beck.json") {
				object.CreateTextureBoxBeck(m_json);
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


	//string str_temp = "Resources/JsonSave/" + to_string((int)number) + "/" + name_file; 
	//char* char_temp = new char[str_temp.size()];
	//strcpy(char_temp, str_temp.c_str());
	//if (name_file != "Save/file_beck.json" && name_file != "Save/file_zero.json" && name_file != "Save/file_front.json")
	//	remove(char_temp);             // удаление файла 

		
	return vec;
}

void JsonSaveMenager::DeleteJsonFile(string name_file, LevelNumber& number)
{
	string str_temp = "Resources/JsonSave/" + to_string((int)number) + "/" + name_file;
	char* char_temp = new char[str_temp.size()];
	strcpy(char_temp, str_temp.c_str());
	remove(char_temp);
}
