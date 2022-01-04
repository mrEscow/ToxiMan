#pragma once
#include "System.h"
#include "GameStates.h"
#include "Button.h"
#include "TextBox.h"
#include "Map.h"

class ArchtectMenu 
{
private:

	StateGame m_state_game_ptr;

	GameSettings* ptr_game_settings;

	ArcitectVector * m_ptr_Z_vec;

	Map *m_map_ptr;

	sf::View archMenu;

	// MapEditor
	v2f PozMenu;
	v2f SizeMenu;

	enum class MapEditor : uint {
		ENEMY,
		PLATFORMS,
		PLAYER,
		SIZY_MAP,
		STATIC_CUBE
	};

	MapEditor MAP_EDITOR = MapEditor::SIZY_MAP;

	Shape	m_Enemy;
	Shape	m_Platforms;
	Shape	m_Player;
	Shape	m_SizeMap;
	Shape	m_StaticCube;

	vector<unique_ptr<UI::Button>> MP_Buttons;

	////////

	Shape	m_menu;

	Text	m_main_text;

	Text	m_name_vector_text;


	//bool m_is_CreateStart = false;
	
	vector<unique_ptr<UI::Button>> vec_button;
	vector<unique_ptr<UI::TextBox>> vec_textbox;
	vector<unique_ptr<UI::TextBoxInt>> vec_textboxInt;

public:
	ArchtectMenu(Map& map,GameSettings& game_settings, ArcitectVector& Z_vec);
	void Action(

		// Menu buttons

		bool& is_grid, 
 
		bool& is_new_start,
		bool& is_new_finish,
		bool& is_save_map,

		bool& is_back,

		bool& is_Next_Level
	);
	void Update();
	void Draw();
	Shape* GetSnape();
	~ArchtectMenu();
};

