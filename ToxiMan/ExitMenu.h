#pragma once
#include "GameStates.h"
#include "Button.h"
class ExitMenu
{
private:

	vector<unique_ptr<UI::Button>> vec_button;
	StateMainMenu* m_state_main_menu_ptr;
	sf::Text text_exit;
	GameSettings* m_game_settings_ptr;

public:

	ExitMenu(StateMainMenu&, GameSettings&);
	void Update();
	void Draw();
	void Action();
	~ExitMenu();
};

