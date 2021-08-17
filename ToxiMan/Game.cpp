// ▼
#pragma once
#include "Game.h"


Game::Game()
{
	sf::Cursor curcor;
	curcor.loadFromSystem(sf::Cursor::Cross);
	System::wnd.setMouseCursor(curcor);

	m_ptr_lvl = new Level(m_number);

	m_ptr_thread = new sf::Thread(&Game::Thread, this);
	m_ptr_thread->launch();
}

void Game::Update()
{
	switch (m_state_game)
	{
	case StateGame::ON_MAIN_MENU:
		break;
	case StateGame::ON_GAME:
		m_ptr_lvl->Update(m_state_game,m_number);
		break;
	case StateGame::ON_ARCITECT:
		m_ptr_lvl->Update(m_state_game, m_number);
		break;
	default:
		break;
	}
}

void Game::Draw()
{
	//System::wnd.clear();



	switch (m_state_game)
	{
	case StateGame::ON_MAIN_MENU:
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

		World::world->Step(1 / (float)System::frameLimit * 2, 8, 3);

		Update();

		Draw();
	}
}

void Game::Play()
{
	System::wnd.setActive(false);

	while (System::wnd.isOpen())
		while (System::wnd.pollEvent(System::event)) Action();	
}

Game::~Game()
{
	delete m_ptr_lvl;
	delete m_ptr_thread;
}