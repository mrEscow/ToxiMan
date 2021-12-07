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

	m_mouse = System::CreateShape(
		System::cur_p, 
		v2f(
		static_cast<float> (m_size_x), 
		static_cast<float> (m_size_y)
		), 
		System::resources.texture.arhitectMouse);

	m_mouse.setOutlineColor(Color::Red);
	m_mouse.setOutlineThickness(-5);

	m_start = System::CreateShape(
		m_map_ptr->GetStartPos(),
		v2f(
			static_cast<float> (m_size_x),
			static_cast<float> (m_size_y)
		), 
		System::resources.texture.arhitectMouse); // cteate texture
	m_start.setOutlineColor(Color::Cyan);
	m_start.setOutlineThickness(-50);

	
	m_finish = System::CreateShape(
		m_map_ptr->GetFinalPos(),
		v2f(
			static_cast<float> (m_size_x),
			static_cast<float> (m_size_y)
		),
		System::resources.texture.arhitectMouse); // cteate texture
	m_finish.setOutlineColor(Color::Yellow);
	m_finish.setOutlineThickness(-50);

	//m_zoom = 1.f;

	for (size_t y = 0; y < size_map.y; y++)
	{
		for (size_t x = 0; x < size_map.x; x++) {
			
			m_cell = System::CreateShape(
				v2f(
					static_cast<float> (x) * m_size_x, 
					static_cast<float> (y) * m_size_y),
				v2f(
					static_cast<float> (m_size_x),
					static_cast<float> (m_size_y)),
				System::resources.texture.arhitectMouse
			);
				
			m_cell.setOutlineColor(Color::Green);
			m_cell.setOutlineThickness(-2);

			m_cell_vec.push_back(m_cell);
		}
	}

	m_ptr_menu = new ArchtectMenu(*m_map_ptr,game_settings, m_Z_vec);

	// 
	is_create = false;
	is_delete = false;
	is_grid = false;
	is_back = false;

	// buttons for map
	is_new_start = false;
	is_new_finish = false;
	is_save_map = false;
	is_next_level = false;
}

