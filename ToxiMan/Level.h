#pragma once

#include "System.h"

#include "World.h"

#include "GameStates.h"

#include "ObjectManager.h"

#include "JsonSaveMenager.h"

#include "Player.h"

#include "Architect.h"


class Level
{
private:
	 JsonSaveMenager  m_jsonSM;


	Player* m_ptr_player;
	Architect* m_ptr_arhitevt;

	bool is_from_arhitetc;

	vector<ObjectManager> m_objectListBeck;
	vector<ObjectManager> m_objectListZero;
	vector<ObjectManager> m_objectListFront;

public:

	v2f GetPositionPlayer();

	void LoadLevel(LevelNumber &number);


	Level();
	void Action(StateGame& state_game, LevelNumber& number);
	void Update(StateGame& state_game, LevelNumber& number);
	void Draw(StateGame& state_game, LevelNumber& number);
	~Level();
};

