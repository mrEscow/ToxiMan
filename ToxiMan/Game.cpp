﻿// ▼
#pragma once
#include "Game.h"


Game::Game()
{
	m_lvl.LoadLevel(m_number);

}

void Game::Update()
{
	switch (m_state_game)
	{
	case StateGame::ON_MAIN_MENU:
		break;
	case StateGame::ON_GAME:
		System::cam.reset(sf::FloatRect(0, 0, System::scr_w, System::scr_h));
		System::cam.setCenter(m_lvl.GetPositionPlayer());
		System::wnd.setView(System::cam);
		m_lvl.Update(m_state_game);
		break;
	case StateGame::ON_ARCITECT:
		m_lvl.Update(m_state_game);
		break;
	default:
		break;
	}


}

void Game::Draw()
{
	switch (m_state_game)
	{
	case StateGame::ON_MAIN_MENU:
		break;
	case StateGame::ON_GAME:
		m_lvl.Draw(m_state_game);
		break;
	case StateGame::ON_ARCITECT:
		m_lvl.Draw(m_state_game);
		break;
	default:
		break;
	}
}

void Game::Action()
{
	switch (m_state_game)
	{
	case StateGame::ON_MAIN_MENU:
		break;
	case StateGame::ON_GAME:
		m_lvl.Action(m_state_game);
		break;
	case StateGame::ON_ARCITECT:
		m_lvl.Action(m_state_game);
		break;
	default:
		break;
	}

	System::CloseEvent();
}

void Game::Play()
{
	while (System::wnd.isOpen())
	{
		System::SystemUpdate();
		if (m_is_pause) System::time = 0.f;

		Update();

		while (System::wnd.pollEvent(System::event))
		{

			Action();
		}

		World::world->Step(1 / (float)System::frameLimit * 2, 8, 3);

		System::wnd.clear();
		Draw();
		System::wnd.display();
	}
}

Game::~Game()
{

}