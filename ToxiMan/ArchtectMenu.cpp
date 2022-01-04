#include "ArchtectMenu.h"

ArchtectMenu::ArchtectMenu(Map& map,GameSettings& game_settings, ArcitectVector& Z_vec) // 1/4 //
{
	ptr_game_settings = &game_settings;
	m_map_ptr = &map;
	m_ptr_Z_vec = &Z_vec;

	archMenu.reset(sf::FloatRect(0.0f, 0.0f, static_cast<float>(System::scr_w), static_cast<float>(System::scr_h)));
	archMenu.setCenter(static_cast<float>(-System::scr_w) / 4.0f,0.0f);

	m_menu = System::CreateShape(v2f(0.0f, 0.0f), v2f(static_cast<float>(System::scr_w) / 4.0f, static_cast<float>(System::scr_h)), Color::Yellow);
	m_menu.setPosition(-m_menu.getSize().x * 2.5f , 0);

	m_main_text = System::CreateText(v2f(m_menu.getPosition().x , -500), 30, "ArchitectMode:", System::resources.font.common, Color::Black);
	System::CenteringText(m_main_text);
	m_name_vector_text = System::CreateText(v2f(m_menu.getPosition().x, -450), 20, "Vector Zero", System::resources.font.common, Color::Black);
	System::CenteringText(m_name_vector_text);

	vec_button.push_back(make_unique<UI::Button>(System::CreateShape(v2f(m_menu.getPosition().x -150, -400), v2f(120, 50), System::resources.texture.menu_button), "V_BACK", game_settings));
	vec_button.push_back(make_unique<UI::Button>(System::CreateShape(v2f(m_menu.getPosition().x, -400), v2f(120, 50), System::resources.texture.menu_button), "V_ZERO", game_settings));
	vec_button.push_back(make_unique<UI::Button>(System::CreateShape(v2f(m_menu.getPosition().x + 150, -400), v2f(120, 50), System::resources.texture.menu_button), "V_FRONT", game_settings));

	vec_button.push_back(make_unique<UI::Button>(System::CreateShape(v2f(m_menu.getPosition().x , -325), v2f(440, 50), System::resources.texture.menu_button), "enable grid", game_settings));

	
	//	MapEditor

	PozMenu = v2f(
		-m_menu.getSize().x * 2.5f,
		0
	);
	SizeMenu = v2f(
		static_cast<float>(System::scr_w) / 4.0f, 
		static_cast<float>(System::scr_h)
	);

	System::resources.texture.LoadMapEditor();

	//1
	m_Map = System::CreateShape(PozMenu, SizeMenu, System::resources.texture.menu_Map);
	m_MapLoad = System::CreateShape(PozMenu, SizeMenu, System::resources.texture.menu_MapLoad);
	m_MapSize = System::CreateShape(PozMenu, SizeMenu, System::resources.texture.menu_MapSize);
	//
	m_Enemy = System::CreateShape(PozMenu,SizeMenu, System::resources.texture.menu_Enemy);
	m_Platforms = System::CreateShape(PozMenu, SizeMenu, System::resources.texture.menu_Platforms);
	m_Player = System::CreateShape(PozMenu, SizeMenu, System::resources.texture.menu_Player);

	m_StaticCube = System::CreateShape(PozMenu, SizeMenu, System::resources.texture.menu_StaticCube);

	//	1   65 80
	MP_Buttons.push_back(make_unique<UI::Button>(System::CreateShape(
		v2f(
			m_menu.getPosition().x - (static_cast<float>(System::scr_w) / 8.0f) + 15 + 32, 
			m_menu.getPosition().y - (static_cast<float>(System::scr_h) / 2.0f) + 158 + 40
		),
		v2f(65, 80),
		System::resources.texture.menu_button),
		"Map",
		game_settings)
	);
	// x 100 246 = 146, y 242 270 = !32 = 15
	MapMenuBattons.push_back(make_unique<UI::Button>(System::CreateShape(
		v2f(
			m_menu.getPosition().x - (static_cast<float>(System::scr_w) / 8.0f) + 100 + 73,
			m_menu.getPosition().y - (static_cast<float>(System::scr_h) / 2.0f) + 242 + 12
		),
		v2f(146, 24),
		System::resources.texture.menu_button),
		"Load",
		game_settings)
	);
	// x 299 444 = 145, y 242 266 = 24
	MapMenuBattons.push_back(make_unique<UI::Button>(System::CreateShape(
		v2f(
			m_menu.getPosition().x - (static_cast<float>(System::scr_w) / 8.0f) + 299 + 73,
			m_menu.getPosition().y - (static_cast<float>(System::scr_h) / 2.0f) + 242 + 12
		),
		v2f(145, 24),
		System::resources.texture.menu_button),
		"Size",
		game_settings)
	);

	//	2   65 80
	MP_Buttons.push_back(make_unique<UI::Button>(System::CreateShape(
		v2f(
			m_menu.getPosition().x - (static_cast<float>(System::scr_w) / 8.0f) + 15 + 32,
			m_menu.getPosition().y - (static_cast<float>(System::scr_h) / 2.0f) + 158 + 40 + 100
		),
		v2f(65, 80),
		System::resources.texture.menu_button),
		"StaticCube",
		game_settings)
	);

	//55 258   120 338   65 80
	MP_Buttons.push_back(make_unique<UI::Button>(System::CreateShape(
		v2f(
			m_menu.getPosition().x - (static_cast<float>(System::scr_w) / 8.0f) + 15 + 32,
			m_menu.getPosition().y - (static_cast<float>(System::scr_h) / 2.0f) + 158 + 40 + 200
		),
		v2f(65, 80),
		System::resources.texture.menu_button),
		"Platforms",
		game_settings)
	);

	//55 258   120 338   65 80
	MP_Buttons.push_back(make_unique<UI::Button>(System::CreateShape(
		v2f(
			m_menu.getPosition().x - (static_cast<float>(System::scr_w) / 8.0f) + 15 + 32,
			m_menu.getPosition().y - (static_cast<float>(System::scr_h) / 2.0f) + 158 + 40 + 300
		),
		v2f(65, 80),
		System::resources.texture.menu_button),
		"Enemy",
		game_settings)
	);

	//55 258   120 338   65 80
	MP_Buttons.push_back(make_unique<UI::Button>(System::CreateShape(
		v2f(
			m_menu.getPosition().x - (static_cast<float>(System::scr_w) / 8.0f) + 15 + 32,
			m_menu.getPosition().y - (static_cast<float>(System::scr_h) / 2.0f) + 158 + 40 + 400
		),
		v2f(65, 80),
		System::resources.texture.menu_button),
		"Player",
		game_settings)
	);


	// nameMap
	vec_textbox.push_back(make_unique<UI::TextBox>(v2f(m_menu.getPosition().x, -250), v2f(200, 30), "MapName", m_map_ptr->GetName()));
	// sizeMap
	vec_textboxInt.push_back(make_unique<UI::TextBoxInt>(v2f(m_menu.getPosition().x - 100, -200), v2f(100, 50), "sizeMapX", to_string(m_map_ptr->GetMapSize().x)));
	vec_textboxInt.push_back(make_unique<UI::TextBoxInt>(v2f(m_menu.getPosition().x + 100, -200), v2f(100, 50), "sizeMapY", to_string(m_map_ptr->GetMapSize().y)));
	// apply map
	vec_button.push_back(make_unique<UI::Button>(System::CreateShape(
		v2f(m_menu.getPosition().x, 0),
		v2f(200, 50),
		System::resources.texture.menu_button),
		"NextMap",
		game_settings));


	vec_button.push_back(make_unique<UI::Button>(System::CreateShape(
		v2f(m_menu.getPosition().x, 100), 
		v2f(200, 50), 
		System::resources.texture.menu_button), 
		"CreateStart", 
		game_settings));

	vec_button.push_back(make_unique<UI::Button>(System::CreateShape(
		v2f(m_menu.getPosition().x, 200), 
		v2f(200, 50), 
		System::resources.texture.menu_button), 
		"CreateFinish", 
		game_settings));

	vec_button.push_back(make_unique<UI::Button>(System::CreateShape(
		v2f(m_menu.getPosition().x, 300),
		v2f(200, 50),
		System::resources.texture.menu_button),
		"SaveMap",
		game_settings));



	vec_button.push_back(make_unique<UI::Button>(System::CreateShape(
		v2f(m_menu.getPosition().x, 400), 
		v2f(440, 50), 
		System::resources.texture.menu_button), 
		"BACK", 
		game_settings));
}

