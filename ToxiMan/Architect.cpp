#include "Architect.h"

Architect::Architect(vector<ObjectManager>&objectListBack, vector<ObjectManager>&objectListZero, vector<ObjectManager>&objectListFront, v2f size_map, GameSettings& game_settings)
{
	m_ptr_objectListBack = &objectListBack;
	m_ptr_objectListZero = &objectListZero;
	m_ptr_objectListFront = &objectListFront;

	m_size_x = 64;
	m_size_y = 64;

	m_mouse = System::CreateShape(System::cur_p, v2f(m_size_x, m_size_y), System::resources.texture.arhitectMouse);
	m_mouse.setOutlineColor(Color::Red);
	m_mouse.setOutlineThickness(-5);

	m_zoom = 1.f;

	for (size_t i = 0; i < size_map.x; i++)
	{
		for (size_t j = 0; j < size_map.y; j++) {
			
			m_cell = System::CreateShape(v2f(i * m_size_x, j * m_size_y), v2f(m_size_x, m_size_y), System::resources.texture.arhitectMouse);
				
			m_cell.setOutlineColor(Color::Green);
			m_cell.setOutlineThickness(-2);

			m_cell_vec.push_back(m_cell);
		}
	}

	m_ptr_menu = new ArchtectMenu(game_settings, m_Z_vec);

	is_create = false;
	is_delete = false;
	is_grid = false;
}

void Architect::Action(StateGame& state_game,bool& is_from_arhitetc, JsonSaveMenager &jsonSM, LevelNumber& number)
{
	
	if (System::IsKeyPressed(Key::F1) || System::IsKeyPressed(Key::F1)) {
		
		for (auto& obj : *m_ptr_objectListBack) 
			jsonSM.SaveObject(obj, "file_back.json",number);

		for (auto& obj : *m_ptr_objectListZero) 
			jsonSM.SaveObject(obj, "file_zero.json", number);	
		
		for (auto& obj : *m_ptr_objectListFront) 
			jsonSM.SaveObject(obj, "file_front.json", number);
		


		ObjectManager::ObjectBeckID = 0;
		ObjectManager::ObjectZeroID = 0;
		ObjectManager::ObjectFrontID = 0;

		is_from_arhitetc = true;

		state_game = StateGame::ON_GAME;
	}

	if (System::IsKeyReleased(Key::F1) || System::IsKeyReleased(Key::F1)) {

	}

	if (System::IsKeyPressed(Key::Left) || System::IsKeyPressed(Key::A)) {
		System::cam.move( - 10 * m_zoom, 0);
	}

	if (System::IsKeyReleased(Key::Left) || System::IsKeyReleased(Key::A)) {

	}

	if (System::IsKeyPressed(Key::Right) || System::IsKeyPressed(Key::D)) {
		System::cam.move(10 * m_zoom, 0); //cout << "D" << endl;
	}

	if (System::IsKeyReleased(Key::Right) || System::IsKeyReleased(Key::D)) {

	}

	if (System::IsKeyPressed(Key::Up) || System::IsKeyPressed(Key::W)) {
		System::cam.move(0, -10 * m_zoom);
	}

	if ((System::IsKeyReleased(Key::Up) || System::IsKeyReleased(Key::W))) {

	}

	if (System::IsKeyPressed(Key::Down) || System::IsKeyPressed(Key::S)) {
		System::cam.move(0, 10 * m_zoom);
	}

	if ((System::IsKeyReleased(Key::Down) || System::IsKeyReleased(Key::S))) {

	}
	//------------------------------------------------------
	if (!System::IsContains(*m_ptr_menu->GetSnape(), System::cur_p / m_zoom - System::cam.getCenter() / m_zoom)) {
		//cout << "********************" << endl;
		//cout << (System::cur_p / m_zoom - System::cam.getCenter() / m_zoom).x << endl;
		//cout << m_ptr_menu->GetSnape()->getPosition().x << endl;
		//cout << "Not On Menu" << endl;
		//cout << "********************" << endl;
		for (auto& cell : m_cell_vec)
			if (System::IsContains(cell, System::cur_p)) {

				if (System::IsMousePressed(MouseButton::Left))
					is_create = true;

				if (System::IsMouseReleased(MouseButton::Left))
					is_create = false;

				if (System::IsMousePressed(MouseButton::Right))
					is_delete = true;

				if (System::IsMouseReleased(MouseButton::Right))
					is_delete = false;
			}
	}
	else {
		//cout << "********************" << endl;
		//cout << (System::cur_p / m_zoom - System::cam.getCenter() / m_zoom).x << endl;
		//cout << m_ptr_menu->GetSnape()->getPosition().x << endl;
		//cout << "On Menu" << endl;
		//cout << "********************" << endl;
		is_create = false;
		is_delete = false;
	}	
	//--------------------------------------------------------	
	if (System::IsKeyPressed(Key::Q))
	{
		m_zoom *= 0.90f;
		System::cam.zoom(0.90f);
		
	}

	if (System::IsKeyPressed(Key::E))
	{
		m_zoom *= 1.1f;
		System::cam.zoom(1.1f); 		
	}
	//-------------------------------------------------------------

	m_ptr_menu->Action(is_grid);

	//-------------------------------------------------------------
}




