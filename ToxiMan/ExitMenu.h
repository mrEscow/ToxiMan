#pragma once
#include "GameStates.h"
#include "Button.h"
class ExitMenu
{
private:

	vector<unique_ptr<UI::Button>> vec_button;
	sf::Text text_exit;

public:

	ExitMenu();
	void Update();
	void Draw();
	void Action();
	~ExitMenu();
};

