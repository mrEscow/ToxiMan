#pragma once
#include"System.h"
#include"World.h"
#include "ObjectManager.h"
#include "GameStates.h"
class Architect
{
	Shape m_shape;
	vector<ObjectManager> objectList;

public:
	Architect();
	void Action(StateGame& state_game);
	void Update();
	void Draw(StateGame& state_game);
	//~Architect();
};

