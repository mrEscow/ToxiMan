// ▼
#pragma once
#include "Game.h"


Game::Game()
{
	//sf::Cursor curcor;
	//curcor.loadFromSystem(sf::Cursor::Cross);
	//System::wnd.setMouseCursor(curcor);

	System::speedGame = 2;

	m_main_menu = make_unique<Menu>(m_state_game, m_game_settings);

	m_ptr_lvl = new Level(m_number, m_game_settings);

	m_ptr_thread = new sf::Thread(&Game::Thread, this);
	m_ptr_thread->launch();
}

void Game::Update()
{
	switch (m_state_game)
	{
	case StateGame::ON_MAIN_MENU:
		System::cam.setViewport(sf::FloatRect(0.f, 0.f, 1.f, 1.f));
		m_main_menu->Update();
		break;
	case StateGame::ON_GAME:
		//System::resources.audio.music.menu_music.stop();
		System::cam.setViewport(sf::FloatRect(0.f, 0.f, 1.f, 1.f));
		m_ptr_lvl->Update(m_state_game,m_number);
		break;
	case StateGame::ON_ARCITECT:
		//System::resources.audio.music.menu_music.stop();
		System::cam.setViewport(sf::FloatRect(0.25f, 0.f, 1.f, 1.f));
		m_ptr_lvl->Update(m_state_game, m_number);
		break;
	default:
		break;
	}
}

void Game::Draw()
{
	System::wnd.clear();

	switch (m_state_game)
	{
	case StateGame::ON_MAIN_MENU:
		m_main_menu->Draw();
		break;
	case StateGame::ON_GAME:
		m_ptr_lvl->Draw(m_state_game, m_number);
		break;
	case StateGame::ON_ARCITECT:
		m_ptr_lvl->Draw(m_state_game, m_number);
		break;
	default:
		break;
	}

	System::wnd.display();
}

void Game::Action()
{
	switch (m_state_game)
	{
	case StateGame::ON_MAIN_MENU:
		m_main_menu->Action();
		break;
	case StateGame::ON_GAME:
		m_ptr_lvl->Action(m_state_game, m_number);
		break;
	case StateGame::ON_ARCITECT:
		m_ptr_lvl->Action(m_state_game, m_number);
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

		World::world->Step(1 / System::fps * (System::speedGame + (World::world->GetBodyCount() / 1000)) , 8, 3);

		Update();

		Draw();
	}

	sf::sleep(sf::milliseconds(1000));
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
	delete m_ptr_lvl;
	delete m_ptr_thread;
}