#pragma once
#include "System.h"
#include "GameStates.h"
#include "Button.h"
#include "GameSettings.h"

class MainMenu
{

private:

	vector<unique_ptr<UI::Button>> vec_button;

	StateGame* m_state_game_ptr;			// ”казатель на основное состо€ние игры

	sf::Text HelloText;

public:
	MainMenu(StateGame&);
	void Update();
	void Draw();
	void Action();
	~MainMenu();
};


