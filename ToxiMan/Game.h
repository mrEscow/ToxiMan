// ▼
#pragma once



#include "Menu.h"
#include "Level.h"

#include "Timer.h"

class Game
{
private:

	vector <  unique_ptr  <  Map  >  > m_VEC_MAPS;


	sf::Thread* m_ptr_thread;

	//bool m_is_pause = false;

	bool m_is_next_level = true;


	StateGame m_state_game = StateGame::ON_GAME;
	//StateGame m_state_game = StateGame::ON_ARCITECT;

	StateGame previous_state;

	GameSettings m_game_settings;

	unique_ptr<Menu> m_main_menu;


	LevelNumber m_number = LevelNumber::two;

	Map* m_map_ptr;
	Level *m_ptr_lvl;

	unique_ptr< Map > m_u_map;
	unique_ptr<Level> m_u_lvl;

	Escow::Timer timer5sec{ 5.f };

public:

	Game();

	void Play();

	// поток 2
	void Thread();
	void Update();
	void Draw();


	void Action();


	void GreateLevel();

	void LoadNextLevel(LevelNumber number);

	void NextLevel();


	~Game();
};