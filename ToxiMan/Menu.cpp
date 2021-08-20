#include "Menu.h"

Menu::Menu(StateGame& state_game, GameSettings& game_settings)
{
	System::resources.texture.LoadMenu();
	//System::resources.audio.sound.LoadMenuSound();
	//System::resources.audio.music.LoadMenuMusic();
	//game_settings.ReadSettings();
	m_state_game_ptr = &state_game;
	m_game_settings_ptr = &game_settings;
	m_state = StateMainMenu::ON_MAIN;
	m_main_menu = make_unique<MainMenu>(*m_state_game_ptr, m_state, *m_game_settings_ptr);
	m_options_menu = make_unique<OptionsMenu>(m_state, *m_game_settings_ptr);
	m_exit_menu = make_unique<ExitMenu>(m_state, *m_game_settings_ptr);
	m_shape_back_ground = System::CreateShape(v2f(0, 0), v2f(B::scr_w, B::scr_h), System::resources.texture.menu_background);
}

void audioSettings(GameSettings& m_game_settings)
{
	//System::resources.audio.music.menu_music.setLoop(true);
	//System::resources.audio.music.menu_music.setVolume(m_game_settings.GetMusicVolume());

	//if (m_game_settings.GetMusicOn()) {
	//	//if (System::resources.audio.music.menu_music.getStatus() == System::resources.audio.music.menu_music.Stopped())
	//	//	System::resources.audio.music.menu_music.play();
	//}
	//else
	//	System::resources.audio.music.menu_music.stop();

}

void Menu::Update()
{
	audioSettings(*m_game_settings_ptr);

	switch (m_state)
	{
	case StateMainMenu::ON_MAIN:
		m_main_menu->Update(); break;
	case StateMainMenu::ON_OPTIONS:
		m_options_menu->Update(); break;
	case StateMainMenu::ON_EXIT:
		m_exit_menu->Update();

		break;
	}
}

void Menu::Draw()
{
	System::wnd.draw(m_shape_back_ground);
	switch (m_state)
	{
	case StateMainMenu::ON_MAIN:
		m_main_menu->Draw();
		break;
	case StateMainMenu::ON_OPTIONS:
		m_options_menu->Draw();
		break;
	case StateMainMenu::ON_EXIT:
		m_exit_menu->Draw();
		break;
	default: break;
	}
}

void Menu::Action()
{
	switch (m_state)
	{
	case StateMainMenu::ON_MAIN:
		m_main_menu->Action();
		break;
	case StateMainMenu::ON_OPTIONS:
		m_options_menu->Action();
		//m_game_settings_ptr->SaveSettings();
		break;
	case StateMainMenu::ON_EXIT:
		m_exit_menu->Action();
		break;
	default: break;
	}
}

Menu::~Menu()
{
}
