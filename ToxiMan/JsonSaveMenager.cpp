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
	m_fin.open("Resources/JsonSave/" + to_string((int)number) + "/" + name_file);
	if (!m_fin.is_open()) {
		cout << "error: file not open!" << endl;
	}
	else {
		cout << "file open!" << endl;
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
		}
	}
	m_fin.close();


	string str_temp = "Resources/JsonSave/" + to_string((int)number) + "/" + name_file; 
	char* char_temp = new char[str_temp.size()];
	strcpy(char_temp, str_temp.c_str());
	if (remove(char_temp) != 0)             // удаление файла 
		cout << "error "<< name_file << " not delete" << endl;
	else
		cout << name_file << " delete" << endl;
	return vec;
}
