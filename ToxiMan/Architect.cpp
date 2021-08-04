#include "Architect.h"

Architect::Architect()
{
	m_shape = System::CreateShape(System::cur_p, v2f(64, 64), System::resources.texture.arhitectMouse);
	m_shape.setOutlineColor(Color::Red);
	m_shape.setOutlineThickness(-5);

}

void Architect::Action(StateGame& state_game)
{
	if (System::IsKeyPressed(Key::F1) || System::IsKeyPressed(Key::F1)) {
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
		object.CreateStaticBox64();
		objectList.push_back(object);
	}

	if (System::IsMousePressed(Button::Right)) {
		
	}

	if (System::IsMouseReleased(Button::Right)) {
		//cout << "MousePOS: " << System::cur_p.x << "  " << System::cur_p.y << endl;

		for (auto object : objectList) 
			if (System::cur_p.x > object.GetObjectPosition().x - (object.GetObjectSize().x / 2) && System::cur_p.x < object.GetObjectPosition().x + (object.GetObjectSize().x / 2))
				if (System::cur_p.y > object.GetObjectPosition().y - (object.GetObjectSize().y / 2) && System::cur_p.y < object.GetObjectPosition().y + (object.GetObjectSize().y / 2))
				{
					uint i = object.GetObjectID();


					//cout << "ObjectID_delete:  " << object.GetObjectID() << endl;
					objectList.erase(objectList.begin() + i);

					for (i; i < objectList.size(); i++)
						objectList[i].SetNewID();


					ObjectManager::ObjectID--;
				}

			
		
	}


	
	if (System::IsKeyPressed(Key::Q))
	{
		System::cam.zoom(0.95f);// gameZoom += 0.01f;
	}
	if (System::IsKeyPressed(Key::E))
	{
		System::cam.zoom(1.05f); // gameZoom -= 0.01f;
	}

}

void Architect::DeleteObject()
{
}

void Architect::Update()
{
	for (auto object : objectList)
		object.Update();


	System::wnd.setView(System::cam);
	System::wnd.setView(System::cam);
	//cout << "System::MOUSE:  " << System::cur_p_wnd.x << "\t" << System::cur_p_wnd.y << endl;
	m_shape.setPosition(System::cur_p);
}

void Architect::Draw(StateGame& state_game)
{
	for (auto object : objectList)
		object.Draw();
	if(state_game==StateGame::ON_ARCITECT)
		System::wnd.draw(m_shape);
}
