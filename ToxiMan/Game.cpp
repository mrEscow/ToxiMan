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


	//---Vector from file----------------------
	
	Json json;
	ifstream fin;

	fin.open("file_beck.json");
	if (!fin.is_open()) {
		cout << "error: file_beck.json not open!" << endl;
	}
	else {
		cout << "file_beck.json open!" << endl;
		//char nil = '\0';
		string line;
		ObjectManager object;
		while (std::getline(fin, line))
		{
			cout << "Line: " << line << endl;
			json = Json::parse(line);
			cout << "Json: " << json << endl;

			object.CreateTextureBoxBeck(json);
			m_objectListBeck.push_back(object);
		}
	
	}
	fin.close();
	fin.open("file_zero.json");
	if (!fin.is_open()) {
		cout << "error: file_zero.json not open!" << endl;
	}
	else {
		cout << "file_zero.json open!" << endl;
		//char nil = '\0';
		string line;
		ObjectManager object;
		while (std::getline(fin, line))
		{
			cout << "Line: " << line << endl;
			json = Json::parse(line);
			cout << "Json: " << json << endl;

			object.CreateStaticBox(json);
			m_objectListZero.push_back(object);
		}

	}
	fin.close();
	fin.open("file_front.json");
	if (!fin.is_open()) {
		cout << "error: file_front.json not open!" << endl;
	}
	else {
		cout << "file_front.json open!" << endl;
		//char nil = '\0';
		string line;
		ObjectManager object;
		while (std::getline(fin, line))
		{
			cout << "Line: " << line << endl;
			json = Json::parse(line);
			cout << "Json: " << json << endl;

			object.CreateTextureBoxFront(json);
			m_objectListFront.push_back(object);
		}

	}
	fin.close();

	if (remove("file_beck.json") != 0)             // удаление файла 
		cout << "error file_beck.json not delete" << endl;
	else
		cout << "file_beck.json delete" << endl;

	if (remove("file_zero.json") != 0)             // удаление файла 
		cout << "error file_zero.json not delete" << endl;
	else
		cout << "file_zero.json delete" << endl;

	if (remove("file_front.json") != 0)             // удаление файла 
		cout << "error file_front.json not delete" << endl;
	else
		cout << "file_front.json delete" << endl;
	
	//---GAME-----------------------------------
	System::resources.texture.LoadLevel_0();
	m_background = System::CreateShape(v2f(0, 0), v2f(System::scr_w, System::scr_h), System::resources.texture.background);
	m_player = new Player();


	//---ARCHITECT------------------------------
	System::resources.texture.LoadForArhitect();
	m_arhitevt = new Architect(m_objectListBeck,m_objectListZero,m_objectListFront);
	is_from_arhitetc = false;
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
		for (auto object : m_objectListBeck)
			object.Update("objectListBeck");
		for (auto object : m_objectListZero)
			object.Update("objectListZero");
		m_player->Update();
		for (auto object : m_objectListFront)
			object.Update("objectListFront");
		break;
	case StateGame::ON_ARCITECT:
		//System::cam.setCenter(m_player->GetPosition());
		//System::wnd.setView(System::cam);
		m_arhitevt->Update();
		break;
	default:
		break;
	}

	if (is_from_arhitetc) {
		Json json;
		ifstream fin;

		fin.open("file_beck.json");
		if (!fin.is_open()) {
			cout << "error: file_beck.json not open!" << endl;
		}
		else {
			cout << "file_beck.json open!" << endl;
			//char nil = '\0';
			string line;
			ObjectManager object;
			while (std::getline(fin, line))
			{
				cout << "Line: " << line << endl;
				json = Json::parse(line);
				cout << "Json: " << json << endl;

				object.CreateTextureBoxBeck(json);
				m_objectListBeck.push_back(object);
			}

		}
		fin.close();

		fin.open("file_zero.json");
		if (!fin.is_open()) {
			cout << "error: file_zero.json not open!" << endl;
		}
		else {
			cout << "file_zero.json open!" << endl;
			//char nil = '\0';
			string line;
			ObjectManager object;
			while (std::getline(fin, line))
			{
				cout << "Line: " << line << endl;
				json = Json::parse(line);
				cout << "Json: " << json << endl;

				object.CreateStaticBox(json);
				m_objectListZero.push_back(object);
			}

		}
		fin.close();

		fin.open("file_front.json");
		if (!fin.is_open()) {
			cout << "error: file_front.json not open!" << endl;
		}
		else {
			cout << "file_front.json open!" << endl;
			//char nil = '\0';
			string line;
			ObjectManager object;
			while (std::getline(fin, line))
			{
				cout << "Line: " << line << endl;
				json = Json::parse(line);
				cout << "Json: " << json << endl;

				object.CreateTextureBoxFront(json);
				m_objectListFront.push_back(object);
			}

		}
		fin.close();

		//if (remove("file_beck.json") != 0)             // удаление файла 
		//	cout << "error file_beck.json not delete" << endl;
		//else
		//	cout << "file_beck.json delete" << endl;

		//if (remove("file_zero.json") != 0)             // удаление файла 
		//	cout << "error file_zero.json not delete" << endl;
		//else
		//	cout << "file_zero.json delete" << endl;

		//if (remove("file_front.json") != 0)             // удаление файла 
		//	cout << "error file_front.json not delete" << endl;
		//else
		//	cout << "file_front.json delete" << endl;

		is_from_arhitetc = false;
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
		for (auto object : m_objectListBeck)
			object.Draw();
		for (auto object : m_objectListZero)
			object.Draw();
		m_player->Draw();
		for (auto object : m_objectListFront)
			object.Draw();

		//m_arhitevt->Draw(m_state_game);
		break;
	case StateGame::ON_ARCITECT:
		m_arhitevt->Draw(m_state_game,m_player);
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
		//for (auto object : m_objectListBeck)
		//	object.Action();
		//for (auto object : m_objectListZero)
		//	object.Action();
		m_player->Action(m_state_game);
		//for (auto object : m_objectListFront)
		//	object.Action();
		break;
	case StateGame::ON_ARCITECT:
		m_arhitevt->Action(m_state_game, is_from_arhitetc);
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