#include "Menu.h"

Menu::Menu(StateGame& state_game)
{
	System::resources.texture.LoadMenu();
	System::resources.audio.sound.LoadMenuSound();
	System::resources.audio.music.LoadMenuMusic();

	m_main_menu = make_unique<MainMenu>(*m_state_game_ptr);
	m_level_editor = make_unique<LevelEditor>();
	m_options_menu = make_unique<OptionsMenu>();
	m_exit_menu = make_unique<ExitMenu>();

	m_menu_back_ground = System::CreateShape(
		v2f(0.0f, 0.0f), 
		v2f(static_cast<float>(System::scr_w), 
		static_cast<float>(System::scr_h)), 
		System::resources.texture.menu_background
	);
}

void AudioSettings()
{
	System::resources.audio.music.menu_music.setLoop(true);
	System::resources.audio.music.menu_music.setVolume(GameSettings::GetMusicVolume());

	if (GameSettings::GetMusicOn()) {
		if (System::resources.audio.music.menu_music.getStatus() == System::resources.audio.music.menu_music.Stopped)
			System::resources.audio.music.menu_music.play();
	}
	else
		System::resources.audio.music.menu_music.stop();

}

void Menu::Update()
{
	AudioSettings();

	//cout << (int)g_StateMainMenu << endl;

	switch (g_StateMainMenu)
	{
	case StateMainMenu::ON_MAIN:
		m_main_menu->Update(); 
		break;
	case StateMainMenu::ON_LEVEL_EDITOR:
		System::resources.audio.music.menu_music.stop();
		System::cam.setViewport(sf::FloatRect(0.25f, 0.f, 1.f, 1.f));
		m_level_editor->Update();
		break;
	case StateMainMenu::ON_OPTIONS:
		m_options_menu->Update(); 
		break;
	case StateMainMenu::ON_EXIT:
		m_exit_menu->Update(); 
		break;
	default: break;
	}

	cout << (int)g_StateMainMenu << endl;
}

void Menu::Draw()
{
	switch (g_StateMainMenu)
	{
	case StateMainMenu::ON_MAIN:
		System::wnd.draw(m_menu_back_ground);
		m_main_menu->Draw();
		break;
	case StateMainMenu::ON_LEVEL_EDITOR:
		m_level_editor->Draw();
		break;
	case StateMainMenu::ON_OPTIONS:
		System::wnd.draw(m_menu_back_ground);
		m_options_menu->Draw();
		break;
	case StateMainMenu::ON_EXIT:
		System::wnd.draw(m_menu_back_ground);
		m_exit_menu->Draw();
		break;
	default: break;
	}
}

void Menu::Action()
{
	switch (g_StateMainMenu)
	{
	case StateMainMenu::ON_MAIN:
		GameSettings::SaveSettings();
		m_main_menu->Action();
		break;
	case StateMainMenu::ON_LEVEL_EDITOR:
		m_level_editor->Action();

		cout << (int)g_StateMainMenu << endl;
		cout << (int)g_StateMainMenu << endl;
		cout << (int)g_StateMainMenu << endl;

		break;
	case StateMainMenu::ON_OPTIONS:
		m_options_menu->Action();
		GameSettings::SaveSettings();
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
