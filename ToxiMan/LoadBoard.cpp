#include "LoadBoard.h"

LoadBoard::LoadBoard(GameSettings& game_settings, string name, v2f pos)
{
	System::resources.texture.LoadLoadBoard();

	this->pos = pos;
	size = v2f(333.f, 119.f);

	shape = System::CreateShape(this->pos, size,System::resources.texture.LoadBord);

	shape.setOrigin(v2f(0, 0));

	buttons.push_back(make_unique<UI::Button>(System::CreateShape(v2f(
		shape.getPosition().x + 15 + 45, 
		shape.getPosition().y + 75 + 16),
		v2f(90, 32),
		System::resources.texture.menu_button), 
		"Load", 
		game_settings)
	);
	buttons.push_back(make_unique<UI::Button>(System::CreateShape(v2f(
		shape.getPosition().x + 115 + 45, 
		shape.getPosition().y + 75 + 16),
		v2f(90, 32), 
		System::resources.texture.menu_button), 
		"Save", 
		game_settings)
	);
	buttons.push_back(make_unique<UI::Button>(System::CreateShape(v2f(
		shape.getPosition().x + 215 + 45,
		shape.getPosition().y + 75 + 16),
		v2f(90, 32), 
		System::resources.texture.menu_button), 
		"Delete", 
		game_settings)
	);

	cout << pos.x << endl;
	cout << pos.y << endl;

	textbox = make_unique <UI::TextBox>(v2f(
		shape.getPosition().x + 140 + 90, 
		shape.getPosition().y + 20 + 18),
		v2f(180, 36), 
		name, 
		name, 
		10
	);
}

void LoadBoard::Update()
{

	textbox->SetPosition(v2f(
		shape.getPosition().x + 140 + 90, 
		shape.getPosition().y + 20 + 18
	));
}

void LoadBoard::Draw()
{
	System::wnd.draw(shape);
	textbox->Draw();

	for (auto& button : buttons)
		button->Draw();
}
