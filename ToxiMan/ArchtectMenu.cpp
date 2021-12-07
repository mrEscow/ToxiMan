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

			if (button->GetNameId() == "V_BACK")										
				*m_ptr_Z_vec = ArcitectVector::BECK;
			
			if (button->GetNameId() == "V_ZERO")							
				*m_ptr_Z_vec = ArcitectVector::ZERO;
			
			if (button->GetNameId() == "V_FRONT")							
				*m_ptr_Z_vec = ArcitectVector::FRONT;
			
			if (button->GetNameId() == "enable grid") {
				is_rename = true;
				is_grid = !is_grid;
				button->SetNameID("disable grid");
			}

			if (button->GetNameId() == "disable grid" && is_rename == false) {
				is_grid = !is_grid;
				button->SetNameID("enable grid");
			}


			if (button->GetNameId() == "NextMap") {
				GameSettings::SetGameLevels(GameSettings::GetGemeLevels() + 1);
				ptr_game_settings->SaveSettings();
				is_Next_Level = true;
				cout << "NextMap" << endl;				
			}

			/// ///

			if (button->GetNameId() == "CreateStart" ) {

				cout << "Create_Start_achc_menu!" << endl;
				is_new_start = true;
				
			}

			if (button->GetNameId() == "CreateFinish" ) {

				cout << "Create_Finisht_achc_menu!" << endl;
				is_new_finish = true;

			}

			if (button->GetNameId() == "SaveMap") {

				is_save_map = true;

				m_map_ptr->SetName(vec_textbox[0].get()->GetData());

				v2i newSize = v2i(
					stoi(vec_textboxInt[0].get()->GetData()),
					stoi(vec_textboxInt[1].get()->GetData())
				);

				m_map_ptr->SetMapSize(newSize);

			}

			if (button->GetNameId() == "BACK") {
				cout << "BACK_achc_menu!" << endl;
				is_back = true;
			}

		}
	}

	for (auto& textbox : vec_textbox)
		textbox->Action();
	for (auto& textbox : vec_textboxInt)
		textbox->Action();
}

void ArchtectMenu::Update()
{
	m_map_ptr->GetName();



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

	System::wnd.draw(m_menu);
	System::wnd.draw(m_main_text);
	System::wnd.draw(m_name_vector_text);


	for (auto& button : vec_button)
		button->Draw();

	for (auto& textbox : vec_textbox)
		textbox->Draw();
	for (auto& textbox : vec_textboxInt)
		textbox->Draw();

	System::wnd.setView(System::cam);
}

Shape* ArchtectMenu::GetSnape()
{
	return &m_menu;
}

ArchtectMenu::~ArchtectMenu()
{
}
