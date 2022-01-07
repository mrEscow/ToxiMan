#pragma once
#include "System.h"
#include "World.h"

#include "MainMenu.h"
#include "LevelEditor.h"
#include "OptionsMenu.h"
#include "ExitMenu.h"

// Основное главное меню, которое появляется при каждом запуске игры.

class Menu
{
private:

	StateMainMenu m_state;						// Состояние главного меню
	StateGame* m_state_game_ptr;				// Указатель на основное состояние игры
	unique_ptr<MainMenu> m_main_menu;			// Набор для управления в главном меню
	unique_ptr<LevelEditor> m_level_editor;		// Создатель уровней
	unique_ptr<OptionsMenu> m_options_menu;		// Набор управления в меню настроек
	unique_ptr<ExitMenu> m_exit_menu;			// Вы правда очень сильно хотите выйти?
	Shape m_menu_back_ground;					// Фон главного меню

public:

	Menu(StateGame& state_game);
	void Update();
	void Draw();
	void Action();

	~Menu();

};
