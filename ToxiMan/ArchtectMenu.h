#pragma once
#include "System.h"
#include "GameStates.h"
#include "Button.h"
#include "TextBox.h"
#include "Map.h"
#include "LoadBoard.h"
#include "JsonSaveMenager.h"
#include "Level.h"

class ArchtectMenu 
{
private:
	//std::map<uint32_t, Map>* m_Maps;
	std::map<UINT32, Level>* m_Levels;

	StateGame m_state_game_ptr;

	ArcitectVector * m_ptr_Z_vec;

	sf::View archMenu;

	unique_ptr <UI::Button> BackButton;

	JsonSaveMenager jsonSM;

	// MapEditor

	vector<unique_ptr<UI::Button>> MP_Buttons;

	v2f PozMenu;
	v2f SizeMenu;

	enum class MapEditor : uint {
		MAP,
		ENEMY,
		PLATFORMS,
		PLAYER,
		STATIC_CUBE
	};

	MapEditor MAP_EDITOR = MapEditor::MAP;

	//	1
	vector<unique_ptr<UI::Button>> MapMenuBattons;

	enum class MapMenu : uint {
		LOAD,
		SIZE
	};

	MapMenu Map_Manu = MapMenu::LOAD;

	Shape	m_Map;
	Shape	m_MapLoad;
	Shape	m_MapSize;

	unique_ptr <UI::Button> CreateNewMapButton;

	vector<unique_ptr<LoadBoard>> LoadBoards;

	bool is_save{ 0 };
	bool is_load{ 0 };
	bool is_delete{ 0 };
	uint32 id_for_del;
	//	2
	Shape	m_Enemy;
	Shape	m_Platforms;
	Shape	m_Player;

	Shape	m_StaticCube;



	////////

	Shape	m_menu;

	Text	m_main_text;

	Text	m_name_vector_text;


	//bool m_is_CreateStart = false;
	
	vector<unique_ptr<UI::Button>> vec_button;
	vector<unique_ptr<UI::TextBox>> vec_textbox;
	vector<unique_ptr<UI::TextBoxInt>> vec_textboxInt;

public:
	ArchtectMenu(std::map<UINT32, Level>& Levels, ArcitectVector& Z_vec);
	void Action(

		// Menu buttons

		bool& is_grid, 
 
		bool& is_new_start,
		bool& is_new_finish,
		bool& is_save_map,

		bool& is_back

	);
	void Update();
	void Draw();
	Shape* GetSnape();
	~ArchtectMenu();
};

