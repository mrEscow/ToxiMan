#include "ArchtectMenu.h"

ArchtectMenu::ArchtectMenu(GameSettings& game_settings)
{
	archMenu.setViewport(sf::FloatRect(0.f, 0.f, 1.f, 1.f));
	//archMenu.setCenter(0, 0);
	m_menu = System::CreateShape(v2f(0, 0), v2f(System::scr_w / 8,System::scr_h), Color::Yellow);
	m_menu.setOrigin(0, 0);


	m_main_text = System::CreateText(v2f(0, 10), 30, "ArchitectMode:", System::resources.font.common, Color::Black);
	m_name_vector_text = System::CreateText(v2f(0 , 120), 30, "Vector Zero", System::resources.font.common, Color::Black);

	vec_button.push_back(make_unique<UI::Button>(System::CreateShape(v2f(m_menu.getSize().x / 2, 300), v2f(200, 50), System::resources.texture.menu_button), "NEW", game_settings));
	//vec_button[0].get()->GetShape()->setOrigin(0, 0);
}

void ArchtectMenu::Action()
{
	//cout << "*********************************************" << endl;
	//cout << " - System::scr_w / 5:  " << -System::scr_w / 5 << endl;
	//cout << "Sx: " << vec_button[0].get()->GetPos().x << endl;
	//cout << "Sy: " << vec_button[0].get()->GetPos().y << endl;
	//cout << "System::cur_p_wnd.x: " << System::cur_p_wnd.x << endl;
	//cout << "System::cur_p_wnd.y: " << System::cur_p_wnd.y << endl;
	//cout << "x: " << System::cur_p.x << "y: " << System::cur_p.y << endl;	
	//cout << "dx: " << System::cur_p.x - System::cam.getCenter().x << endl; 
	//cout << "dy: " << System::cur_p.y - System::cam.getCenter().y << endl;
	//cout << "*********************************************" << endl;

	//System::cur_p = System::cur_p_wnd;
	//cout << vec_button[0]->
	//cout << "System::scr_w / 4  : " << System::scr_w / 4 << endl;
	//cout << "m_menu.getSize().x : " << m_menu.getSize().x << endl;
	for (auto& button : vec_button)
	{
		if (button->IsAction())
		{
			cout << button->GetNameId() << endl;
			if (button->GetNameId() == "NEW")
			{
				cout << "Click!" << endl;
			}
		}
	}

}

void ArchtectMenu::Update(ArcitectVector &Z_vec, StateGame& state_game)
{
	//System::wnd.setView(archMenu);
	for (auto& button : vec_button)
		button->Update(state_game);

	switch (Z_vec)
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


}

void ArchtectMenu::Draw()
{
	System::wnd.setView(archMenu);

	System::wnd.draw(m_menu);
	System::wnd.draw(m_main_text);
	System::wnd.draw(m_name_vector_text);


	for (auto& button : vec_button)
		button->Draw();

	System::wnd.setView(System::cam);
}

ArchtectMenu::~ArchtectMenu()
{
}
