#include "LoadBoard.h"

uint32 LoadBoard::id = 0;

LoadBoard::LoadBoard(string name, v2f pos)
{
	m_id = id;

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
		"Load" 
		)
	);
	buttons.push_back(make_unique<UI::Button>(System::CreateShape(v2f(
		shape.getPosition().x + 115 + 45, 
		shape.getPosition().y + 75 + 16),
		v2f(90, 32), 
		System::resources.texture.menu_button), 
		"Save" 
		)
	);
	buttons.push_back(make_unique<UI::Button>(System::CreateShape(v2f(
		shape.getPosition().x + 215 + 45,
		shape.getPosition().y + 75 + 16),
		v2f(90, 32), 
		System::resources.texture.menu_button), 
		"Delete" 
		)
	);

	textbox = make_unique <UI::TextBox>(v2f(
		shape.getPosition().x + 140 + 90, 
		shape.getPosition().y + 20 + 18),
		v2f(150, 36), 
		name, 
		name, 
		10
	);

	id++;
}

void LoadBoard::Action(bool& is_load, bool& is_save, bool& is_delete)
{
	for (auto& button : buttons)
	{
		if (button->IsAction()) {
			if (button->GetNameId() == "Load") {
				is_load = true;
				cout << "Load" << endl;
			}
			if (button->GetNameId() == "Save") {
				is_save = true;
				cout << "Save" << endl;
			}
			if (button->GetNameId() == "Delete") {
				is_delete = true;
				this->is_delete = true;
				cout << "Delete" << endl;
			}
		}
	}

}

void LoadBoard::Update()
{

	textbox->SetPosition(v2f(
		shape.getPosition().x + 140 + 90, 
		shape.getPosition().y + 20 + 18
	));

	for (auto& button : buttons)
		button->Update();
}

void LoadBoard::Draw()
{
	System::wnd.draw(shape);
	textbox->Draw();


	for (auto& button : buttons)
		button->Draw();
}

uint LoadBoard::GetId()
{
	return m_id;
}

void LoadBoard::NewId()
{
	m_id--;
}

bool LoadBoard::CheckDel()
{
	return is_delete;
}
