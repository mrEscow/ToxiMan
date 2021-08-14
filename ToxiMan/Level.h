#pragma once

#include "GameStates.h"
#include "ObjectManager.h"
#include "JsonSaveMenager.h"
#include "Player.h"
#include "Architect.h"


class Level
{
private:

	LevelNumber *m_ptr_number;

	JsonSaveMenager  m_jsonSM;

	v2f m_firstPos;
	v2f m_size_map;
	

	Player* m_ptr_player;

	Architect* m_ptr_arhitevt;

	bool is_from_arhitetc;

	vector<ObjectManager> m_objectListBeck;
	vector<ObjectManager> m_objectListZero;
	vector<ObjectManager> m_objectListFront;

public:

	v2f GetPositionPlayer();

	void LoadLevel(LevelNumber &number);


	Level(LevelNumber& number);
	void Action(StateGame& state_game, LevelNumber& number);
	void Update(StateGame& state_game, LevelNumber& number);
	void Draw(StateGame& state_game, LevelNumber& number);
	~Level();
};

