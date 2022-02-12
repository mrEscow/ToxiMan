﻿// ▼
#pragma once
#include "Game.h"
#include "BlackTest.h"

Game::Game()
{

	//Static
	sf::RectangleShape* rectangle3 = new sf::RectangleShape(v2f(1000, 1500));
	rectangle3->setFillColor(Color::Cyan);
	backGround = new BackGround(rectangle3);
	vGemeObjects.push_back(backGround);

	vStaticObjects.push_back(backGround);

	//Dynamic
	sf::RectangleShape* rectangle = new sf::RectangleShape(v2f(100,50));
	rectangle->setFillColor(Color::Green);
	plane = new Plane(rectangle);
	vGemeObjects.push_back(plane);

	vDynamicObjects.push_back(plane);

	sf::RectangleShape* Square = new sf::RectangleShape(v2f(500, 500));
	Square->setFillColor(Color::Magenta);
	bigSquare = new BigSquare(Square);
	vGemeObjects.push_back(bigSquare);

	vDynamicObjects.push_back(bigSquare);

	//FactoryMetod
	pCreator = new CreateDynamicTank;

	for (size_t i = 0; i < 5; i++)
	{
		pCreator->CreateGameObject();
	}


	vGemeObjectsV01.push_back(pair<uint32, vector<IGameObject*>>(Grounds, vAllGrounds));
	vGemeObjectsV01.push_back(pair<uint32, vector<IGameObject*>>(Houses, vAllHouses));
	vGemeObjectsV01.push_back(pair<uint32, vector<IGameObject*>>(Tanks, vAllTanks));
	vGemeObjectsV01.push_back(pair<uint32, vector<IGameObject*>>(Players, vAllPlayers));
	vGemeObjectsV01.push_back(pair<uint32, vector<IGameObject*>>(Tanks, vAllTanks));
	vGemeObjectsV01.push_back(pair<uint32, vector<IGameObject*>>(Plans, vAllPlans));
	vGemeObjectsV01.push_back(pair<uint32, vector<IGameObject*>>(Guis, vAllGuis));

	FactoryPlans factoryPlans;
	factoryPlans.CreateTrheeFighter();


	// test black team
	{
		is_first = true;
		is_not_first = false;
		is_black = true;

		sf::Uint8 Alpha = 255;
		black.setSize(v2f(
			static_cast<float>(System::wnd.getSize().x),
			static_cast<float>(System::wnd.getSize().y))
		);
		//black.setSize(v2f(500.f, 500.f));
		black.setFillColor(Color(0, 0, 0, Alpha));
		black.setOrigin(v2f(System::wnd.getSize().x / 2.f, System::wnd.getSize().y / 2.f));
		black.setPosition(System::cam.getCenter());
	}

	// test cursor
	{
		//sf::Cursor curcor;
		//curcor.loadFromSystem(sf::Cursor::Cross);
		//System::wnd.setMouseCursor(curcor);
	}

	//// Game
	//GameSettings::ReadSettings();
	////m_main_menu = make_unique<Menu>();

	//m_GameStates = new GameStates(0);
	//m_GameStates->Set(GameStates::GS::CHECK_MAP);
	//m_GameStates->Updata();



	m_ptr_thread = new sf::Thread(&Game::Thread, this);

	//m_ptr_play = new sf::Thread(&Game::Play, this);
	
	m_ptr_thread->launch();

	//m_ptr_play->wait();
	
	System::speedGame = 2;
}




