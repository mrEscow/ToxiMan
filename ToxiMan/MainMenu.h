#pragma once
#include "System.h"
#include "GameStates.h"
#include "Button.h"
#include "GameSettings.h"

class MainMenu
{

private:

	vector<unique_ptr<UI::Button>> vec_button;

	StateGame* m_state_game_ptr;			// ��������� �� �������� ��������� ����
	StateMainMenu* m_state_main_menu_ptr;	// ��������� �� �������� ��������� �������� ����

	sf::Text HelloText;

public:
	MainMenu(StateGame&, StateMainMenu&);
	void Update();
	void Draw();
	void Action();
	~MainMenu();
};


