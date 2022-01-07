#include "ArchtectMenu.h"

ArchtectMenu::ArchtectMenu(std::map<UINT32, Level>& Levels, ArcitectVector& Z_vec) // 1/4 //
{
	m_Levels = &Levels;


	m_ptr_Z_vec = &Z_vec;

	archMenu.reset(sf::FloatRect(0.0f, 0.0f, static_cast<float>(System::scr_w), static_cast<float>(System::scr_h)));
	archMenu.setCenter(static_cast<float>(-System::scr_w) / 4.0f,0.0f);

	m_menu = System::CreateShape(v2f(0.0f, 0.0f), v2f(static_cast<float>(System::scr_w) / 4.0f, static_cast<float>(System::scr_h)), Color::Yellow);
	m_menu.setPosition(-m_menu.getSize().x * 2.5f , 0);

	m_main_text = System::CreateText(v2f(m_menu.getPosition().x , -500), 30, "ArchitectMode:", System::resources.font.common, Color::Black);
	System::CenteringText(m_main_text);
	m_name_vector_text = System::CreateText(v2f(m_menu.getPosition().x, -450), 20, "Vector Zero", System::resources.font.common, Color::Black);
	System::CenteringText(m_name_vector_text);

	vec_button.push_back(make_unique<UI::Button>(System::CreateShape(v2f(m_menu.getPosition().x -150, -400), v2f(120, 50), System::resources.texture.menu_button), "V_BACK"));
	vec_button.push_back(make_unique<UI::Button>(System::CreateShape(v2f(m_menu.getPosition().x, -400), v2f(120, 50), System::resources.texture.menu_button), "V_ZERO"));
	vec_button.push_back(make_unique<UI::Button>(System::CreateShape(v2f(m_menu.getPosition().x + 150, -400), v2f(120, 50), System::resources.texture.menu_button), "V_FRONT"));

	vec_button.push_back(make_unique<UI::Button>(System::CreateShape(v2f(m_menu.getPosition().x , -325), v2f(440, 50), System::resources.texture.menu_button), "enable grid"));

	
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
	CreateNewMapButton = make_unique<UI::Button>(System::CreateShape(
		v2f(
			m_menu.getPosition().x - (static_cast<float>(System::scr_w) / 8.0f) + 270,
			m_menu.getPosition().y - (static_cast<float>(System::scr_h) / 2.0f) + 320
		), 
		v2f(333, 50), 
		System::resources.texture.menu_button), 
		"Create New Map" 
	);



	for (Uint32 i = 0; i <= GameSettings::GetGemeLevels(); i++)
	{
		LoadBoards.push_back(make_unique<LoadBoard>(
			m_Levels->find(i)->second.m_Map.GetName(),
			v2f(
				m_menu.getPosition().x - (static_cast<float>(System::scr_w) / 8.0f) + 105,
				m_menu.getPosition().y - (static_cast<float>(System::scr_h) / 2.0f) + 350 + (i * 125)
			))
		);
	}


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
		"Map")
	);
	// x 100 246 = 146, y 242 270 = !32 = 15
	MapMenuBattons.push_back(make_unique<UI::Button>(System::CreateShape(
		v2f(
			m_menu.getPosition().x - (static_cast<float>(System::scr_w) / 8.0f) + 100 + 73,
			m_menu.getPosition().y - (static_cast<float>(System::scr_h) / 2.0f) + 242 + 12
		),
		v2f(146, 24),
		System::resources.texture.menu_button),
		"Load")
	);
	// x 299 444 = 145, y 242 266 = 24
	MapMenuBattons.push_back(make_unique<UI::Button>(System::CreateShape(
		v2f(
			m_menu.getPosition().x - (static_cast<float>(System::scr_w) / 8.0f) + 299 + 73,
			m_menu.getPosition().y - (static_cast<float>(System::scr_h) / 2.0f) + 242 + 12
		),
		v2f(145, 24),
		System::resources.texture.menu_button),
		"Size")
	);

	//	2   65 80
	MP_Buttons.push_back(make_unique<UI::Button>(System::CreateShape(
		v2f(
			m_menu.getPosition().x - (static_cast<float>(System::scr_w) / 8.0f) + 15 + 32,
			m_menu.getPosition().y - (static_cast<float>(System::scr_h) / 2.0f) + 158 + 40 + 100
		),
		v2f(65, 80),
		System::resources.texture.menu_button),
		"StaticCube")
	);

	//55 258   120 338   65 80
	MP_Buttons.push_back(make_unique<UI::Button>(System::CreateShape(
		v2f(
			m_menu.getPosition().x - (static_cast<float>(System::scr_w) / 8.0f) + 15 + 32,
			m_menu.getPosition().y - (static_cast<float>(System::scr_h) / 2.0f) + 158 + 40 + 200
		),
		v2f(65, 80),
		System::resources.texture.menu_button),
		"Platforms")
	);

	//55 258   120 338   65 80
	MP_Buttons.push_back(make_unique<UI::Button>(System::CreateShape(
		v2f(
			m_menu.getPosition().x - (static_cast<float>(System::scr_w) / 8.0f) + 15 + 32,
			m_menu.getPosition().y - (static_cast<float>(System::scr_h) / 2.0f) + 158 + 40 + 300
		),
		v2f(65, 80),
		System::resources.texture.menu_button),
		"Enemy")
	);

	//55 258   120 338   65 80
	MP_Buttons.push_back(make_unique<UI::Button>(System::CreateShape(
		v2f(
			m_menu.getPosition().x - (static_cast<float>(System::scr_w) / 8.0f) + 15 + 32,
			m_menu.getPosition().y - (static_cast<float>(System::scr_h) / 2.0f) + 158 + 40 + 400
		),
		v2f(65, 80),
		System::resources.texture.menu_button),
		"Player")
	);


	//// nameMap
	//vec_textbox.push_back(make_unique<UI::TextBox>(v2f(m_menu.getPosition().x, -250), v2f(200, 30), "MapName", m_map_ptr->GetName()));
	//// sizeMap
	//vec_textboxInt.push_back(make_unique<UI::TextBoxInt>(v2f(m_menu.getPosition().x - 100, -200), v2f(100, 50), "sizeMapX", to_string(m_map_ptr->GetMapSize().x)));
	//vec_textboxInt.push_back(make_unique<UI::TextBoxInt>(v2f(m_menu.getPosition().x + 100, -200), v2f(100, 50), "sizeMapY", to_string(m_map_ptr->GetMapSize().y)));
	//// apply map
	//vec_button.push_back(make_unique<UI::Button>(System::CreateShape(
	//	v2f(m_menu.getPosition().x, 0),
	//	v2f(200, 50),
	//	System::resources.texture.menu_button),
	//	"NextMap"));


	//vec_button.push_back(make_unique<UI::Button>(System::CreateShape(
	//	v2f(m_menu.getPosition().x, 100), 
	//	v2f(200, 50), 
	//	System::resources.texture.menu_button), 
	//	"CreateStart"));

	//vec_button.push_back(make_unique<UI::Button>(System::CreateShape(
	//	v2f(m_menu.getPosition().x, 200), 
	//	v2f(200, 50), 
	//	System::resources.texture.menu_button), 
	//	"CreateFinish"));

	//vec_button.push_back(make_unique<UI::Button>(System::CreateShape(
	//	v2f(m_menu.getPosition().x, 300),
	//	v2f(200, 50),
	//	System::resources.texture.menu_button),
	//	"SaveMap"));



	BackButton = make_unique<UI::Button>(System::CreateShape(
		v2f(
			m_menu.getPosition().x - (static_cast<float>(System::scr_w) / 8.0f) + 270,
			m_menu.getPosition().y - (static_cast<float>(System::scr_h) / 2.0f) + 1000
		),
		v2f(333, 50),
		System::resources.texture.menu_button), 
		"BACK");
}

