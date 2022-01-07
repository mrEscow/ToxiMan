#pragma once
#include "System.h"
#include "GameStates.h"
#include "Button.h"
#include "GameSettings.h"

class MainMenu
{

private:

	vector<unique_ptr<UI::Button>> vec_button;
	sf::Text HelloText;

public:
	MainMenu();
	void Update();
	void Draw();
	void Action();
	~MainMenu();
};


