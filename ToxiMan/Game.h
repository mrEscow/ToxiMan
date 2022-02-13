// ▼
#pragma once

//#include <thread>

//#include "Menu.h"
//#include "Level.h"
#include "Timer.h"
#include "GameObject.h"
#include "Plane.h"
#include "Factory.h"
#include "NewObject.h"

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

class UTILITA {
public:
	//static Player* WherePlayer() {
	//	for (auto& gameObject : vGemeObjects) {
	//		Player* p = dynamic_cast<Player*>(gameObject);
	//		if (p != nullptr)
	//			return p;
	//	}
	//	return nullptr;
	//};
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

using namespace my;
class SHR :public IGameObject {
	sf::Vector2f V2positions[1000];
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
		vAllSHR.push_back(this);
	};

	void Update() {
		pGUI->setPosition(System::cam.getCenter());
	}

	virtual void Draw() override {

		m_time = m_time + System::time / 1000;

		for (int i = 0; i < 1000; ++i) {
			V2positions[i] = v2f(0, 0);
		}

		for (int i = 0; i < UTILITA::WhereAllPlans().size() /* && i < 1000*/; i++)
		{
			

			APlane* p = UTILITA::WhereAllPlans()[i];

			if (p != nullptr) {

				V2positions[i] = v2f(
					(p->GetPosition() -
						System::cam.getCenter() +
						v2f(System::wnd.getSize().x / 2, System::wnd.getSize().y / 2)).x,
					(p->GetPosition() -
						System::cam.getCenter() -
						v2f(System::wnd.getSize().x / 2, System::wnd.getSize().y / 2)).y
				);



				//cout << "********" << endl;
				//cout << (
				//	p->GetPosition() -
				//	System::cam.getCenter() +
				//	v2f(System::wnd.getSize().x / 2, (System::wnd.getSize().y / 2))
				//	).x << endl;
				//cout << (
				//	p->GetPosition() - 
				//	System::cam.getCenter() +
				//	v2f(System::wnd.getSize().x / 2, (System::wnd.getSize().y / 2))
				//	).y << endl;
			}
				
		}



		shader.setUniformArray("V2positions", V2positions, 1000);
		// x y z
		//sf::Vector3f(1, 1, 1);
		//shader.setUniform("V2positions", V2positions);
		shader.setUniform("time", m_time);
		shader.setUniform("pos", System::GetPosForShader(*pGUI));
		shader.setUniform("size", pGUI->getSize());

		System::wnd.draw(*pGUI, &shader);
		//System::wnd.draw(*pGUI);
	}
};

class Player {
	Controller* PC = new GuiController;
	Controller* PC2 = new PlayerController;
	Escow::Timer Timer;

	NewObject transport_;
public:
	Player(const NewObject& transport) {

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

		if (PC2->LKM->ON()) {
			fire();
		}

	}


private:
	IDynamicObject* slot_1;
	void fire() {
		dynamic_cast<IGun*>(slot_1)->fire(System::cur_p, 100);
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

	NewObject monster;
	Player* player = new Player(monster);

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

	void CreateMegaMonster();

	void NextLevel();

	~Game();
};