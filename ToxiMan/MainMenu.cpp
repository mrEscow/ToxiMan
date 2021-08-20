#include "MainMenu.h"

MainMenu::MainMenu(StateGame& state_game, StateMainMenu& state_main_menu, GameSettings& game_settings)
{
	m_state_game_ptr = &state_game;
	m_state_main_menu_ptr = &state_main_menu;
	m_game_settings_ptr = &game_settings;
	HelloText.setFont(System::resources.font.common);
	HelloText.setString("TOXIMAN!");
	HelloText.setCharacterSize(120);
	HelloText.setFillColor(Color::Magenta);
	System::CenteringText(HelloText);
	HelloText.setPosition(v2f(0, -350));

	HelloText.setStyle(sf::Text::Bold);

	PNG& t_button = System::resources.texture.menu_button;

	vec_button.push_back(make_unique<UI::Button>(System::CreateShape(v2f(0, -225), v2f(200, 50), t_button), "Start"/*, *m_game_settings_ptr*/));
	vec_button.push_back(make_unique<UI::Button>(System::CreateShape(v2f(0, -150), v2f(200, 50), t_button), "Options"/*, *m_game_settings_ptr*/));
	vec_button.push_back(make_unique<UI::Button>(System::CreateShape(v2f(0, -75), v2f(200, 50), t_button), "Exit"/*, *m_game_settings_ptr*/));
}

void MainMenu::Update()
{
	for (auto& button : vec_button)
		button->Update();
}

void MainMenu::Draw()
{
	System::wnd.draw(HelloText);
	for (auto& button : vec_button)
		button->Draw();
}

void MainMenu::Action()
{
	for (auto& button : vec_button)
	{
		if (button->IsAction())
		{
			cout << button->GetNameId() << endl;
			if (button->GetNameId() == "Start") *m_state_game_ptr = StateGame::ON_GAME;
			if (button->GetNameId() == "Options") *m_state_main_menu_ptr = StateMainMenu::ON_OPTIONS;
			if (button->GetNameId() == "Exit") *m_state_main_menu_ptr = StateMainMenu::ON_EXIT;
		}
	}
}

MainMenu::~MainMenu()
{
}
