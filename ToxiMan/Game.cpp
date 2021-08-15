// ▼
#pragma once
#include "Game.h"


Game::Game()
{
	

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
	System::wnd.clear();

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

}

void Game::Play()
{

	while (System::wnd.isOpen())
	{

		System::SystemUpdate();
		//if (m_is_pause) System::time = 0.f;
		Update();

		while (System::wnd.pollEvent(System::event)) Action();

		World::world->Step(1 / (float)System::frameLimit * 2, 8, 3);
		Draw();
	}
}

Game::~Game()
{
	delete m_ptr_lvl;
	delete m_ptr_thread;
}