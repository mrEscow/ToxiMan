// ▼
#pragma once
#include "Game.h"


Game::Game()
{
	// потом перенести в левл
	m_wall = System::CreateShape(v2f(0, 60 + 120 + 120 + 120 + 20), v2f(1920, 20),Color::White);
	World::SetStaticBox(m_wall);
	m_wall2 = System::CreateShape(v2f(-1000, -(60 + 120 + 120)), v2f(1920, 20), Color::White);;
	World::SetStaticBox(m_wall2);
	m_wall3 = System::CreateShape(v2f(540, 0), v2f(20,1080/2), Color::White);;
	World::SetStaticBox(m_wall3);
	m_wall4 = System::CreateShape(v2f(-540, 0), v2f(20,1080/2), Color::White);;
	World::SetStaticBox(m_wall4);

	m_wall5 = System::CreateShape(v2f(200, 0), v2f(200, 100), 5, Color::Blue, Color::Black);
	x = -1;
	m_body_wall = World::CreateBodyBox(m_wall5);
	//m_body_wall->SetType(b2BodyType::b2_dynamicBody);
	m_body_wall->SetType(b2BodyType::b2_kinematicBody);
	m_body_wall->SetGravityScale(0);
	m_body_wall->SetFixedRotation(true);

	m_wall6 = System::CreateShape(v2f(-200, 100), v2f(200, 100), 5, Color::Blue, Color::Black);
	World::SetStaticBox(m_wall6);

	//---GAME-----------------------------------
	System::resources.texture.LoadLevel_0();
	m_player = new Player();

	m_background = System::CreateShape(v2f(0, 0), v2f(System::scr_w, System::scr_h), System::resources.texture.background);
	//---ARCHITECT------------------------------
	System::resources.texture.LoadForArhitect();
	m_arhitevt = new Architect();
}

void Game::Update()
{
	//cout << m_body_wall->GetPosition().x << endl;
	if (m_body_wall->GetPosition().x > 5 )
		x = -1;
	if (m_body_wall->GetPosition().x < -5 )
		x = 1;

	m_body_wall->ApplyLinearImpulseToCenter(b2Vec2(x, 0), true);

	m_wall5.setPosition(m_body_wall->GetPosition().x * SCALE, m_body_wall->GetPosition().y * SCALE);
	m_wall5.setRotation(m_body_wall->GetAngle() * DEG);

	switch (m_state_game)
	{
	case StateGame::ON_MAIN_MENU:
		break;
	case StateGame::ON_GAME:
		System::cam.reset(sf::FloatRect(0, 0, System::scr_w, System::scr_h));
		System::cam.setCenter(m_player->GetPosition());
		System::wnd.setView(System::cam);

		m_player->Update();
		break;
	case StateGame::ON_ARCITECT:
		//System::cam.setCenter(m_player->GetPosition());
		//System::wnd.setView(System::cam);
		m_arhitevt->Update();
		break;
	default:
		break;
	}


}

void Game::Draw()
{
	System::wnd.draw(m_background);
	// прям вектор)
	System::wnd.draw(m_wall);
	System::wnd.draw(m_wall2);
	System::wnd.draw(m_wall3);
	System::wnd.draw(m_wall4);
	System::wnd.draw(m_wall5);
	System::wnd.draw(m_wall6);
	m_player->Draw();
	switch (m_state_game)
	{
	case StateGame::ON_MAIN_MENU:
		break;
	case StateGame::ON_GAME:
		m_player->Draw();
		m_arhitevt->Draw(m_state_game);
		break;
	case StateGame::ON_ARCITECT:
		m_arhitevt->Draw(m_state_game);
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
		m_player->Action(m_state_game);
		break;
	case StateGame::ON_ARCITECT:
		m_arhitevt->Action(m_state_game);
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
	delete m_player;
	delete m_arhitevt;
}