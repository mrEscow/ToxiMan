#include "ArchtectMenu.h"

ArchtectMenu::ArchtectMenu(GameSettings& game_settings)
{
	archMenu.setViewport(sf::FloatRect(0.f, 0.f, 0.25f, 1.f));
	//archMenu.setCenter(0, 0);
	m_menu = System::CreateShape(archMenu.getCenter(), archMenu.getSize(), Color::Yellow);	
	m_main_text = System::CreateText(v2f(10, 15 ), 70, "ArchitectMode:", System::resources.font.common, Color::Black);
	m_name_vector_text = System::CreateText(v2f(archMenu.getCenter().x + 10, 15), 70, "Vector Zero", System::resources.font.common, Color::Black);

	vec_button.push_back(make_unique<UI::Button>(System::CreateShape(v2f(200, 300), v2f(200, 50), System::resources.texture.menu_button), "NEW", game_settings));
}

void ArchtectMenu::Action()
{
	//System::wnd.setView(archMenu);
	cout << "x: " << System::cur_p.x << "y: " << System::cur_p.y << endl;
	//System::cur_p = System::cur_p_wnd;
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

void ArchtectMenu::Update(ArcitectVector &Z_vec)
{
	//System::wnd.setView(archMenu);
	for (auto& button : vec_button)
		button->Update();

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
}

ArchtectMenu::~ArchtectMenu()
{
}
