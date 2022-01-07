#include "OptionsMenu.h"

//float size_options_menu = 50



OptionsMenu::OptionsMenu(StateMainMenu& state_main_menu)
{
	m_state_main_menu_ptr = &state_main_menu;


	text_options = System::CreateText(v2f(0, -350), 120, "Options", System::resources.font.erica_type, Color::Magenta);
	System::CenteringText(text_options);

	vec_button.push_back(make_unique<UI::Button>(System::CreateShape(v2f(0, -225), v2f(200, 50), System::resources.texture.menu_button), "Back"));

	if (GameSettings::GetMusicOn()) {
		t_checkbox = System::resources.texture.menu_checkbox_ON; //cout << "t_checkbox_ON" << endl;
	}
	else {
		t_checkbox = System::resources.texture.menu_checkbox_OFF; //cout << "t_checkbox_OFF" << endl;
	}


	vec_checkbox.push_back(make_unique<UI::CheckBox>(System::CreateShape(v2f(poz_checkbox_x, poz_checkbox_y + size_checkbox * 0 * DF), size_checkbox_xy, t_checkbox), "Music", GameSettings::GetMusicOn()));
	vec_scroll.push_back(make_unique<UI::Scroll>(v2f(poz_checkbox_x + 200, poz_checkbox_y + size_checkbox * 0 * DF), v2f(300, 50), "Music", GameSettings::GetMusicVolume()));

	if (GameSettings::GetSoundOn()) {
		t_checkbox = System::resources.texture.menu_checkbox_ON; //cout << "t_checkbox_ON" << endl;
	}
	else {
		t_checkbox = System::resources.texture.menu_checkbox_OFF; //cout << "t_checkbox_OFF" << endl;
	}

	vec_checkbox.push_back(make_unique<UI::CheckBox>(System::CreateShape(v2f(poz_checkbox_x, poz_checkbox_y + size_checkbox * 1 * DF), size_checkbox_xy, t_checkbox), "Sound", GameSettings::GetSoundOn()));
	vec_scroll.push_back(make_unique<UI::Scroll>(v2f(poz_checkbox_x + 200, poz_checkbox_y + size_checkbox * 1 * DF), v2f(300, 50), "Sound", GameSettings::GetSoundVolume()));


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
			GameSettings::SetMusicOn(checkbox->GetValue());

		}
		if (checkbox->GetNameId() == "Sound") {
			checkbox->Action();
			GameSettings::SetSoundOn(checkbox->GetValue());

		}
	}


	for (auto& scroll : vec_scroll)
	{
		if (GameSettings::GetMusicOn() && scroll->GetNameId() == "Music")
		{
			scroll->Action();
			GameSettings::SetMusicVolume(scroll->GetValue());

		}
		if (GameSettings::GetSoundOn() && scroll->GetNameId() == "Sound")
		{
			scroll->Action();
			GameSettings::SetSoundVolume(scroll->GetValue());

		}
	}
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






OptionsMenu::~OptionsMenu()
{
}
