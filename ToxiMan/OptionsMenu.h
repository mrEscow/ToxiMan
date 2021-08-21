#pragma once
#include "System.h"
#include "GameStates.h"
#include "GameSettings.h" // статические пол€ в одном экземпл€ре на всю игру.
#include "Button.h"
#include "CheckBox.h"
#include "Scroll.h"



class OptionsMenu
{
private:

	vector<unique_ptr<UI::Button>> vec_button;
	vector<unique_ptr<UI::CheckBox>> vec_checkbox;
	vector<unique_ptr<UI::Scroll>> vec_scroll;

	StateMainMenu* m_state_main_menu_ptr;		// ”казатель на основное состо€ние главного меню

	GameSettings* m_game_settings_ptr;
	PNG t_checkbox;

	sf::Text text_options;
	//----------------------------------------------------------------------------------
	float size_checkbox = 50; // размер чекбокса и скрола
	v2f size_checkbox_xy = v2f(size_checkbox, size_checkbox);

	float poz_checkbox_x = -100; // позици€ первого чекбокса относительно оси х
	float poz_checkbox_y = -150; // позици€ первого чекбокса относительно оси н

	float distance_factor = 1.5; // коэфицент удалени€ следкющего чекбокса от предыдущего 
	float DF = distance_factor;

	float length_scroll = size_checkbox * 6;
	float height_scroll = length_scroll / 6;
	v2f size_scroll = v2f(length_scroll, height_scroll);
	v2f size_scroll2 = v2f(length_scroll / 6, height_scroll);

	float poz_skroll_x = poz_checkbox_x + (size_checkbox * 4);
	float poz_skroll_y = poz_checkbox_y;

public:

	OptionsMenu(StateMainMenu&, GameSettings& m_game_settings);
	void Update(StateGame& state_game);
	void Action();
	void Draw();
	~OptionsMenu();
};

