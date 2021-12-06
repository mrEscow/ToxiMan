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

	void SaveMap(string name, Map &map, UINT32 GameLevel);
	Map LoadMap(string name, UINT32 GameLevel);

	void SaveObject(ObjectManager &obj, string name_file, UINT32 GameLevel);
	vector<ObjectManager> LoadVecObject(string name_file, UINT32 GameLevel);

	void DeleteJsonFile(string name_file, UINT32 GameLevel);
};

