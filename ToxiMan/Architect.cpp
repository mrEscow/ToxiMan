#include "Architect.h"

Architect::Architect()
{
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
		//Json json_back;
		//Json json_zero;
		//Json json_front;
		
		for (auto obj : m_objectListBeck) {

			jsonSM.SaveObject(obj, "file_beck.json",number);

			//json_back["ID"] = obj.m_ID;
			//json_back["Name"] = obj.m_name;

			//json_back["PosX"] = obj.m_shape.getPosition().x;
			//json_back["PosY"] = obj.m_shape.getPosition().y;

			//json_back["SizeX"] = obj.m_shape.getSize().x;
			//json_back["SizeY"] = obj.m_shape.getSize().y;

			//cout << "JSON: " << json_back << endl;

			//string serializedString = json_back.dump();

			//ofstream fout;
			//fout.open("file_beck.json", ofstream::app);
			//fout << serializedString << "\n";
			//fout.close(); 
		 }

		for (auto obj : m_objectListZero) {
			jsonSM.SaveObject(obj, "file_zero.json", number);

			//json_zero["ID"] = obj.m_ID;
			//json_zero["Name"] = obj.m_name;

			//json_zero["PosX"] = obj.m_shape.getPosition().x;
			//json_zero["PosY"] = obj.m_shape.getPosition().y;

			//json_zero["SizeX"] = obj.m_shape.getSize().x;
			//json_zero["SizeY"] = obj.m_shape.getSize().y;

			//cout << "JSON: " << json_zero << endl;

			//string serializedString = json_zero.dump();

			//ofstream fout;
			//fout.open("file_zero.json", ofstream::app);
			//fout << serializedString << "\n";
			//fout.close();
		}

		for (auto obj : m_objectListFront) {
			jsonSM.SaveObject(obj, "file_front.json", number);

			//json_front["ID"] = obj.m_ID;
			//json_front["Name"] = obj.m_name;

			//json_front["PosX"] = obj.m_shape.getPosition().x;
			//json_front["PosY"] = obj.m_shape.getPosition().y;

			//json_front["SizeX"] = obj.m_shape.getSize().x;
			//json_front["SizeY"] = obj.m_shape.getSize().y;

			//cout << "JSON: " << json_front << endl;

			//string serializedString = json_front.dump();

			//ofstream fout;
			//fout.open("file_front.json", ofstream::app);
			//fout << serializedString << "\n";
			//fout.close();
		}
		// CLEAR VECTORS
		m_objectListBeck.clear();
		m_objectListZero.clear();
		m_objectListFront.clear();
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
		System::cam.move(10, 0); cout << "D" << endl;
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

		switch (m_Z_vec)
		{
		case ArcitectVector::BECK:
			object.CreateTextureBoxBeck(m_mouse);
			m_objectListBeck.push_back(object);
			break;
		case ArcitectVector::ZERO:			
			object.CreateStaticBox(m_mouse);
			m_objectListZero.push_back(object);
			break;
		case ArcitectVector::FRONT:
			object.CreateTextureBoxFront(m_mouse);
			m_objectListFront.push_back(object);
			break;
		default:
			break;
		}

	}

	if (System::IsMousePressed(Button::Right)) {
		
	}

	if (System::IsMouseReleased(Button::Right)) {
		//cout << "MousePOS: " << System::cur_p.x << "  " << System::cur_p.y << endl;
		switch (m_Z_vec)
		{
		case ArcitectVector::BECK:
			for (auto object : m_objectListBeck)
				if (System::cur_p.x > object.GetObjectPosition().x - (object.GetObjectSize().x / 2) && System::cur_p.x < object.GetObjectPosition().x + (object.GetObjectSize().x / 2))
					if (System::cur_p.y > object.GetObjectPosition().y - (object.GetObjectSize().y / 2) && System::cur_p.y < object.GetObjectPosition().y + (object.GetObjectSize().y / 2))
					{
						uint i = object.GetObjectID();
						//cout << "ObjectID_delete:  " << object.GetObjectID() << endl;
						m_objectListBeck.erase(m_objectListBeck.begin() + i);

						for (i; i < m_objectListBeck.size(); i++)
							m_objectListBeck[i].SetNewID();
						ObjectManager::ObjectBeckID--;
					}
			break;
		case ArcitectVector::ZERO:
			for (auto object : m_objectListZero)
				if (System::cur_p.x > object.GetObjectPosition().x - (object.GetObjectSize().x / 2) && System::cur_p.x < object.GetObjectPosition().x + (object.GetObjectSize().x / 2))
					if (System::cur_p.y > object.GetObjectPosition().y - (object.GetObjectSize().y / 2) && System::cur_p.y < object.GetObjectPosition().y + (object.GetObjectSize().y / 2))
					{
						uint i = object.GetObjectID();
						//cout << "ObjectID_delete:  " << object.GetObjectID() << endl;
						m_objectListZero.erase(m_objectListZero.begin() + i);

						for (i; i < m_objectListZero.size(); i++)
							m_objectListZero[i].SetNewID();
						ObjectManager::ObjectZeroID--;
					}
			break;
		case ArcitectVector::FRONT:
			for (auto object : m_objectListFront)
				if (System::cur_p.x > object.GetObjectPosition().x - (object.GetObjectSize().x / 2) && System::cur_p.x < object.GetObjectPosition().x + (object.GetObjectSize().x / 2))
					if (System::cur_p.y > object.GetObjectPosition().y - (object.GetObjectSize().y / 2) && System::cur_p.y < object.GetObjectPosition().y + (object.GetObjectSize().y / 2))
					{
						uint i = object.GetObjectID();
						//cout << "ObjectID_delete:  " << object.GetObjectID() << endl;
						m_objectListFront.erase(m_objectListFront.begin() + i);

						for (i; i < m_objectListFront.size(); i++)
							m_objectListFront[i].SetNewID();
						ObjectManager::ObjectFrontID--;
					}
			break;
		default:
			break;
		}
		
		
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
		if (m_size_x >= 64)
			m_size_x -= 32;
	}

	if (System::IsKeyPressed(Key::X)) {
		m_size_x += 32;
	}

	if (System::IsKeyPressed(Key::C)) {
		if (m_size_y >= 64)
			m_size_y -= 32;
	}

	if (System::IsKeyPressed(Key::V)) {
		m_size_y += 32;
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


	for (auto object : m_objectListBeck)
		object.Update("objectListBeck");
	for (auto object : m_objectListZero)
		object.Update("objectListZero");
	for (auto object : m_objectListFront)
		object.Update("objectListFront");



	//m_mouse.setPosition(System::cur_p);


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
	 
	
	//m_main_text.setPosition(System::cam_p.x - (System::scr_w / 2), System::cam_p.y - System::scr_h / 2);
	//m_main_text.setPosition(System::cam.getCenter().x - (System::scr_w / 2), System::cam.getCenter().y- System::scr_h / 2);
	m_main_text.setPosition(System::cam.getCenter().x - (System::scr_w * m_koef / 2), System::cam.getCenter().y - System::scr_h * m_koef / 2);
	m_main_text.setScale(m_zoom_for_text);
	m_name_vector_text.setPosition(System::cam_p.x - (System::scr_w * m_koef / 2), System::cam_p.y - (System::scr_h * m_koef / 2) + (100 * m_koef));
	m_name_vector_text.setScale(m_zoom_for_text);



	//System::wnd.setView(System::cam);
	System::wnd.setView(System::cam);
	//cout << "System::MOUSE:  " << System::cur_p_wnd.x << "\t" << System::cur_p_wnd.y << endl;

}

void Architect::Draw(StateGame& state_game, Player* player)
{
	for (auto object : m_objectListBeck)
		object.Draw();
	for (auto object : m_objectListZero)
		object.Draw();
	player->Draw();
	for (auto object : m_objectListFront)
		object.Draw();
	if (state_game == StateGame::ON_ARCITECT) {
		for (auto cell : m_cell_vec)
			System::wnd.draw(cell);


		System::wnd.draw(m_mouse);

		System::wnd.draw(m_main_text);
		System::wnd.draw(m_name_vector_text);

	}
		
}