void Game::Update()
{
	//m_GameStates->Updata();

	//switch (g_StateGame)
	{
		//case StateGame::ON_MENU:
		System::cam.setViewport(sf::FloatRect(0.f, 0.f, 1.f, 1.f));
		System::cam.reset(
			sf::FloatRect(
				0,
				0,
				static_cast<float>(System::scr_w),
				static_cast<float>(System::scr_h)
			)
		);
		System::cam.setCenter(0, 0);
		System::wnd.setView(System::cam);
		System::zoom /= System::zoom;
		System::zoom = 1;
		//m_main_menu->Update();

	//	break;
	//case StateGame::ON_GAME:
	//	System::resources.audio.music.menu_music.stop();
	//	System::cam.setViewport(sf::FloatRect(0.f, 0.f, 1.f, 1.f));
	//	break;
	//default:
	//	break;
	//}


		//Cool faund
		//for (size_t i = 0; i < vDynamicObjects.size(); i++)
		//{
		//	Tank* p = dynamic_cast<Tank*>(vDynamicObjects[i]);
		//	if (p != nullptr)
		//	{
		//		p->SetDirection(plane->GetPosition());
		//	}
		//}

		for (auto& obj : vDynamicObjects) {
			Tank* p = dynamic_cast<Tank*>(obj);
			if (p != nullptr) {
				int x{ 0 }, y{ 0 };
				//x = plane->GetPosition().x - p->m_rectangle->getPosition().x;
				//cout << "============" << endl;
				//cout << p->m_rectangle->getPosition().x << endl;
				//cout << x << endl;
				obj->SetDirection(v2f(plane->GetPosition().x/19200, plane->GetPosition().y / 10800));
				obj->Move();
			}
			else
			{
				if(obj)
					obj->Move();
			}
				
		}



		plane->Update();
	}
}



void Game::Draw()
{
	System::wnd.clear();

	if (is_first)
	{
		if (TimerAlha.IsTick(0.2f / 255.0f))
			Alpha--;
		black.setFillColor(Color(0, 0, 0, Alpha));
		if (Alpha == 0)
		{
			is_first = false;
			Alpha = 255;
		}
	}

	//if (is_balck && !is_first) {
	//	if (is_not_first) {
	//		if (TimerAlha.IsTick(0.3f / 255.0f))
	//			Alpha++;
	//	}
	//	else {
	//		if (TimerAlha.IsTick(0.3f / 255.0f))
	//			Alpha--;
	//	}

	//	black.setFillColor(Color(0, 0, 0, Alpha));
	//	if (Alpha == 255)
	//		is_not_first = false;
	//	if (Alpha == 0)
	//	{
	//		is_balck = false;
	//		is_not_first = false;
	//	}
	//}

	//switch (g_StateGame)
	//{
	//case StateGame::ON_MENU:
	//	m_main_menu->Draw();
	//	break;
	//case StateGame::ON_GAME:
	//	break;
	//default:
	//	break;
	//}

	//for (auto& object : vGemeObjects)
	//	if(object)
	//		object->Draw();

	for (auto& [key, objects] : vGemeObjectsV01) {
		if (key == Grounds)
			objects = vAllGrounds;
		if (key == Houses)
			objects = vAllHouses;
		if (key == Tanks)
			objects = vAllTanks;
		if (key == Plans)
			objects = vAllPlans;
		if (key == Players)
			objects = vAllPlayers;
		if(key == Plans)
			objects = vAllPlans;

		for (auto& obj : objects)
			obj->Draw();
	}

	[&]() { // DELETER OBJECTS

		my::Alg::for_each(vAllPlans.begin(), vAllPlans.end(), [](IGameObject* obj) {
			if (dynamic_cast<APlane*>(obj)->isDaed())
				vAllPlans.erase(vAllPlans.begin());
			});

	};


	my::S::wnd.draw(black);
	System::wnd.display();

}

void Game::Action()
{
	//switch (g_StateGame)
	{
	//case StateGame::ON_MENU:
		//m_main_menu->Action();
		System::CloseEvent();
		//break;
	//case StateGame::ON_GAME:
		if (System::IsKeyPressed(Key::Escape))
		{
			//g_StateGame = StateGame::ON_MENU;
		}
		//break;
	//default:
		//break;
	}
	for (auto& Controller : vAllControllers)
		Controller->Action();

	player->Controller();
	plane->action();
}
// public metods
void Game::Thread()
{
	System::wnd.setActive(false);

	while (System::wnd.isOpen())
	{
		System::SystemUpdate();
		Update();
		Draw();
	}

}
void Game::Play()
{
	System::wnd.setActive(false);

	while (System::wnd.isOpen())	
		while (System::wnd.pollEvent(System::event)) Action();	

	sf::sleep(sf::milliseconds(1000));
}

Game::~Game()
{
	delete m_ptr_thread;
}