#include "Level.h"

v2f Level::GetPositionPlayer()
{
	return m_ptr_player->GetPosition();
}
void Level::LoadLevel(LevelNumber& number)
{
	Json json;
	ifstream fin;

	switch (number)
	{
	case LevelNumber::zero:


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

		System::resources.texture.LoadLevel_0();
		System::resources.texture.LoadForArhitect();
		break;
	case LevelNumber::one:
		break;
	case LevelNumber::two:
		break;
	case LevelNumber::tree:
		break;
	case LevelNumber::four:
		break;
	case LevelNumber::five:
		break;
	case LevelNumber::six:
		break;
	case LevelNumber::seven:
		break;
	case LevelNumber::eight:
		break;
	case LevelNumber::nine:
		break;
	case LevelNumber::ten:
		break;
	default:
		break;
	}
}
//----------------------------------------------------------------------
Level::Level()
{


	m_ptr_player = new Player();
	m_ptr_arhitevt = new Architect();
	is_from_arhitetc = false;


}

void Level::Action(StateGame& state_game)
{
	switch (state_game)
	{
	case StateGame::ON_MAIN_MENU:
		break;
	case StateGame::ON_GAME:
		m_ptr_player->Action(state_game);
		break;
	case StateGame::ON_ARCITECT:
		m_ptr_arhitevt->Action(state_game, is_from_arhitetc);
		break;
	default:
		break;
	}


}

void Level::Update(StateGame& state_game)
{


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


	switch (state_game)
	{
	case StateGame::ON_MAIN_MENU:
		break;
	case StateGame::ON_GAME:
		m_ptr_player->Update();
		break;
	case StateGame::ON_ARCITECT:
		m_ptr_arhitevt->Update();
		break;
	default:
		break;
	}
	for (auto object : m_objectListBeck)
		object.Update("objectListBeck");
	for (auto object : m_objectListZero)
		object.Update("objectListZero");
	//m_player->Update();
	for (auto object : m_objectListFront)
		object.Update("objectListFront");
}

void Level::Draw(StateGame& state_game)
{
	for (auto object : m_objectListBeck)
		object.Draw();

	for (auto object : m_objectListZero)
		object.Draw();

	switch (state_game)
	{
	case StateGame::ON_MAIN_MENU:
		break;
	case StateGame::ON_GAME:
		m_ptr_player->Draw();
		break;
	case StateGame::ON_ARCITECT:
		m_ptr_player->Draw();
		m_ptr_arhitevt->Draw(state_game, m_ptr_player);
		break;
	default:
		break;
	}

	for (auto object : m_objectListFront)
	object.Draw();

}

Level::~Level()
{
	delete m_ptr_player;
	delete m_ptr_arhitevt;
}
