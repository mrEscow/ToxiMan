// ▼
#pragma once

//#include <thread>

//#include "Menu.h"
//#include "Level.h"
#include "Timer.h"
#include "GameObject.h"
#include "Plane.h"
#include "Factory.h"



using namespace my;

class Player: public DynamicObject {
	GuiController PC;
	Escow::Timer Timer;
public:
	Player(sf::RectangleShape* rectangle) : DynamicObject(rectangle) {};
	void Controller() {
		PC.Action();
		if (Timer.IsReset(0.5)) {
			if (PC.NUM1->ON()) {
				Timer.Reset();
				FactoryPlans factoryPlans;
				factoryPlans.CreateTrheeFighter();
				cout << "Cteate Tree Fighters" << endl;
			}
			if (PC.NUM2->ON()) {
				Timer.Reset();
				FactoryPlans factoryPlans;
				factoryPlans.CreateTwoInterceptors();
				cout << "Cteate Two Interceptors" << endl;
			}
			if (PC.NUM3->ON()) {
				Timer.Reset();
				FactoryPlans factoryPlans;
				factoryPlans.CreateOneBomber();
				cout << "Cteate One Bomber" << endl;
			}
		}
	}
};

class UTILITA {
public:
	static Player* WherePlayer() {
		for (auto& gameObject : vGemeObjects) {
			Player* p = dynamic_cast<Player*>(gameObject);
			if (p != nullptr)
				return p;
		}
		return nullptr;
	};
	static Plane* WherePlane() {
		for (auto& gameObject : vGemeObjects) {
			Plane* p = dynamic_cast<Plane*>(gameObject);
			if (p != nullptr)
				return p;
		}
		return nullptr;
	};
	static vector<IGameObject*> AllWhereTanks() {
		vector<IGameObject*> AllTanks;
		for (auto& gameObject : vGemeObjects) {
			Tank* p = dynamic_cast<Tank*>(gameObject);
			if (p != nullptr)
				AllTanks.push_back(gameObject);
		}
		return AllTanks;
	};
	static vector<IGameObject*> AllWhereBullets() {
		vector<IGameObject*> AllBullets;
		for (auto& gameObject : vGemeObjects) {
			Bullet* p = dynamic_cast<Bullet*>(gameObject);
			if (p != nullptr)
				AllBullets.push_back(gameObject);
		}
		return AllBullets;
	};
};

class Game
{
private:


	BackGround* backGround;
	BigSquare* bigSquare;
	Plane* plane;

	Creator* pCreator;

	Player* player = new Player(nullptr);

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
	bool is_black;


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