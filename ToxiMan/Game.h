﻿// ▼
#pragma once

#include "System.h"
#include "World.h"
#include "Player.h"
#include "GameStates.h"
#include "Architect.h"

class Game
{
private:


	bool m_is_pause = false;
	StateGame m_state_game = StateGame::ON_GAME;

	Player* m_player;
	Architect* m_arhitevt;

	Shape m_background;
	Shape m_wall;
	Shape m_wall2;
	Shape m_wall3;
	Shape m_wall4;
	Shape m_wall5;
	b2Body* m_body_wall;
	Shape m_wall6;
	int x;
	
	vector<ObjectManager> m_objectListBeck;
	vector<ObjectManager> m_objectListZero;
	vector<ObjectManager> m_objectListFront;

	bool is_from_arhitetc;

public:

	Game();
	void Play();
	void Update();
	void Draw();
	void Action();
	~Game();
};