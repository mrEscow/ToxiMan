#include "Architect.h"



Architect::Architect(Map& map,vector<ObjectManager>&objectListBack, vector<ObjectManager>&objectListZero, vector<ObjectManager>&objectListFront, v2f size_map, GameSettings& game_settings)
{

	m_map_ptr = &map;



	m_ptr_objectListBack = &objectListBack;
	m_ptr_objectListZero = &objectListZero;
	m_ptr_objectListFront = &objectListFront;


	// размер Shape
	m_size_x = 64;
	m_size_y = 64;

	m_mouse = System::CreateShape(System::cur_p, v2f(m_size_x, m_size_y), System::resources.texture.arhitectMouse);
	m_mouse.setOutlineColor(Color::Red);
	m_mouse.setOutlineThickness(-5);

	m_start = System::CreateShape(System::cur_p, v2f(m_size_x, m_size_y), System::resources.texture.arhitectMouse);
	m_start.setOutlineColor(Color::Cyan);
	m_start.setOutlineThickness(-20);

	//m_zoom = 1.f;

	for (size_t y = 0; y < size_map.y; y++)
	{
		for (size_t x = 0; x < size_map.x; x++) {
			
			m_cell = System::CreateShape(
				v2f(x * m_size_x, y * m_size_y), 
				v2f(m_size_x, m_size_y), 
				System::resources.texture.arhitectMouse
			);
				
			m_cell.setOutlineColor(Color::Green);
			m_cell.setOutlineThickness(-2);

			m_cell_vec.push_back(m_cell);
		}
	}

	m_ptr_menu = new ArchtectMenu(*m_map_ptr,game_settings, m_Z_vec);

	is_create = false;
	is_delete = false;
	is_grid = false;
	is_back = false;

	m_is_new_start = false;
	is_save_map = false;
}

void Architect::Action(StateGame& state_game, StateGame& previous_state, bool& is_from_arhitetc, JsonSaveMenager &jsonSM, LevelNumber& number)
{
	

	if (System::IsKeyReleased(Key::F1) || System::IsKeyReleased(Key::F1)) {

	}

	if (System::IsKeyPressed(Key::Left) || System::IsKeyPressed(Key::A)) {
		System::cam.move( - 10 * System::zoom, 0);
	}

	if (System::IsKeyReleased(Key::Left) || System::IsKeyReleased(Key::A)) {

	}

	if (System::IsKeyPressed(Key::Right) || System::IsKeyPressed(Key::D)) {
		System::cam.move(10 * System::zoom, 0); //cout << "D" << endl;
	}

	if (System::IsKeyReleased(Key::Right) || System::IsKeyReleased(Key::D)) {

	}

	if (System::IsKeyPressed(Key::Up) || System::IsKeyPressed(Key::W)) {
		System::cam.move(0, -10 * System::zoom);
	}

	if ((System::IsKeyReleased(Key::Up) || System::IsKeyReleased(Key::W))) {

	}

	if (System::IsKeyPressed(Key::Down) || System::IsKeyPressed(Key::S)) {
		System::cam.move(0, 10 * System::zoom);
	}

	if ((System::IsKeyReleased(Key::Down) || System::IsKeyReleased(Key::S))) {

	}
	//------------------------------------------------------

	if (!m_is_new_start) {
		cout << "m_is_new_start in arhitect_333" << endl;
		if (!System::IsContains(*m_ptr_menu->GetSnape(), System::cur_p / System::zoom - System::cam.getCenter() / System::zoom)) {
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
			is_create = false;
			is_delete = false;
		}
	}


	if (m_is_new_start) {

		cout << "m_is_new_start in arhitect_111" << endl;
		is_create = false;
		is_delete = false;

		if (!System::IsContains(*m_ptr_menu->GetSnape(), System::cur_p / System::zoom - System::cam.getCenter() / System::zoom)) {
			for (auto& cell : m_cell_vec)
				if (System::IsContains(cell, System::cur_p)) {

					if (System::IsMousePressed(MouseButton::Left)) {
						cout << "m_is_new_start in arhitect_222" << endl;
						CreateStart();
						is_create = false;
						is_delete = false;
					}
					if (System::IsMouseReleased(MouseButton::Left)) {
						cout << "m_is_new_start in arhitect_444" << endl;
						//CreateStart();
						is_create = false;
						is_delete = false;
					}

				}
		}		
	}



	//--------------------------------------------------------	
	if (System::IsKeyPressed(Key::Q))
	{
		System::zoom *= 0.90f;
		System::cam.zoom(0.90f);		
	}

	if (System::IsKeyPressed(Key::E))
	{
		System::zoom *= 1.1f;
		System::cam.zoom(1.1f); 		
	}
	//-------------------------------------------------------------

	m_ptr_menu->Action(is_grid, is_back, m_is_new_start, is_save_map);


	//-------------------------------------------------------------

	if (is_back) {
		for (auto& obj : *m_ptr_objectListBack)
			jsonSM.SaveObject(obj, "file_back.json", number);

		for (auto& obj : *m_ptr_objectListZero)
			jsonSM.SaveObject(obj, "file_zero.json", number);

		for (auto& obj : *m_ptr_objectListFront)
			jsonSM.SaveObject(obj, "file_front.json", number);

		cout << "SAVE" << endl;

		ObjectManager::ObjectBeckID = 0;
		ObjectManager::ObjectZeroID = 0;
		ObjectManager::ObjectFrontID = 0;

		is_from_arhitetc = true;

		is_back = false;

		state_game = previous_state;
	}

	if (is_save_map) {
		JsonSaveMenager temp;
		temp.DeleteJsonFile("Save/MAP.json", number);
		temp.SaveMap("Save/MAP.json", *m_map_ptr, number);
		is_save_map = false;
		cout << "SaveMap" << endl;
	}

	//-------------------------------------------------------------
}




void Architect::Update()
{

	//cout << "IS:" << m_is_new_start << endl;

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

	//if (m_is_new_start) {
	//	CreateStart();
	//}




	m_mouse.setSize(v2f(m_size_x, m_size_y));
	m_mouse.setOrigin(v2f(m_size_x, m_size_y) / 2.f);
	
	for (auto &cell : m_cell_vec)
		if (System::IsContains(cell, System::cur_p)) {
			m_mouse.setPosition(cell.getPosition());
			m_start.setPosition(cell.getPosition());
		}

	m_ptr_menu->Update();

}

void Architect::Draw(StateGame& state_game, Player* player)
{
	if (state_game == StateGame::ON_ARCITECT) {

		m_ptr_menu->Draw();


		player->Draw();

		if(is_grid)
			for (auto &cell : m_cell_vec)
				System::wnd.draw(cell);

		if (!m_is_new_start) {
			System::wnd.draw(m_mouse);
			//cout << "m_mouse" << endl;
		}
			
		else {
			System::wnd.draw(m_start);
			//cout << "m_start" << endl;
		}
			
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

vector<ObjectManager>& Architect::GetVecZero()
{
	return *m_ptr_objectListZero;
}

void Architect::CreateStart()
{
	// if()
	// delete old
	// set new pos and texturu

	m_map_ptr->SetStartPos(m_start.getPosition());

	m_is_new_start = false;
}

vector<Shape>& Architect::GetVecCell()
{
	return m_cell_vec;
}

Map Architect::GetMap()
{
	return *m_map_ptr;
}

Architect::~Architect()
{
	delete m_ptr_menu;
}