void Architect::Action(StateGame& state_game, StateGame& previous_state, bool& is_from_arhitetc, JsonSaveMenager &jsonSM, UINT32 GameLevel, bool& is_Next_Level)
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

	if (!is_new_start && !is_new_finish) {
		//cout << "m_is_new_start in arhitect_100" << endl;
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


	if (is_new_start && !is_new_finish) {

		//cout << "m_is_new_start in arhitect_200" << endl;
		is_create = false;
		is_delete = false;

		if (!System::IsContains(*m_ptr_menu->GetSnape(), System::cur_p / System::zoom - System::cam.getCenter() / System::zoom)) {
			for (auto& cell : m_cell_vec)
				if (System::IsContains(cell, System::cur_p)) {

					if (System::IsMousePressed(MouseButton::Left)) {
						//cout << "m_is_new_start in arhitect_210" << endl;
						CreateStart();
						is_create = false;
						is_delete = false;
					}
					if (System::IsMouseReleased(MouseButton::Left)) {
						//cout << "m_is_new_start in arhitect_220" << endl;
						//CreateStart();
						is_create = false;
						is_delete = false;
					}

				}
		}		
	}

	if (!is_new_start && is_new_finish) {

		//cout << "m_is_new_start in arhitect_200" << endl;
		is_create = false;
		is_delete = false;

		if (!System::IsContains(*m_ptr_menu->GetSnape(), System::cur_p / System::zoom - System::cam.getCenter() / System::zoom)) {
			for (auto& cell : m_cell_vec)
				if (System::IsContains(cell, System::cur_p)) {

					if (System::IsMousePressed(MouseButton::Left)) {
						//cout << "m_is_new_start in arhitect_210" << endl;
						CreateFinish();
						is_create = false;
						is_delete = false;
					}
					if (System::IsMouseReleased(MouseButton::Left)) {
						//cout << "m_is_new_start in arhitect_220" << endl;
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
	//--------------------------------------------------------  --IS FROM MENU
	if (is_next_level)
	{
		is_save_map = true;
		is_next_level = false;
	}
	//-------------------------------------------------------------
	m_ptr_menu->Action(
		is_grid, 

		is_new_start, 
		is_new_finish,
		is_save_map,

		is_back,

		is_Next_Level
	);
	//-------------------------------------------------------------
	if (is_Next_Level)
		is_next_level = is_Next_Level;
	//-------------------------------------------------------------

	if (is_back) {


		is_from_arhitetc = true;

		is_back = false;

		state_game = previous_state;
	}
	//-------------------------------------------------------------
	if (is_save_map) {
		is_grid = false;

		jsonSM.DeleteJsonFile("Save/MAP.json", GameLevel);
		jsonSM.SaveMap("Save/MAP.json", *m_map_ptr, GameLevel);
		*m_map_ptr = jsonSM.LoadMap("Save/MAP.json", GameLevel);


		for (auto& obj : *m_ptr_objectListBack)
			jsonSM.SaveObject(obj, "file_back.json", GameLevel);

		for (auto& obj : *m_ptr_objectListZero)
			jsonSM.SaveObject(obj, "file_zero.json", GameLevel);

		for (auto& obj : *m_ptr_objectListFront)
			jsonSM.SaveObject(obj, "file_front.json", GameLevel);


		ObjectManager::ObjectBeckID = 0;
		ObjectManager::ObjectZeroID = 0;
		ObjectManager::ObjectFrontID = 0;

		m_cell_vec.clear();
		m_cell_vec.reserve(m_map_ptr->GetMapSize().y* m_map_ptr->GetMapSize().x);

		for (size_t y = 0; y < m_map_ptr->GetMapSize().y; y++)
		{
			for (size_t x = 0; x < m_map_ptr->GetMapSize().x; x++) {

				m_cell = System::CreateShape(
					v2f(
						static_cast<float> (x) * m_size_x,
						static_cast<float> (y) * m_size_y),
					v2f(
						static_cast<float> (m_size_x),
						static_cast<float> (m_size_y)),
					System::resources.texture.arhitectMouse
				);

				m_cell.setOutlineColor(Color::Green);
				m_cell.setOutlineThickness(-2);

				m_cell_vec.push_back(m_cell);
			}
		}

		//is_grid = true;
		is_save_map = false;
		cout << "SaveMap" << endl;
	}

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


	m_mouse.setSize(
		v2f(
			static_cast<float> (m_size_x), 
			static_cast<float> (m_size_y))
	);
	m_mouse.setOrigin(
		v2f(
			static_cast<float> (m_size_x), 
			static_cast<float> (m_size_y)) / 2.f
	);
	
	for (auto &cell : m_cell_vec)
		if (System::IsContains(cell, System::cur_p)) {


			m_mouse.setPosition(cell.getPosition());


			if (is_new_start && !is_new_finish)
			m_start.setPosition(cell.getPosition());

			if (!is_new_start && is_new_finish)
			m_finish.setPosition(cell.getPosition());


		}

	if (is_new_start && is_new_finish) {
		m_start.setPosition(m_map_ptr->GetStartPos());
		m_finish.setPosition(m_map_ptr->GetFinalPos());
	}

	m_ptr_menu->Update();

}

void Architect::Draw(StateGame& state_game, Player* player)
{
	if (state_game == StateGame::ON_ARCITECT && !is_save_map) {

		m_ptr_menu->Draw();

		System::wnd.draw(m_start);
		System::wnd.draw(m_finish);

		player->Draw();
		
		if(is_grid && !is_save_map)
			if(!m_cell_vec.empty())
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

vector<ObjectManager>& Architect::GetVecZero()
{
	return *m_ptr_objectListZero;
}

void Architect::CreateStart()
{
	m_map_ptr->SetStartPos(m_start.getPosition());

	is_new_start = false;
}

void Architect::CreateFinish() 
{
	m_map_ptr->SetFinalPos(m_finish.getPosition());

	is_new_finish = false;
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
