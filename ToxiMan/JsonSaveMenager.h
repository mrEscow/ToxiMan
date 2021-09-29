#pragma once
//#include "System.h"
//#include "World.h"

#include "GameStates.h"
#include "ObjectManager.h"
#include "Map.h"


class JsonSaveMenager
{
private:
	Json m_json;
	string m_serializedString;
	ofstream m_fout;
	ifstream m_fin;
public:

	void SaveMap(string name, Map &map, LevelNumber& number);
	Map LoadMap(string name, LevelNumber& number);

	void SaveObject(ObjectManager &obj, string name_file, LevelNumber& number);
	vector<ObjectManager> LoadVecObject(string name_file, LevelNumber& number);

	void DeleteJsonFile(string name_file, LevelNumber& number);
};

