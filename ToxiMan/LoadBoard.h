#pragma once

#include "Button.h"
#include "TextBox.h"
#include "System.h"

class LoadBoard
{
	string name;
	v2f pos;
	v2f size;
	Shape shape;
	vector<unique_ptr<UI::Button>> buttons;
	unique_ptr<UI::TextBox> textbox;
public:
	LoadBoard(GameSettings& game_settings,string name, v2f pos);
	void Action();
	void Update();
	void Draw();
};

