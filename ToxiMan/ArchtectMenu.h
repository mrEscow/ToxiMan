#pragma once
#include "System.h"
#include "GameStates.h"
#include "Button.h"

class ArchtectMenu
{
private:
	StateGame m_state_game_ptr;
	ArcitectVector * m_ptr_Z_vec;
	sf::View archMenu;
	Shape	m_menu;
	Text	m_main_text;
	Text	m_name_vector_text;


	
	vector<unique_ptr<UI::Button>> vec_button;


public:
	ArchtectMenu(GameSettings& game_settings, ArcitectVector& Z_vec);
	void Action(bool &is_grid, bool& is_back);
	void Update(float zoom);
	void Draw();
	Shape* GetSnape();
	~ArchtectMenu();
};

