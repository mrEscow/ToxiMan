#pragma once
#include "System.h"
#include "GameStates.h"
#include "Button.h"
#include "TextBox.h"
#include "GameSettings.h"

class MainMenu
{

private:

	vector<unique_ptr<UI::Button>> vec_button;

	StateGame* m_state_game_ptr;			// ”казатель на основное состо€ние игры
	StateMainMenu* m_state_main_menu_ptr;	// ”казатель на основное состо€ние главного меню
	GameSettings* m_game_settings_ptr;

	sf::Text HelloText;

	vector<unique_ptr<UI::TextBox>> vec_textbox;

public:

	MainMenu(StateGame&, StateMainMenu&, GameSettings&);
	void Update();
	void Draw();
	void Action();
	~MainMenu();


};


