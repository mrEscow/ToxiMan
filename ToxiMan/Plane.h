#pragma once
#include "GameObject.h" // Super class

class IButton {
public:
	virtual bool ON() = 0;
	virtual void Set(bool) = 0;
};

class Button : public IButton
{
public:
	string name;
	bool stage;
	bool ON{ false };
	virtual bool ON() override {
		return ON;
	}
	virtual void Set(bool stage) override {
		this->stage = stage;
	}
	Button();
	~Button();

private:
};

class Controller {
	Controller() {
		IButton* W = new Button;
		IButton* S = new Button;
		vecButtonLogic.push_back(W);
	}
	static vector<IButton*> vecButtonLogic;

	enum class Buttons
	{
		Button_W,
		Button_S
	};

	Buttons e;

	void Update() {
		if (System::IsKeyPressed(Key::Left) || System::IsKeyPressed(Key::A)) {
			is_button_Left = true;
		}

		if (System::IsKeyReleased(Key::Left) || System::IsKeyReleased(Key::A)) {
			is_button_Left = false;
		}

		if (System::IsKeyPressed(Key::Right) || System::IsKeyPressed(Key::D)) {
			is_button_Righr = true;
		}

		if (System::IsKeyReleased(Key::Right) || System::IsKeyReleased(Key::D)) {
			is_button_Righr = false;

		}
	}
	
};

class Plane : public DynamicObject
{

	Plane();

	void fly() {
		m_position.x++;
		this->SetPosition(m_position);
	}

	void chendyY() {
		if(controller)
	}
};

