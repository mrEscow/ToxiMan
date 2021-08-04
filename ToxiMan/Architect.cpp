#include "Architect.h"

Architect::Architect(vector<ObjectManager> &objectListBeck, vector<ObjectManager> &objectListZero, vector<ObjectManager> &objectListFront)
{
	m_size_x = 64;
	m_size_y = 64;

	m_mouse = System::CreateShape(System::cur_p, v2f(m_size_x, m_size_y), System::resources.texture.arhitectMouse);
	m_mouse.setOutlineColor(Color::Red);
	m_mouse.setOutlineThickness(-5);

	m_text = System::CreateText(v2f(0,System::scr_h/2),16,"ArchitectMode",System::resources.font.common,Color::White);

}

void Architect::Action(StateGame& state_game)
{
	if (System::IsKeyPressed(Key::F1) || System::IsKeyPressed(Key::F1)) {
		
		// SAVE OBJECT FIXIT
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
		System::cam.move(10, 0);
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
		System::cam.zoom(0.95f);// gameZoom += 0.01f;
	}
	if (System::IsKeyPressed(Key::E))
	{
		System::cam.zoom(1.05f); // gameZoom -= 0.01f;
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
	for (auto object : m_objectListBeck)
		object.Update("objectListBeck");
	for (auto object : m_objectListZero)
		object.Update("objectListZero");
	for (auto object : m_objectListFront)
		object.Update("objectListFront");


	m_mouse.setSize(v2f(m_size_x, m_size_y));
	m_mouse.setOrigin(v2f(m_size_x, m_size_y) / 2.f);
	m_mouse.setPosition(System::cur_p);
	
	//System::wnd.setView(System::cam);
	System::wnd.setView(System::cam);
	//cout << "System::MOUSE:  " << System::cur_p_wnd.x << "\t" << System::cur_p_wnd.y << endl;

}

void Architect::Draw(StateGame& state_game)
{
	for (auto object : m_objectListBeck)
		object.Draw();
	for (auto object : m_objectListZero)
		object.Draw();
	for (auto object : m_objectListFront)
		object.Draw();
	if(state_game==StateGame::ON_ARCITECT)
		System::wnd.draw(m_mouse);
}
