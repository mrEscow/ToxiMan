// ▼
#pragma once
#include "Game.h"
#include "BlackTest.h"

Game::Game()
{
	sf::RectangleShape square = System::CreateShape(v2f(100, 100), v2f(100, 100));
	
	BigSquare* bigSquare = new BigSquare(&square);
	
	vGemeObjects.push_back(bigSquare);

	// test black team
	{
		is_first = true;
		is_not_first = false;
		is_balck = true;

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

	// Game
	GameSettings::ReadSettings();
	m_main_menu = make_unique<Menu>();

	m_GameStates = new GameStates(0);
	m_GameStates->Set(GameStates::GS::CHECK_MAP);
	m_GameStates->Updata();



	m_ptr_thread = new sf::Thread(&Game::Thread, this);

	//m_ptr_play = new sf::Thread(&Game::Play, this);
	
	m_ptr_thread->launch();

	//m_ptr_play->wait();
	
	System::speedGame = 2;
}




void Game::Update()
{
	m_GameStates->Updata();

	switch (g_StateGame)
	{
	case StateGame::ON_MENU:
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
		m_main_menu->Update();
		
		break;
	case StateGame::ON_GAME:
		System::resources.audio.music.menu_music.stop();
		System::cam.setViewport(sf::FloatRect(0.f, 0.f, 1.f, 1.f));
		break;
	default:
		break;
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

	switch (g_StateGame)
	{
	case StateGame::ON_MENU:
		m_main_menu->Draw();
		break;
	case StateGame::ON_GAME:
		break;
	default:
		break;
	}


	for (auto& object : vGemeObjects)
		object->Draw();
	my::S::wnd.draw(black);
	System::wnd.display();

}

void Game::Action()
{
	switch (g_StateGame)
	{
	case StateGame::ON_MENU:
		m_main_menu->Action();
		System::CloseEvent();
		break;
	case StateGame::ON_GAME:
		if (System::IsKeyPressed(Key::Escape))
		{
			g_StateGame = StateGame::ON_MENU;
		}
		break;
	default:
		break;
	}


}

void Game::Thread()
{
	System::wnd.setActive(false);

	while (System::wnd.isOpen())
	{
		System::SystemUpdate();

		World::world->Step(1 / System::fps * (System::speedGame + (World::world->GetBodyCount() / 1000)) , 8, 3);
		Update();

		//Mutex.lock();
		Draw();
		//Mutex.unlock();
	}
	//sf::sleep(sf::milliseconds(1000));
}

void Game::NextLevel()
{
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