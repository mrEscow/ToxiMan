#include "Architect.h"

Architect::Architect(vector<ObjectManager>&objectListBeck, vector<ObjectManager>&objectListZero, vector<ObjectManager>&objectListFront)
{
	
	m_ptr_objectListBeck = &objectListBeck;
	m_ptr_objectListZero = &objectListZero;
	m_ptr_objectListFront = &objectListFront;

	m_size_x = 64;
	m_size_y = 64;

	m_mouse = System::CreateShape(System::cur_p, v2f(m_size_x, m_size_y), System::resources.texture.arhitectMouse);
	m_mouse.setOutlineColor(Color::Red);
	m_mouse.setOutlineThickness(-5);

	m_main_text = System::CreateText(v2f(System::cam_p.x - (System::scr_w / 2), System::cam_p.y - (System::scr_h / 2)),70,"ArchitectMode",System::resources.font.common,Color::White);
	m_name_vector_text = System::CreateText(v2f(System::cam_p.x - (System::scr_w / 2), System::cam_p.y - (System::scr_h / 2) + 100), 60, "Vector Zero", System::resources.font.common, Color::White);
	m_zoom_for_text = v2f(1, 1);
	m_koef = 1.f;


	for (size_t i = 0; i < 19 * 2; i++)
	{
		for (size_t j = 0; j < 10; j++) {
			
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
		// SAVE OBJECT 		
		for (auto obj : *m_ptr_objectListBeck) {
			jsonSM.SaveObject(obj, "file_beck.json",number);
		 }
		for (auto obj : *m_ptr_objectListZero) {
			jsonSM.SaveObject(obj, "file_zero.json", number);	
		}
		for (auto obj : *m_ptr_objectListFront) {
			jsonSM.SaveObject(obj, "file_front.json", number);
		}

		// clear ctatic
		ObjectManager::ObjectBeckID = 0;
		ObjectManager::ObjectZeroID = 0;
		ObjectManager::ObjectFrontID = 0;
		// is_from_arhitetc
		is_from_arhitetc = true;
		// GO IN GAME
		state_game = StateGame::ON_GAME;
	}

	if (System::IsKeyReleased(Key::F1) || System::IsKeyReleased(Key::F1)) {

	}

	if (System::IsKeyPressed(Key::Left) || System::IsKeyPressed(Key::A)) {
		//System::cam.setCenter(System::cam.getCenter().x - 10, (System::cam.getCenter().y));
		System::cam.move( - 10, 0);
	}

	if (System::IsKeyReleased(Key::Left) || System::IsKeyReleased(Key::A)) {

	}

	if (System::IsKeyPressed(Key::Right) || System::IsKeyPressed(Key::D)) {
		//System::cam.setCenter(System::cam.getCenter().x + 10, (System::cam.getCenter().y));
		System::cam.move(10, 0); //cout << "D" << endl;
	}

	if (System::IsKeyReleased(Key::Right) || System::IsKeyReleased(Key::D)) {

	}

	if (System::IsKeyPressed(Key::Up) || System::IsKeyPressed(Key::W)) {
		//System::cam.setCenter(System::cam.getCenter().x, (System::cam.getCenter().y - 10));
		System::cam.move(0, -10);
	}

	if ((System::IsKeyReleased(Key::Up) || System::IsKeyReleased(Key::W))) {

	}

	if (System::IsKeyPressed(Key::Down) || System::IsKeyPressed(Key::S)) {
		//System::cam.setCenter(System::cam.getCenter().x, (System::cam.getCenter().y + 10));
		System::cam.move(0, 10);
	}

	if ((System::IsKeyReleased(Key::Down) || System::IsKeyReleased(Key::S))) {

	}

	if (System::IsMousePressed(Button::Left)) {
		

	}

	if (System::IsMouseReleased(Button::Left)) {

		ObjectManager object;
		bool is_contact = false;
		switch (m_Z_vec)
		{
		case ArcitectVector::BECK:
			object.CreateTextureBoxBeck(m_mouse);
			
			m_ptr_objectListBeck->push_back(object);
			break;
		case ArcitectVector::ZERO:	

			for (auto obj : *m_ptr_objectListZero)
				if (System::IsContains(obj.m_shape, System::cur_p)) {
					is_contact = true;
					cout << "Contact " << endl;
					break;
				}
			if (!is_contact) {
				cout << "if not contact" << endl;
				object.CreateStaticBox(m_mouse);
				m_ptr_objectListZero->push_back(object);
			}

			break;
		case ArcitectVector::FRONT:
			object.CreateTextureBoxFront(m_mouse);
			m_ptr_objectListFront->push_back(object);
			break;
		default:
			break;
		}
		
	}

	if (System::IsMousePressed(Button::Right)) {
		
	}

	if (System::IsMouseReleased(Button::Right)) {
		DeleteObject();
	}

	//--------------------------------------------------------
	
	if (System::IsKeyPressed(Key::Q))
	{
		m_koef *= 0.95f;
		System::cam.zoom(0.95f);// gameZoom += 0.01f;
		m_zoom_for_text *= 0.95f;
		
	}
	if (System::IsKeyPressed(Key::E))
	{
		m_koef *= 1.05f;
		System::cam.zoom(1.05f); // gameZoom -= 0.01f;
		m_zoom_for_text *= 1.05f;
		//m_main_text.
		
	}

	//-------------------------------------------------------------

	if (System::IsKeyPressed(Key::Z)) {
		if (m_size_x >= 128)
			m_size_x -= 128;
	}

	if (System::IsKeyPressed(Key::X)) {
		m_size_x += 128;
	}

	if (System::IsKeyPressed(Key::C)) {
		if (m_size_y >= 128)
			m_size_y -= 128;
	}

	if (System::IsKeyPressed(Key::V)) {
		m_size_y += 128;
	}

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

void Architect::DeleteObject()
{
	switch (m_Z_vec)
	{
	case ArcitectVector::BECK:
		for (auto object : *m_ptr_objectListBeck)
			if (System::cur_p.x > object.GetObjectPosition().x - (object.GetObjectSize().x / 2) && System::cur_p.x < object.GetObjectPosition().x + (object.GetObjectSize().x / 2))
				if (System::cur_p.y > object.GetObjectPosition().y - (object.GetObjectSize().y / 2) && System::cur_p.y < object.GetObjectPosition().y + (object.GetObjectSize().y / 2))
				{
					it = m_ptr_objectListBeck->begin() + object.GetObjectID();					

					m_ptr_objectListBeck->erase(it);

					for (it;it != m_ptr_objectListBeck->end(); it++)
						it->SetNewID();

					ObjectManager::ObjectBeckID--;
				}
		break;
	case ArcitectVector::ZERO:
		for (auto object : *m_ptr_objectListZero)
			if (System::cur_p.x > object.GetObjectPosition().x - (object.GetObjectSize().x / 2) && System::cur_p.x < object.GetObjectPosition().x + (object.GetObjectSize().x / 2))
				if (System::cur_p.y > object.GetObjectPosition().y - (object.GetObjectSize().y / 2) && System::cur_p.y < object.GetObjectPosition().y + (object.GetObjectSize().y / 2))
				{
					it = m_ptr_objectListZero->begin() + object.GetObjectID();

					object.DeleteObject();

					m_ptr_objectListZero->erase(it);

					for (it; it != m_ptr_objectListZero->end(); it++)
						it->SetNewID();

					ObjectManager::ObjectZeroID--;
				}
		break;
	case ArcitectVector::FRONT:
		for (auto object : *m_ptr_objectListFront)
			if (System::cur_p.x > object.GetObjectPosition().x - (object.GetObjectSize().x / 2) && System::cur_p.x < object.GetObjectPosition().x + (object.GetObjectSize().x / 2))
				if (System::cur_p.y > object.GetObjectPosition().y - (object.GetObjectSize().y / 2) && System::cur_p.y < object.GetObjectPosition().y + (object.GetObjectSize().y / 2))
				{
					it = m_ptr_objectListFront->begin() + object.GetObjectID();

					m_ptr_objectListFront->erase(it);

					for (it; it != m_ptr_objectListFront->end(); it++)
						it->SetNewID();

					ObjectManager::ObjectFrontID--;
				}
		break;
	default:
		break;
	}


}

void Architect::Update()
{
	m_mouse.setSize(v2f(m_size_x, m_size_y));
	m_mouse.setOrigin(v2f(m_size_x, m_size_y) / 2.f);

	for (auto cell : m_cell_vec)		
		if (System::cur_p.x > cell.getPosition().x - (cell.getSize().x / 2) && System::cur_p.x < cell.getPosition().x + (cell.getSize().x / 2))
			if (System::cur_p.y > cell.getPosition().y - (cell.getSize().y / 2) && System::cur_p.y < cell.getPosition().y + (cell.getSize().y / 2))
			{
				m_mouse.setPosition(cell.getPosition());
			}


	//for (auto object : m_objectListBeck)
	//	object.Update("objectListBeck");
	//for (auto object : m_objectListZero)
	//	object.Update("objectListZero");
	//for (auto object : m_objectListFront)
	//	object.Update("objectListFront");


	switch (m_Z_vec)
	{
	case ArcitectVector::BECK:
		m_name_vector_text.setString("Vector Beck");
		break;
	case ArcitectVector::ZERO:
		m_name_vector_text.setString("Vector Zero");
		break;
	case ArcitectVector::FRONT:
		m_name_vector_text.setString("Vector Front");
		break;
	default:
		break;
	}
	 
	
	m_main_text.setPosition(System::cam.getCenter().x - (System::scr_w * m_koef / 2), System::cam.getCenter().y - System::scr_h * m_koef / 2);
	m_main_text.setScale(m_zoom_for_text);
	m_name_vector_text.setPosition(System::cam_p.x - (System::scr_w * m_koef / 2), System::cam_p.y - (System::scr_h * m_koef / 2) + (100 * m_koef));
	m_name_vector_text.setScale(m_zoom_for_text);


	System::wnd.setView(System::cam);

}

void Architect::Draw(StateGame& state_game, Player* player)
{
	for (auto object : *m_ptr_objectListBeck)
		object.Draw();
	for (auto object : *m_ptr_objectListZero)
		object.Draw();
	player->Draw();
	for (auto object : *m_ptr_objectListFront)
		object.Draw();
	if (state_game == StateGame::ON_ARCITECT) {
		for (auto cell : m_cell_vec)
			System::wnd.draw(cell);


		System::wnd.draw(m_mouse);

		System::wnd.draw(m_main_text);
		System::wnd.draw(m_name_vector_text);

	}
		
}