void ArchtectMenu::Action(

	bool& is_grid,

	bool& is_new_start,
	bool& is_new_finish,
	bool& is_save_map,

	bool& is_back,

	bool& is_Next_Level
)
{

	for (auto& button : vec_button)
	{
		if (!is_new_start && !is_new_finish && button->IsAction())
		{
			bool is_rename = false;

			//if (button->GetNameId() == "V_BACK")										
			//	*m_ptr_Z_vec = ArcitectVector::BECK;
			//
			//if (button->GetNameId() == "V_ZERO")							
			//	*m_ptr_Z_vec = ArcitectVector::ZERO;
			//
			//if (button->GetNameId() == "V_FRONT")							
			//	*m_ptr_Z_vec = ArcitectVector::FRONT;
			//
			//if (button->GetNameId() == "enable grid") {
			//	is_rename = true;
			//	is_grid = !is_grid;
			//	button->SetNameID("disable grid");
			//}

			//if (button->GetNameId() == "disable grid" && is_rename == false) {
			//	is_grid = !is_grid;
			//	button->SetNameID("enable grid");
			//}


			//if (button->GetNameId() == "NextMap") {
			//	GameSettings::SetGameLevels(GameSettings::GetGemeLevels() + 1);
			//	ptr_game_settings->SaveSettings();
			//	is_Next_Level = true;
			//	cout << "NextMap" << endl;				
			//}

			///// ///

			//if (button->GetNameId() == "CreateStart" ) {

			//	cout << "Create_Start_achc_menu!" << endl;
			//	is_new_start = true;
			//	
			//}

			//if (button->GetNameId() == "CreateFinish" ) {

			//	cout << "Create_Finisht_achc_menu!" << endl;
			//	is_new_finish = true;

			//}

			//if (button->GetNameId() == "SaveMap") {

			//	is_save_map = true;

			//	m_map_ptr->SetName(vec_textbox[0].get()->GetData());

			//	v2i newSize = v2i(
			//		stoi(vec_textboxInt[0].get()->GetData()),
			//		stoi(vec_textboxInt[1].get()->GetData())
			//	);

			//	m_map_ptr->SetMapSize(newSize);

			//}

			if (button->GetNameId() == "BACK") {
				cout << "BACK_achc_menu!" << endl;
				is_back = true;
			}

		}
	}


	// MapEditor
	for (auto& button : MP_Buttons)
	{
		if (button->IsAction()) {
			if (button->GetNameId() == "Map") {
				MAP_EDITOR = MapEditor::MAP;
				cout << "SizeMap" << endl;
				cout << to_string((int)MAP_EDITOR) << endl;
			}


			if (button->GetNameId() == "StaticCube") {
				MAP_EDITOR = MapEditor::STATIC_CUBE;
				cout << "StaticCube" << endl;
				cout << to_string((int)MAP_EDITOR) << endl;
			}


			if (button->GetNameId() == "Platforms"){
				MAP_EDITOR = MapEditor::PLATFORMS;
				cout << "Platforms" << endl;
				cout << to_string((int)MAP_EDITOR) << endl;
			}

			if (button->GetNameId() == "Enemy") {
				MAP_EDITOR = MapEditor::ENEMY;
				cout << "Enemy" << endl;
				cout << to_string((int)MAP_EDITOR) << endl;
			}


			if (button->GetNameId() == "Player") {
				MAP_EDITOR = MapEditor::PLAYER;
				cout << "Player" << endl;
				cout << to_string((int)MAP_EDITOR) << endl;
			}

		}
	}

	switch (MAP_EDITOR)
	{
	case ArchtectMenu::MapEditor::MAP:
		for (auto& button : MapMenuBattons)
		{
			if (button->IsAction()) {
				if (button->GetNameId() == "Load") {
					Map_Manu = MapMenu::LOAD;
					cout << "Load" << endl;
				}
				if (button->GetNameId() == "Size") {
					Map_Manu = MapMenu::SIZE;
					cout << "Size" << endl;
				}
			}
		}
		break;
	case ArchtectMenu::MapEditor::ENEMY:
		break;
	case ArchtectMenu::MapEditor::PLATFORMS:
		break;
	case ArchtectMenu::MapEditor::PLAYER:
		break;
	case ArchtectMenu::MapEditor::STATIC_CUBE:
		break;
	default:
		break;
	}

	for (auto& textbox : vec_textbox)
		textbox->Action();
	for (auto& textbox : vec_textboxInt)
		textbox->Action();
}

