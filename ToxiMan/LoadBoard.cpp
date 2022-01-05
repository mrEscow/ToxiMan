#include "LoadBoard.h"

uint32 LoadBoard::id = 0;

LoadBoard::LoadBoard(string name, v2f pos)
{
	TextID.setFont(System::resources.font.common);

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

	TextID.setPosition(v2f(
		shape.getPosition().x + 15,
		shape.getPosition().y + 3)
	);

	OstrID << m_id;
	TextID.setString(OstrID.str());
	TextID.scale(v2f(0.8, 0.8));

	id++;
}

void LoadBoard::Action(std::map<uint32_t, Map>& Maps, bool& is_load, bool& is_save, bool& is_delete)
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

				if (Maps.size() > 1) {
					is_delete = true;
					this->is_delete = true;
					cout << "Delete" << endl;
				}
				else
					cout << "Non DELETE" << endl;

			}
		}
	}

	textbox->Action();

}

void LoadBoard::Update()
{
	shape.setPosition(pos);

	textbox->SetPosition(v2f(
		shape.getPosition().x + 140 + 90, 
		shape.getPosition().y + 20 + 18
	));

	TextID.setPosition(v2f(
		shape.getPosition().x + 15,
		shape.getPosition().y + 3)
	);

	buttons[0]->SetPosition(v2f(
		shape.getPosition().x + 15 + 45,
		shape.getPosition().y + 75 + 16
	));
	buttons[1]->SetPosition(v2f(
		shape.getPosition().x + 115 + 45,
		shape.getPosition().y + 75 + 16
	));
	buttons[2]->SetPosition(v2f(
		shape.getPosition().x + 215 + 45,
		shape.getPosition().y + 75 + 16
	));


	for (auto& button : buttons) 
		button->Update();

	textbox->Update();

	//OstrID << m_id;
	TextID.setString(to_string(m_id));
	OstrID.clear();
}

void LoadBoard::Draw()
{
	System::wnd.draw(shape);


	textbox->Draw();


	for (auto& button : buttons)
		button->Draw();

	System::wnd.draw(TextID);
}

uint LoadBoard::GetId()
{
	return m_id;
}

void LoadBoard::NewId(uint32 id)
{
	m_id = id;

}

void LoadBoard::SetPosition(v2f pos)
{
	this->pos = pos;
}

bool LoadBoard::CheckDel()
{
	return is_delete;
}
