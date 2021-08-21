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
	GameSettings* m_game_settings_ptr;

	sf::Text HelloText;

public:

	MainMenu(StateGame&, StateMainMenu&, GameSettings&);
	void Update();
	void Draw();
	void Action();
	~MainMenu();


};


