#pragma once
#include "System.h"
#include "MainMenu.h"
#include "OptionsMenu.h"
#include "ExitMenu.h"

// �������� ������� ����, ������� ���������� ��� ������ ������� ����.

class Menu
{
private:

	StateMainMenu m_state;						// ��������� �������� ����
	StateGame* m_state_game_ptr;				// ��������� �� �������� ��������� ����
	unique_ptr<MainMenu> m_main_menu;			// ����� ��� ���������� � ������� ����
	unique_ptr<OptionsMenu> m_options_menu;		// ����� ���������� � ���� ��������
	unique_ptr<ExitMenu> m_exit_menu;			// �� ������ ����� ������ ������ �����?
	Shape m_shape_back_ground;					// ��� �������� ����

	GameSettings* m_game_settings_ptr;			// ��������� �� ���������

public:

	Menu(StateGame& state_game, GameSettings& game_settings);
	void Update();
	void Draw();
	void Action();

	~Menu();

};
