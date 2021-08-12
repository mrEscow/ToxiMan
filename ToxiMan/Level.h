#pragma once

#include "System.h"
#include "World.h"

#include "Player.h"
#include "GameStates.h"
#include "Architect.h"

class Level
{
private:

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
	void Action(StateGame& state_game);
	void Update(StateGame& state_game);
	void Draw(StateGame& state_game);
	~Level();
};

