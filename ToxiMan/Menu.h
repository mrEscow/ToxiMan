#pragma once
#include "System.h"
#include "World.h"
#include "GameStates.h"
#include "MainMenu.h"
#include "LevelEditor.h"
#include "OptionsMenu.h"
#include "ExitMenu.h"

// �������� ������� ����, ������� ���������� ��� ������ ������� ����.

class Menu
{
private:
	unique_ptr<MainMenu> m_main_menu;			// ����� ��� ���������� � ������� ����
	unique_ptr<LevelEditor> m_level_editor;		// ��������� �������
	unique_ptr<OptionsMenu> m_options_menu;		// ����� ���������� � ���� ��������
	unique_ptr<ExitMenu> m_exit_menu;			// �� ������ ����� ������ ������ �����?
	Shape m_menu_back_ground;					// ��� �������� ����

public:

	Menu();
	void Update();
	void Draw();
	void Action();

	~Menu();

};
