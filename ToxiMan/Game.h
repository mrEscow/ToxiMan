// ▼
#pragma once

//#include <thread>

//#include "Menu.h"
//#include "Level.h"
#include "Timer.h"
#include "GameObject.h"
#include "Plane.h"



using namespace my;



class Game
{
private:

	vector<IGameObject*> vGemeObjects;
	BigSquare* bigSquare;
	Plane* plane;

	sf::Thread* m_ptr_thread;

	sf::Thread* m_ptr_play;

	//bool m_is_pause = false;

	//GameStates *m_GameStates;

	//unique_ptr<Menu> m_main_menu;

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