void ArchtectMenu::Action(


	bool& is_grid,

	bool& is_new_start,
	bool& is_new_finish,
	bool& is_save_map,

	bool& is_back

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



		switch (Map_Manu)
		{
		case ArchtectMenu::MapMenu::LOAD:

			for (auto& loadbord : LoadBoards) {
				loadbord->Action(*m_Levels, is_load, is_save, is_delete);
				if (is_load) {

				}
				if (is_save) {

				}
				if (is_delete) {
					id_for_del = loadbord->GetId();
					//break;
				}
			}
			//if (is_delete) {
			//	auto it = LoadBoards.begin() + id_for_del;
			//	LoadBoards.erase(it);
			//	for (it; it != LoadBoards.end(); it++)
			//		it->get()->NewId();
			//	is_delete = false;
			//}

			if (CreateNewMapButton->IsAction()) {
				cout << "CreateNewMapButton" << endl;
				//GameStates::gs = GameStates::GS::NEW_LEVEL;


				if(!m_Levels->empty())
					GameSettings::SetGameLevels(GameSettings::GetGemeLevels() + 1);
				GameSettings::SaveSettings();

				Level tLevel;
				Map temp = jsonSM.LoadMap("New", GameSettings::GetGemeLevels());
				jsonSM.SaveMap("Save/MAP.json", temp, GameSettings::GetGemeLevels());


				LoadBoards.push_back(make_unique<LoadBoard>(
					temp.GetName(),
					v2f(
						m_menu.getPosition().x - (static_cast<float>(System::scr_w) / 8.0f) + 105,
						m_menu.getPosition().y - (static_cast<float>(System::scr_h) / 2.0f) + 350 + (LoadBoards.size() * 125)
					))
				);
				tLevel.m_Map = temp;
				m_Levels->insert(pair<uint32,Level>(GameSettings::GetGemeLevels(), tLevel));

				cout << "MAPS.SIZE: " << m_Levels->size() << endl;
				for (auto& key : *m_Levels)
					cout << "key " << key.first << endl;
			}
			break;
		case ArchtectMenu::MapMenu::SIZE:
			break;
		default:
			break;
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

	//for (auto& textbox : vec_textbox)
	//	textbox->Action();
	//for (auto& textbox : vec_textboxInt)
	//	textbox->Action();

	if (BackButton->IsAction()) {
		g_StateMainMenu = StateMainMenu::ON_MAIN;
	}
}

void ArchtectMenu::Update()
{


	for (auto it = LoadBoards.begin(); it != LoadBoards.end(); ) {
		auto& loadbord = it;
		if (loadbord->get()->CheckDel()) {
			it = LoadBoards.erase(it);
		}
		else {
			it++;
		}
	}

	if (is_delete)
	{
		LoadBoard::id--;
		if (GameSettings::GetGemeLevels() != 0)
			GameSettings::SetGameLevels(GameSettings::GetGemeLevels() - 1);
		GameSettings::SaveSettings();



		jsonSM.DeleteJsonFile("maps/map_", id_for_del);
		cout << "DELETE: " << id_for_del << endl;

		for (uint32 i = id_for_del; (i < LoadBoards.size() - 1) && !LoadBoards.empty(); i++)
		{
			Map tempMap = jsonSM.LoadMap("", i + 1);
			cout << "Load: " << i << endl;
			jsonSM.SaveMap("", tempMap, i);
			cout << "Save: " << i << endl;
			jsonSM.DeleteJsonFile("maps/map_", i + 1);
		}

		//jsonSM.DeleteJsonFile("maps/map_", LoadBoards.size());
		//cout << "DELETE: " << LoadBoards.size() << endl;

		cout << "m_Levels.SIZE: " << m_Levels->size() << endl;

		for (uint32 i = id_for_del; i < m_Levels->size() - 1; i++)
		{
			cout << "SWAP: " << i << endl;

			auto it = m_Levels->find(i);

			it->second.m_Map = m_Levels->find(i + 1)->second.m_Map;

			cout << "SWAP: " << "OK" << endl;
		}

		cout << "SWAP: " << "  OK" << endl;

		m_Levels->erase(--m_Levels->end());

		cout << "m_Levels.SIZE: " << m_Levels->size() << endl;

		for (auto& key : *m_Levels)
			cout << "key " << key.first << endl;

		is_delete = false;
	}




	for (auto& button : MP_Buttons)
		button->Update();
	switch (MAP_EDITOR)
	{
	case ArchtectMenu::MapEditor::MAP:
		for (auto& button : MapMenuBattons)
			button->Update();
		switch (Map_Manu)
		{
		case ArchtectMenu::MapMenu::LOAD:
			System::wnd.draw(m_MapLoad);

			for (Uint32 i = 0; i < LoadBoards.size(); i++)
			{
				LoadBoards[i]->SetPosition(
					v2f(
						m_menu.getPosition().x - (static_cast<float>(System::scr_w) / 8.0f) + 105,
						m_menu.getPosition().y - (static_cast<float>(System::scr_h) / 2.0f) + 350 + (i * 125)
					));
				LoadBoards[i]->NewId(i);
			}

			for (auto& loadbord : LoadBoards)
				loadbord->Update();
			CreateNewMapButton->Update();
			break;
		case ArchtectMenu::MapMenu::SIZE:
			break;
		default:
			break;
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

	BackButton->Update();
}

void ArchtectMenu::Draw()
{
	if (!m_Levels->empty())
		System::wnd.draw(System::CreateShape(v2f(0, 0), v2f(500, 500)));

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
			for (auto& loadbord : LoadBoards)
				loadbord->Draw();
			CreateNewMapButton->Draw();
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
	BackButton->Draw();

	System::wnd.setView(System::cam);
}

Shape* ArchtectMenu::GetSnape()
{
	return &m_menu;
}

ArchtectMenu::~ArchtectMenu()
{
}
