#pragma once
#include "System.h"
#include "World.h"

#include "Player.h"
#include "GameStates.h"
#include "Architect.h"

#include "Level.h"

class JsonSaveMenager
{
private:
	Json m_json;
	string m_serializedString;
	ofstream m_fout;
public:
	void SaveObject(ObjectManager &obj, string name_file);
};

