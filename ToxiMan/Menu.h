#pragma once
#include "System.h"
#include "MainMenu.h"
#include "OptionsMenu.h"
#include "ExitMenu.h"

// Основное главное меню, которое появляется при каждом запуске игры.

class Menu
{
private:

	StateMainMenu m_state;						// Состояние главного меню
	StateGame* m_state_game_ptr;				// Указатель на основное состояние игры
	unique_ptr<MainMenu> m_main_menu;			// Набор для управления в главном меню
	unique_ptr<OptionsMenu> m_options_menu;		// Набор управления в меню настроек
	unique_ptr<ExitMenu> m_exit_menu;			// Вы правда очень сильно хотите выйти?
	Shape m_shape_back_ground;					// Фон главного меню

	GameSettings* m_game_settings_ptr;			// Указатель на настройки

public:

	Menu(StateGame& state_game, GameSettings& game_settings);
	void Update();
	void Draw();
	void Action();

	~Menu();

};
