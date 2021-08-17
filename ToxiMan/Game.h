// ▼
#pragma once

#include "System.h"
#include "World.h"
#include "Level.h"


class Game
{
private:



	sf::Thread* m_ptr_thread;

	//bool m_is_pause = false;

	StateGame m_state_game = StateGame::ON_GAME;

	LevelNumber m_number = LevelNumber::zero;

	Level *m_ptr_lvl;

public:

	Game();
	void Play();
	void Update();
	void Draw();
	void Action();
	void Thread();
	~Game();
};