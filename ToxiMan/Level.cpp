#include "Level.h"


void Level::LoadLevel(LevelNumber& number)
{
	System::resources.texture.LoadLevel_0();
	System::resources.texture.LoadForArhitect();
	m_firstPos = v2f(500, 1750);
	m_size_map = v2f(80, 30);
	m_objectListBeck = m_jsonSM.LoadVecObject("Save/file_beck.json", number);
	m_objectListZero = m_jsonSM.LoadVecObject("Save/file_zero.json", number);
	m_objectListFront = m_jsonSM.LoadVecObject("Save/file_front.json", number);

	m_jsonSM.DeleteJsonFile("file_beck.json", number);
	m_jsonSM.DeleteJsonFile("file_zero.json", number);
	m_jsonSM.DeleteJsonFile("file_front.json", number);
}
//----------------------------------------------------------------------
Level::Level(LevelNumber& number)
{
	m_ptr_number = &number;
	LoadLevel(number);
	
	m_ptr_player = new Player(m_firstPos, m_size_map);
	m_ptr_arhitevt = new Architect(m_objectListBeck, m_objectListZero, m_objectListFront, m_size_map);

	is_from_arhitetc = false;
	
}

void Level::Action(StateGame& state_game, LevelNumber& number)
{
	switch (state_game)
	{
	case StateGame::ON_MAIN_MENU:
		break;
	case StateGame::ON_GAME:
		m_ptr_player->Action(state_game);
		break;
	case StateGame::ON_ARCITECT:
		m_ptr_arhitevt->Action(state_game, is_from_arhitetc, m_jsonSM, number);
		break;
	default:
		break;
	}


}

void Level::Update(StateGame& state_game, LevelNumber& number)
{
	if (is_from_arhitetc) {

		m_objectListBeck = m_jsonSM.LoadVecObject("file_beck.json", number);
		m_objectListZero = m_jsonSM.LoadVecObject("file_zero.json", number);
		m_objectListFront = m_jsonSM.LoadVecObject("file_front.json", number);

		m_jsonSM.DeleteJsonFile("file_beck.json", number);
		m_jsonSM.DeleteJsonFile("file_zero.json", number);
		m_jsonSM.DeleteJsonFile("file_front.json", number);

		is_from_arhitetc = false;
	}

	for (auto& object : m_objectListBeck)
		object.Update("objectListBeck");
	for (auto& object : m_objectListZero)
		object.Update("objectListZero");

	switch (state_game)
	{
	case StateGame::ON_MAIN_MENU:
		break;
	case StateGame::ON_GAME:
		System::cam.reset(sf::FloatRect(0, 0, System::scr_w, System::scr_h));
		System::cam.setCenter(m_ptr_player->GetPosCam());
		System::wnd.setView(System::cam);
		m_ptr_player->Update();
		break;
	case StateGame::ON_ARCITECT:
		m_ptr_arhitevt->Update();
		break;
	default:
		break;
	}

	for (auto& object : m_objectListFront)
		object.Update("objectListFront");
}

void Level::Draw(StateGame& state_game,LevelNumber& number)
{
	for (auto &object : m_objectListBeck) {
		if (object.m_shape.getPosition().x < System::cam_p.x + (System::scr_w / 2) && object.m_shape.getPosition().x > System::cam_p.x - (System::scr_w / 2))
			if (object.m_shape.getPosition().y < System::cam_p.y + (System::scr_h / 2) && object.m_shape.getPosition().y > System::cam_p.y - (System::scr_h / 2))
			object.Draw();
	}

	for (auto &object : m_objectListZero) {
		if (object.m_shape.getPosition().x < System::cam_p.x + (System::scr_w / 2) && object.m_shape.getPosition().x > System::cam_p.x - (System::scr_w / 2))
			if (object.m_shape.getPosition().y < System::cam_p.y + (System::scr_h / 2) && object.m_shape.getPosition().y > System::cam_p.y - (System::scr_h / 2))
				object.Draw();
	}



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

	for (auto &object : m_objectListFront) {
		if (object.m_shape.getPosition().x < System::cam_p.x + (System::scr_w / 2) && object.m_shape.getPosition().x > System::cam_p.x - (System::scr_w / 2))
			if (object.m_shape.getPosition().y < System::cam_p.y + (System::scr_h / 2) && object.m_shape.getPosition().y > System::cam_p.y - (System::scr_h / 2))
			object.Draw();
	}	
}

v2f Level::GetPositionPlayer()
{
	return m_ptr_player->GetPosition();
}

Level::~Level()
{
	for (auto &obj : m_objectListBeck) {
		m_jsonSM.SaveObject(obj, "file_beck.json", *m_ptr_number);
	}
	for (auto &obj : m_objectListZero) {
		m_jsonSM.SaveObject(obj, "file_zero.json", *m_ptr_number);
	}
	for (auto &obj : m_objectListFront) {
		m_jsonSM.SaveObject(obj, "file_front.json", *m_ptr_number);
	}


	m_jsonSM.DeleteJsonFile("Save/file_beck.json", *m_ptr_number);
	m_jsonSM.DeleteJsonFile("Save/file_zero.json", *m_ptr_number);
	m_jsonSM.DeleteJsonFile("Save/file_front.json", *m_ptr_number);

	for (auto& obj : m_objectListBeck) {
		m_jsonSM.SaveObject(obj, "Save/file_beck.json", *m_ptr_number);
	}
	for (auto& obj : m_objectListZero) {
		m_jsonSM.SaveObject(obj, "Save/file_zero.json", *m_ptr_number);
	}
	for (auto& obj : m_objectListFront) {
		m_jsonSM.SaveObject(obj, "Save/file_front.json", *m_ptr_number);
	}

	delete m_ptr_player;
	delete m_ptr_arhitevt;
	//delete m_ptr_number;
	//delete m_ptr_jsonSM;
}
