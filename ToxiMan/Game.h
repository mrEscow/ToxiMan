// ▼
#pragma once

#include "System.h"
#include "World.h"
#include "Player.h"
#include "GameStates.h"

class Game
{
private:


	bool m_is_pause = false;
	StateGame m_state_game = StateGame::ON_MAIN_MENU;

	Player* m_player;
	Shape m_background;
	Shape m_wall;
	Shape m_wall2;
	Shape m_wall3;
	Shape m_wall4;
	Shape m_wall5;
	b2Body* m_body_wall;
	Shape m_wall6;
	int x;
public:

	Game();
	void Play();
	void Update();
	void Draw();
	void Action();
	~Game();
};