void Architect::Update()
{
	for (auto it = m_ptr_objectListBack->begin(); it != m_ptr_objectListBack->end(); ) {
		auto& object = it;
		if (object->Check_is_delete())
			it = m_ptr_objectListBack->erase(it);
		else
			it++;
	}

	for (auto it = m_ptr_objectListZero->begin(); it != m_ptr_objectListZero->end(); ) {
		auto& object = it;
		if (object->Check_is_delete()) {
			World::world->DestroyBody(it->GetBoby());
			it = m_ptr_objectListZero->erase(it);
		}
		else
			it++;
	}

	for (auto it = m_ptr_objectListFront->begin(); it != m_ptr_objectListFront->end(); ) {
		auto& object = it;
		if (object->Check_is_delete()) 
			it = m_ptr_objectListFront->erase(it);		
		else 
			it++;		
	}

	if (is_create)
		CreateObject();

	if (is_delete)
		DeleteObject(); 


	m_mouse.setSize(v2f(m_size_x, m_size_y));
	m_mouse.setOrigin(v2f(m_size_x, m_size_y) / 2.f);
	
	for (auto &cell : m_cell_vec)
		if (System::IsContains(cell, System::cur_p)) {
			m_mouse.setPosition(cell.getPosition());
		}

	m_ptr_menu->Update(m_zoom);

}

void Architect::Draw(StateGame& state_game, Player* player)
{
	if (state_game == StateGame::ON_ARCITECT) {

		m_ptr_menu->Draw();


		player->Draw();

		if(is_grid)
			for (auto &cell : m_cell_vec)
				System::wnd.draw(cell);

		System::wnd.draw(m_mouse);
	}		
}

void Architect::CreateObject()
{
	ObjectManager object;

	bool is_contact = false;

	switch (m_Z_vec)
	{
	case ArcitectVector::BECK:
		for (auto& obj : *m_ptr_objectListBack)
			if (System::IsContains(obj.GetShape(), System::cur_p)) {
				is_contact = true;
				break;
			}
		if (!is_contact) {
			object.CreateTextureBoxBack(m_mouse);
			m_ptr_objectListBack->push_back(object);
		}
		break;
	case ArcitectVector::ZERO:
		for (auto& obj : *m_ptr_objectListZero)
			if (System::IsContains(obj.GetShape(), System::cur_p)) {
				is_contact = true;
				break;
			}
		if (!is_contact) {
			object.CreateStaticBox(m_mouse);
			m_ptr_objectListZero->push_back(object);
		}
		break;
	case ArcitectVector::FRONT:
		for (auto& obj : *m_ptr_objectListFront)
			if (System::IsContains(obj.GetShape(), System::cur_p)) {
				is_contact = true;
				break;
			}
		if (!is_contact) {
			object.CreateTextureBoxFront(m_mouse);
			m_ptr_objectListFront->push_back(object);
		}
		break;
	default:
		break;
	}
}

void Architect::DeleteObject()
{
	switch (m_Z_vec)
	{
	case ArcitectVector::BECK:
		for (auto& object : *m_ptr_objectListBack) {
			if (System::IsContains(object.GetShape(), System::cur_p)) {
				object.DeleteObject();
				//ObjectManager::ObjectBeckID--;
			}
		}
		break;
	case ArcitectVector::ZERO:
		for (auto& object : *m_ptr_objectListZero) {
			if (System::IsContains(object.GetShape(), System::cur_p)) {
				object.DeleteObject();
				//ObjectManager::ObjectZeroID--;
			}
		}
		break;
	case ArcitectVector::FRONT:
		for (auto& object : *m_ptr_objectListFront) {
			if (System::IsContains(object.GetShape(), System::cur_p)) {
				object.DeleteObject();
				//ObjectManager::ObjectFrontID--;
			}
		}
		break;
	default:
		break;
	}
}

Architect::~Architect()
{
	delete m_ptr_menu;
}
