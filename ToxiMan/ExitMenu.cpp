#include "ExitMenu.h"

ExitMenu::ExitMenu(StateMainMenu& state_main_menu, GameSettings& game_settings)
{
	//m_state_game_ptr = &state_game;
	m_state_main_menu_ptr = &state_main_menu;
	m_game_settings_ptr = &game_settings;

	PNG& t_button = System::resources.texture.menu_button;

	text_exit = System::CreateText(v2f(0, -300), 40, "Are you sure you want to get out?", System::resources.font.erica_type, Color::Black);
	System::CenteringText(text_exit);

	vec_button.push_back(make_unique<UI::Button>(System::CreateShape(v2f(0, -225), v2f(200, 50), t_button), "Yes", *m_game_settings_ptr));
	vec_button.push_back(make_unique<UI::Button>(System::CreateShape(v2f(0, -150), v2f(200, 50), t_button), "No", *m_game_settings_ptr));
}

void ExitMenu::Update(StateGame& state_game)
{
	for (auto& button : vec_button)
		button->Update(state_game);
}

void ExitMenu::Draw()
{
	System::wnd.draw(text_exit);
	for (auto& button : vec_button)
		button->Draw();
}

void ExitMenu::Action()
{
	for (auto& button : vec_button)
	{
		if (button->IsAction())
		{
			cout << button->GetNameId() << endl;
			if (button->GetNameId() == "Yes") System::wnd.close();;
			if (button->GetNameId() == "No") *m_state_main_menu_ptr = StateMainMenu::ON_MAIN;

		}
	}
}

ExitMenu::~ExitMenu()
{
}
