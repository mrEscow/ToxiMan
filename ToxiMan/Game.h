// ▼
#pragma once

#include "System.h"
#include "World.h"

#include "Player.h"
#include "GameStates.h"
#include "Architect.h"

#include "Level.h"
#include "JsonSaveMenager.h"

class Game
{
private:

	bool m_is_pause = false;

	StateGame m_state_game = StateGame::ON_ARCITECT;

	Level m_lvl;

	LevelNumber m_number = LevelNumber::zero;

	JsonSaveMenager m_jsonSM;


public:

	Game();
	void Play();
	void Update();
	void Draw();
	void Action();
	~Game();
};