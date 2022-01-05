#pragma once

#include "Button.h"
#include "TextBox.h"
#include "System.h"

class LoadBoard
{
	uint32 m_id;
	string name;
	v2f pos;
	v2f size;
	Shape shape;
	vector<unique_ptr<UI::Button>> buttons;
	unique_ptr<UI::TextBox> textbox;
	bool is_delete{ false };
public:
	static uint32 id;
	LoadBoard(string name, v2f pos);
	void Action(bool& is_load, bool& is_save, bool& is_delete);
	void Update();
	void Draw();

	uint GetId();
	void NewId();
	bool CheckDel();
};

