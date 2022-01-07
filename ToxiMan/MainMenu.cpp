#include "MainMenu.h"

MainMenu::MainMenu(StateGame& state_game)
{
	m_state_game_ptr = &state_game;

	HelloText.setFont(System::resources.font.common);
	HelloText.setString("TOXIMAN!");
	HelloText.setCharacterSize(120);
	HelloText.setFillColor(Color::Magenta);
	System::CenteringText(HelloText);
	HelloText.setPosition(v2f(0, -350));

	HelloText.setStyle(sf::Text::Bold);

	PNG& t_button = System::resources.texture.menu_button;

	vec_button.push_back(make_unique<UI::Button>(System::CreateShape(v2f(0, -225),	v2f(200, 50),		t_button), "Start"));
	vec_button.push_back(make_unique<UI::Button>(System::CreateShape(v2f(0, -150),	v2f(200, 50),		t_button), "MapEditor"));
	vec_button.push_back(make_unique<UI::Button>(System::CreateShape(v2f(0, -75),	v2f(200, 50),		t_button), "Options"));
	vec_button.push_back(make_unique<UI::Button>(System::CreateShape(v2f(0, 0),		v2f(200, 50),		t_button), "Exit"));
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

			if (button->GetNameId() == "MapEditor")	g_StateMainMenu = StateMainMenu::ON_LEVEL_EDITOR;
			if (button->GetNameId() == "Options")	g_StateMainMenu = StateMainMenu::ON_OPTIONS;
			if (button->GetNameId() == "Exit")		g_StateMainMenu = StateMainMenu::ON_EXIT;
		}
	}
}

MainMenu::~MainMenu()
{
}