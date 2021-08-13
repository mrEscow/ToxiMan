#include "JsonSaveMenager.h"

void JsonSaveMenager::SaveObject(ObjectManager &obj, string name_file)
{
	m_json["ID"] = obj.m_ID;
	m_json["Name"] = obj.m_name;

	m_json["PosX"] = obj.m_shape.getPosition().x;
	m_json["PosY"] = obj.m_shape.getPosition().y;

	m_json["SizeX"] = obj.m_shape.getSize().x;
	m_json["SizeY"] = obj.m_shape.getSize().y;

	m_serializedString = m_json.dump();

	m_fout.open("Resources/JsonSave/" + name_file, ofstream::app);
	m_fout << m_serializedString << "\n";
	m_fout.close();
}
