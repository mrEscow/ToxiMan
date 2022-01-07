#include "ExitMenu.h"


ExitMenu::ExitMenu()
{
	PNG& t_button = System::resources.texture.menu_button;

	text_exit = System::CreateText(v2f(0, -300), 40, "Are you sure you want to get out?", System::resources.font.erica_type, Color::Black);
	System::CenteringText(text_exit);

	vec_button.push_back(make_unique<UI::Button>(System::CreateShape(v2f(0, -225), v2f(200, 50), t_button), "Yes"));
	vec_button.push_back(make_unique<UI::Button>(System::CreateShape(v2f(0, -150), v2f(200, 50), t_button), "No"));
}

void ExitMenu::Update()
{
	for (auto& button : vec_button)
		button->Update();
}

void ExitMenu::Draw()
{
	System::wnd.draw(text_exit);
	for (auto& button : vec_button)
		button->Draw();
}

void ExitMenu::Action()
{
	for (auto& button : vec_button)
	{
		if (button->IsAction())
		{
			cout << button->GetNameId() << endl;
			if (button->GetNameId() == "Yes") System::wnd.close();;
			if (button->GetNameId() == "No") g_StateMainMenu = StateMainMenu::ON_MAIN;

		}
	}
}

ExitMenu::~ExitMenu()
{
}
