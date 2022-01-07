// ▼
#pragma once

//#include <thread>

#include "Menu.h"
#include "Level.h"
#include "Timer.h"


using namespace my;



class Game
{
private:

	sf::Thread* m_ptr_thread;

	sf::Thread* m_ptr_play;

	//bool m_is_pause = false;


	StateGame m_state_game = StateGame::ON_MAIN_MENU;
	//StateGame m_state_game = StateGame::ON_ARCITECT;


	GameStates *m_GameStates;

	StateGame previous_state;

	unique_ptr<Menu> m_main_menu;

	// black team test
	Shape black;
	bool is_first;
	bool is_not_first;
	sf::Uint8 Alpha;
	Escow::Timer TimerAlha;
	bool is_balck;


public:

	Game();

	void Play();

	// поток 2
	void Thread();

	void Action();
	void Update();
	void Draw();

	void GreateLevel();

	void NextLevel();

	~Game();
};