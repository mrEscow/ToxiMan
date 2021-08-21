#include "ArchtectMenu.h"

ArchtectMenu::ArchtectMenu(GameSettings& game_settings)
{
	archMenu.reset(sf::FloatRect(0, 0, System::scr_w, System::scr_h));
	archMenu.setCenter(-System::scr_w / 4,0);

	m_menu = System::CreateShape(v2f(0, 0), v2f(System::scr_w / 4,System::scr_h), Color::Yellow);
	m_menu.setPosition(-m_menu.getSize().x * 2.5f , 0);

	m_main_text = System::CreateText(v2f(m_menu.getPosition().x , -500), 30, "ArchitectMode:", System::resources.font.common, Color::Black);
	System::CenteringText(m_main_text);
	m_name_vector_text = System::CreateText(v2f(m_menu.getPosition().x, -450), 20, "Vector Zero", System::resources.font.common, Color::Black);
	System::CenteringText(m_name_vector_text);

	vec_button.push_back(make_unique<UI::Button>(System::CreateShape(v2f(m_menu.getPosition().x, 0), v2f(100, 100), System::resources.texture.menu_button), "NEW", game_settings));

}

void ArchtectMenu::Action()
{
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

	System::wnd.setView(System::cam);
}

ArchtectMenu::~ArchtectMenu()
{
}
