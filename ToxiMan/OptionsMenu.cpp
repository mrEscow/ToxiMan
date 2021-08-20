#include "OptionsMenu.h"

//float size_options_menu = 50



OptionsMenu::OptionsMenu(StateMainMenu& state_main_menu, GameSettings& m_game_settings)
{
	m_state_main_menu_ptr = &state_main_menu;

	m_game_settings_ptr = &m_game_settings;

	text_options = System::CreateText(v2f(0, -350), 120, "Options", System::resources.font.erica_type, Color::Magenta);
	System::CenteringText(text_options);

	vec_button.push_back(make_unique<Button>(System::CreateShape(v2f(0, -225), v2f(200, 50), System::resources.texture.menu_button), "Back", *m_game_settings_ptr));

	if (m_game_settings_ptr->GetMusicOn()) {
		t_checkbox = System::resources.texture.menu_checkbox_ON; //cout << "t_checkbox_ON" << endl;
	}
	else {
		t_checkbox = System::resources.texture.menu_checkbox_OFF; //cout << "t_checkbox_OFF" << endl;
	}


	vec_checkbox.push_back(make_unique<CheckBox>(System::CreateShape(v2f(poz_checkbox_x, poz_checkbox_y + size_checkbox * 0 * DF), size_checkbox_xy, t_checkbox), "Music", m_game_settings_ptr->GetMusicOn(), *m_game_settings_ptr));
	vec_scroll.push_back(make_unique<Scroll>(v2f(poz_checkbox_x + 200, poz_checkbox_y + size_checkbox * 0 * DF), v2f(300, 50), "Music", m_game_settings_ptr->GetMusicVolume()));

	if (m_game_settings_ptr->GetSoundOn()) {
		t_checkbox = System::resources.texture.menu_checkbox_ON; //cout << "t_checkbox_ON" << endl;
	}
	else {
		t_checkbox = System::resources.texture.menu_checkbox_OFF; //cout << "t_checkbox_OFF" << endl;
	}

	vec_checkbox.push_back(make_unique<CheckBox>(System::CreateShape(v2f(poz_checkbox_x, poz_checkbox_y + size_checkbox * 1 * DF), size_checkbox_xy, t_checkbox), "Sound", m_game_settings_ptr->GetSoundOn(), *m_game_settings_ptr));
	vec_scroll.push_back(make_unique<Scroll>(v2f(poz_checkbox_x + 200, poz_checkbox_y + size_checkbox * 1 * DF), v2f(300, 50), "Sound", m_game_settings_ptr->GetSoundVolume()));


}

void OptionsMenu::Update()
{

	for (auto& button : vec_button)
		button->Update();
	for (auto& checkbox : vec_checkbox)
		checkbox->Update();
	for (auto& scroll : vec_scroll)
		scroll->Update();
}

void OptionsMenu::Draw()
{
	System::wnd.draw(text_options);
	for (auto& button : vec_button)
		button->Draw();
	for (auto& checkbox : vec_checkbox)
		checkbox->Draw();
	for (auto& scroll : vec_scroll)
		scroll->Draw();
}

void OptionsMenu::Action()
{
	for (auto& button : vec_button)
	{
		if (button->IsAction())
		{
			cout << button->GetNameId() << endl;
			if (button->GetNameId() == "Back")
			{
				*m_state_main_menu_ptr = StateMainMenu::ON_MAIN;
			}
		}
	}

	for (auto& checkbox : vec_checkbox)
	{
		if (checkbox->GetNameId() == "Music") {
			checkbox->Action();
			m_game_settings_ptr->SetMusicOn(checkbox->GetValue());

		}
		if (checkbox->GetNameId() == "Sound") {
			checkbox->Action();
			m_game_settings_ptr->SetSoundOn(checkbox->GetValue());

		}
	}


	for (auto& scroll : vec_scroll)
	{
		if (m_game_settings_ptr->GetMusicOn() && scroll->GetNameId() == "Music")
		{
			scroll->Action();
			m_game_settings_ptr->SetMusicVolume(scroll->GetValue());

		}
		if (m_game_settings_ptr->GetSoundOn() && scroll->GetNameId() == "Sound")
		{
			scroll->Action();
			m_game_settings_ptr->SetSoundVolume(scroll->GetValue());

		}
	}
}




OptionsMenu::~OptionsMenu()
{
}
