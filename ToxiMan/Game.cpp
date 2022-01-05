// ▼
#pragma once
#include "Game.h"
#include "BlackTest.h"

Game::Game()
{
	is_first = true;
	is_not_first = false;
	is_balck = true;

	sf::Uint8 Alpha = 255;
	black.setSize(v2f(System::wnd.getSize().x, System::wnd.getSize().y));
	//black.setSize(v2f(500.f, 500.f));
	black.setFillColor(Color(0, 0, 0, Alpha));
	black.setOrigin(v2f(System::wnd.getSize().x/2.f, System::wnd.getSize().y /2.f));
	black.setPosition(System::cam.getCenter());

	//sf::Cursor curcor;
	//curcor.loadFromSystem(sf::Cursor::Cross);
	//System::wnd.setMouseCursor(curcor);

	m_main_menu = make_unique<Menu>(m_state_game, m_game_settings);

	m_GameStates = new GameStates(0);
	m_GameStates->Set(GameStates::GS::CHECK_MAP);
	m_GameStates->Updata();

	m_ptr_lvl = new Level(*m_GameStates, m_game_settings);

	m_ptr_thread = new sf::Thread(&Game::Thread, this);

	//m_ptr_play = new sf::Thread(&Game::Play, this);
	
	m_ptr_thread->launch();

	//m_ptr_play->wait();
	
	System::speedGame = 2;
}




void Game::Update()
{
	m_GameStates->Updata();

	switch (m_state_game)
	{
	case StateGame::ON_MAIN_MENU:
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

		m_ptr_lvl->Update(m_state_game, m_GameStates->GetGameLevel());

		m_ptr_lvl->check_lvl();

		break;
	case StateGame::ON_ARCITECT:
		System::resources.audio.music.menu_music.stop();
		System::cam.setViewport(sf::FloatRect(0.25f, 0.f, 1.f, 1.f));
		m_ptr_lvl->Update(m_state_game, m_GameStates->GetGameLevel());
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

	switch (m_state_game)
	{
	case StateGame::ON_MAIN_MENU:
		m_main_menu->Draw();
		break;
	case StateGame::ON_GAME:
		m_ptr_lvl->Draw(m_state_game, m_GameStates->GetGameLevel());
		break;
	case StateGame::ON_ARCITECT:
		m_ptr_lvl->Draw(m_state_game, m_GameStates->GetGameLevel());
		break;
	default:
		break;
	}

	my::S::wnd.draw(black);
	System::wnd.display();
}

void Game::Action()
{
	switch (m_state_game)
	{
	case StateGame::ON_MAIN_MENU:
		m_main_menu->Action();
		previous_state = StateGame::ON_MAIN_MENU;
		break;
	case StateGame::ON_GAME:
		m_ptr_lvl->Action(m_state_game, previous_state, m_GameStates->GetGameLevel());
		previous_state = StateGame::ON_GAME;
		break;
	case StateGame::ON_ARCITECT:
		m_ptr_lvl->Action(m_state_game, previous_state, m_GameStates->GetGameLevel());
		break;
	default:
		break;
	}

	System::CloseEvent();
}

void Game::Thread()
{
	System::wnd.setActive(false);

	while (System::wnd.isOpen())
	{
		System::SystemUpdate();
		UI::TextBoxEditHelper::Update();
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
	//m_ptr_thread->wait();
	delete m_ptr_lvl;
	delete m_ptr_thread;
}