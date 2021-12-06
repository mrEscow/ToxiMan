// ▼
#pragma once

//#include <thread>

#include "Menu.h"
#include "Level.h"

#include "Timer.h"

class Game
{
private:

	vector <  unique_ptr  <  Map  >  > m_VEC_MAPS;


	sf::Thread* m_ptr_thread;

	sf::Thread* m_ptr_play;

	//bool m_is_pause = false;

	bool m_is_next_level = true;


	StateGame m_state_game = StateGame::ON_MAIN_MENU;
	//StateGame m_state_game = StateGame::ON_ARCITECT;


	GameStates *m_GameStates;


	StateGame previous_state;

	GameSettings m_game_settings;

	unique_ptr<Menu> m_main_menu;


	//LevelNumber m_number = LevelNumber::zero;

	Map* m_map_ptr;
	Level *m_ptr_lvl;

	unique_ptr< Map > m_u_map;
	unique_ptr<Level> m_u_lvl;

	

public:

	Game();

	void Play();

	// поток 2
	void Thread();
	void Update();
	void Draw();


	void Action();


	void GreateLevel();

	void LoadNextLevel(UINT32 GameLevel);

	void NextLevel();


	~Game();
};