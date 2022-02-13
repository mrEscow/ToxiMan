// ▼
#pragma once

//#include <thread>

//#include "Menu.h"
//#include "Level.h"
#include "Timer.h"
#include "GameObject.h"
#include "Plane.h"
#include "Factory.h"

class AIController :public Controller {
	virtual void Action() override {
		for (auto& tank : vAllTanks) {
			v2f PlayerPos = dynamic_cast<Plane*>(vAllPlayers[0])->GetPosition();
			v2f tankPos = dynamic_cast<Tank*>(tank)->m_rectangle->getPosition();
			v2f result = tankPos - PlayerPos;
			while ((result.x > 1 || result.x < -1) && (result.y > 1 || result.y < -1))
			{
				result.x / 2;
				result.y / 2;
			}
			cout << "===========" << endl;
			cout << result.x << endl;
			cout << result.y << endl;

			dynamic_cast<Tank*>(tank)->SetDirection(result);
		}
		for (auto& plane : vAllTanks) {
			v2f PlayerPos = dynamic_cast<Plane*>(vAllPlayers[0])->GetPosition();
			v2f planePos = dynamic_cast<APlane*>(plane)->m_rectangle->getPosition();
			v2f result = planePos - PlayerPos;
			while ((result.x > 1 || result.x < -1) && (result.y > 1 || result.y < -1))
			{
				result.x / 2;
				result.y / 2;
			}
			dynamic_cast<Tank*>(plane)->SetDirection(result);
		}
	};
private:
};

using namespace my;
class SHR :public IGameObject {
	float m_time{ 1 };
	sf::Shader shader;
	sf::RectangleShape* pGUI = new sf::RectangleShape((v2f)System::wnd.getSize());
	Controller* pController = new GuiController;
public:
	SHR() {
		pGUI->setOrigin(v2f(pGUI->getSize().x/2, pGUI->getSize().y/2));
		pGUI->setFillColor(sf::Color::Red);
		//pGUI->setFillColor(sf::Color::Color(123, 123, 123, 123));

		shader.loadFromFile("vertex_shader.vert", "inet2.frag");
		vAllGuis.push_back(this);
	};

	void Update() {
		pGUI->setPosition(System::cam.getCenter());
	}

	virtual void Draw() override {

		m_time = m_time + System::time / 1000;

		shader.setUniform("time", m_time);
		shader.setUniform("pos", System::GetPosForShader(*pGUI));
		shader.setUniform("size", pGUI->getSize());

		System::wnd.draw(*pGUI, &shader);
		//System::wnd.draw(*pGUI);
	}
};

class Player: public DynamicObject {
	Controller* PC = new GuiController;
	Escow::Timer Timer;
public:
	Player(sf::RectangleShape* rectangle) : DynamicObject(rectangle) {
		vAllControllers.push_back(PC);
	};
	void Controller() {
		
		if (Timer.IsReset(0.5)) {
			if (PC->NUM1->ON()) {
				Timer.Reset();
				FactoryPlans factoryPlans;
				factoryPlans.CreateTrheeFighter();
				cout << "Cteate Tree Fighters" << endl;
			}
			if (PC->NUM2->ON()) {
				Timer.Reset();
				FactoryPlans factoryPlans;
				factoryPlans.CreateTwoInterceptors();
				cout << "Cteate Two Interceptors" << endl;
			}
			if (PC->NUM3->ON()) {
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
	static vector<IGameObject*> WhereAllTanks() {
		vector<IGameObject*> AllTanks;
		for (auto& gameObject : vGemeObjects) {
			Tank* p = dynamic_cast<Tank*>(gameObject);
			if (p != nullptr)
				AllTanks.push_back(gameObject);
		}
		return AllTanks;
	};
	static vector<IGameObject*> WhereAllBullets() {
		vector<IGameObject*> AllBullets;
		for (auto& gameObject : vGemeObjects) {
			Bullet* p = dynamic_cast<Bullet*>(gameObject);
			if (p != nullptr)
				AllBullets.push_back(gameObject);
		}
		return AllBullets;
	};
	static vector<APlane*> WhereAllPlans() {
		vector<APlane*> AllPlans;
		for (auto& gameObject : vAllPlans) {
			APlane* p = dynamic_cast<APlane*>(gameObject);
			if (p != nullptr)
				AllPlans.push_back(p);
		}
		return AllPlans;
	};
};

class Game
{
private:
	SHR sdrTest;

	BackGround* backGround;
	BigSquare* bigSquare;

	Plane* playerPlane;

	Creator* pCreator;

	Player* player = new Player(nullptr);

	//Controller* pController = new AIController;

	

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