void ArchtectMenu::Update()
{
	m_map_ptr->GetName();

	for (auto& button : MP_Buttons)
		button->Update();
	switch (MAP_EDITOR)
	{
	case ArchtectMenu::MapEditor::MAP:
		for (auto& button : MapMenuBattons)
			button->Update();
		break;
	case ArchtectMenu::MapEditor::ENEMY:
		break;
	case ArchtectMenu::MapEditor::PLATFORMS:
		break;
	case ArchtectMenu::MapEditor::PLAYER:
		break;
	case ArchtectMenu::MapEditor::STATIC_CUBE:
		break;
	default:
		break;
	}
	for (auto& button : vec_button)
		button->Update();

	switch (*m_ptr_Z_vec)
	{
	case ArcitectVector::BECK:
		m_name_vector_text.setString("Vector Back");
		break;
	case ArcitectVector::ZERO:
		m_name_vector_text.setString("Vector Zero");
		break;
	case ArcitectVector::FRONT:
		m_name_vector_text.setString("Vector Front");
		break;
	default:
		break;
	}

	for (auto& textbox : vec_textbox)
		textbox->Update();
	for (auto& textbox : vec_textboxInt)
		textbox->Update();


}

void ArchtectMenu::Draw()
{
	System::wnd.setView(archMenu);


	switch (MAP_EDITOR)
	{
	case ArchtectMenu::MapEditor::ENEMY:
		System::wnd.draw(m_Enemy);
		//for (auto& button : MP_Buttons)
		//	button->Draw();
		break;
	case ArchtectMenu::MapEditor::PLATFORMS:
		System::wnd.draw(m_Platforms);
		//for (auto& button : MP_Buttons)
		//	button->Draw();
		break;
	case ArchtectMenu::MapEditor::PLAYER:
		System::wnd.draw(m_Player);
		//for (auto& button : MP_Buttons)
		//	button->Draw();
		break;
	case ArchtectMenu::MapEditor::MAP:
		System::wnd.draw(m_Map);
		switch (Map_Manu)
		{
		case ArchtectMenu::MapMenu::LOAD:
			System::wnd.draw(m_MapLoad);
			//for (auto& button : MapMenuBattons)
			//	button->Draw();
			break;
		case ArchtectMenu::MapMenu::SIZE:
			System::wnd.draw(m_MapSize);
			//for (auto& button : MapMenuBattons)
			//	button->Draw();
			break;
		default:
			break;
		}
		//for (auto& button : MP_Buttons)
		//	button->Draw();
		break;
	case ArchtectMenu::MapEditor::STATIC_CUBE:
		System::wnd.draw(m_StaticCube);
		//for (auto& button : MP_Buttons)
		//	button->Draw();
		break;
	default:
		break;
	}

	//System::wnd.draw(m_menu);
	//System::wnd.draw(m_main_text);
	//System::wnd.draw(m_name_vector_text);


	//for (auto& button : vec_button)
	//	button->Draw();

	//for (auto& textbox : vec_textbox)
	//	textbox->Draw();
	//for (auto& textbox : vec_textboxInt)
	//	textbox->Draw();

	System::wnd.setView(System::cam);
}

Shape* ArchtectMenu::GetSnape()
{
	return &m_menu;
}

ArchtectMenu::~ArchtectMenu()
{
}
