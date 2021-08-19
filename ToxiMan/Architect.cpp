#include "Architect.h"

Architect::Architect(vector<ObjectManager>&objectListBeck, vector<ObjectManager>&objectListZero, vector<ObjectManager>&objectListFront, v2f size_map)
{
	m_ptr_objectListBeck = &objectListBeck;
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
}

void Architect::Action(StateGame& state_game,bool& is_from_arhitetc, JsonSaveMenager &jsonSM, LevelNumber& number)
{
	
	if (System::IsKeyPressed(Key::F1) || System::IsKeyPressed(Key::F1)) {
		
		for (auto& obj : *m_ptr_objectListBeck) {
			jsonSM.SaveObject(obj, "file_beck.json",number);
		 }
		for (auto& obj : *m_ptr_objectListZero) {
			jsonSM.SaveObject(obj, "file_zero.json", number);	
		}
		for (auto& obj : *m_ptr_objectListFront) {
			jsonSM.SaveObject(obj, "file_front.json", number);
		}


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

	for (auto& cell : m_cell_vec)
		if (System::IsContains(cell, System::cur_p)) {

			if (System::IsMouseReleased(Button::Left))
				CreateObject();

			if (System::IsMouseReleased(Button::Right))
				DeleteObject();
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

	//if (System::IsKeyPressed(Key::Z)) {
	//	if (m_size_x >= 128)
	//		m_size_x -= 128;
	//}

	//if (System::IsKeyPressed(Key::X)) {
	//	m_size_x += 128;
	//}

	//if (System::IsKeyPressed(Key::C)) {
	//	if (m_size_y >= 128)
	//		m_size_y -= 128;
	//}

	//if (System::IsKeyPressed(Key::V)) {
	//	m_size_y += 128;
	//}

	//-------------------------------------------------------------

	if (System::IsKeyPressed(Key::Num1)) {
		m_Z_vec = ArcitectVector::BECK;
	}

	if (System::IsKeyPressed(Key::Num2)) {
		m_Z_vec = ArcitectVector::ZERO;
	}

	if (System::IsKeyPressed(Key::Num3)) {
		m_Z_vec = ArcitectVector::FRONT;
	}
	//-------------------------------------------------------------
}




void Architect::Update()
{
	m_menu.Update(m_Z_vec);

	m_mouse.setSize(v2f(m_size_x, m_size_y));
	m_mouse.setOrigin(v2f(m_size_x, m_size_y) / 2.f);
	
	for (auto &cell : m_cell_vec)
		if (System::IsContains(cell, System::cur_p)) {
			m_mouse.setPosition(cell.getPosition());
		}

}

void Architect::Draw(StateGame& state_game, Player* player)
{
	if (state_game == StateGame::ON_ARCITECT) {

		m_menu.Draw();
		System::wnd.setView(System::cam);

		player->Draw();

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
		for (auto& obj : *m_ptr_objectListBeck)
			if (System::IsContains(obj.m_shape, System::cur_p)) {
				is_contact = true;
				//cout << "Contact " << endl;
				break;
			}
		if (!is_contact) {
			//cout << "if not contact" << endl;
			object.CreateTextureBoxBeck(m_mouse);
			m_ptr_objectListBeck->push_back(object);
		}
		break;
	case ArcitectVector::ZERO:
		for (auto& obj : *m_ptr_objectListZero)
			if (System::IsContains(obj.m_shape, System::cur_p)) {
				is_contact = true;
				//cout << "Contact " << endl;
				break;
			}
		if (!is_contact) {
			//cout << "if not contact" << endl;
			object.CreateStaticBox(m_mouse);
			m_ptr_objectListZero->push_back(object);
		}
		break;
	case ArcitectVector::FRONT:
		for (auto& obj : *m_ptr_objectListFront)
			if (System::IsContains(obj.m_shape, System::cur_p)) {
				is_contact = true;
				//cout << "Contact " << endl;
				break;
			}
		if (!is_contact) {
			//cout << "if not contact" << endl;
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
		for (auto& object : *m_ptr_objectListBeck)
			if (System::IsContains(object.m_shape, System::cur_p)) {
				it = m_ptr_objectListBeck->begin() + object.GetObjectID();
				//World::world->DestroyBody(object.m_body);
				m_ptr_objectListBeck->erase(it);
				for (it = m_ptr_objectListBeck->begin() + object.GetObjectID(); it >= m_ptr_objectListBeck->end(); it++)
					it->SetNewID();
				ObjectManager::ObjectBeckID--;
				//break;
			}
		break;
	case ArcitectVector::ZERO:
		for (auto& object : *m_ptr_objectListZero)
			if (System::IsContains(object.m_shape, System::cur_p)) {

				it = m_ptr_objectListZero->begin() + object.GetObjectID();

				World::world->DestroyBody(it->m_body);
				m_ptr_objectListZero->erase(it);

				for (it = m_ptr_objectListZero->begin() + object.GetObjectID(); it >= m_ptr_objectListZero->end(); it++)
					it->SetNewID();

				ObjectManager::ObjectZeroID--;

				//break;
			}
		break;
	case ArcitectVector::FRONT:
		for (auto& object : *m_ptr_objectListFront)
			if (System::IsContains(object.m_shape, System::cur_p)) {
				it = m_ptr_objectListFront->begin() + object.GetObjectID();
				//World::world->DestroyBody(object.m_body);
				m_ptr_objectListFront->erase(it);
				for (it = m_ptr_objectListFront->begin() + object.GetObjectID(); it >= m_ptr_objectListFront->end(); it++)
					it->SetNewID();
				ObjectManager::ObjectFrontID--;
				break;
			}
		break;
	default:
		break;
	}
}

Architect::~Architect()
{
}
