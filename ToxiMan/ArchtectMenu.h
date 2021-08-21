#pragma once
#include "System.h"
#include "GameStates.h"
#include "Button.h"

class ArchtectMenu
{
private:
	sf::View archMenu;
	Shape	m_menu;
	Text	m_main_text;
	Text	m_name_vector_text;


	
	vector<unique_ptr<UI::Button>> vec_button;


public:
	ArchtectMenu(GameSettings& game_settings);
	void Action();
	void Update(ArcitectVector &m_Z_vec, StateGame& state_game);
	void Draw();
	~ArchtectMenu();
};

