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
	bool stage{false};
public:
	virtual bool ON() override {
		return stage;
	}
	virtual void Set(bool stage) override {
		this->stage = stage;
	}
	//Button();
	//~Button();

private:
};

class AController {
public:
	IButton* W = new Button;
	IButton* S = new Button;
public:
	virtual void Action() = 0;
	virtual ~AController() {
		delete W;
		delete S;
	};
};

class Controller: public AController {
public:
	Controller() {};
	virtual void Action() override{
		if (System::IsKeyPressed(Key::W) || System::IsKeyPressed(Key::Up)) {
			W->Set(true);
		}

		if (System::IsKeyReleased(Key::W) || System::IsKeyReleased(Key::Up)) {
			W->Set(false);
		}

		if (System::IsKeyPressed(Key::S) || System::IsKeyPressed(Key::Down)) {
			S->Set(true);
		}

		if (System::IsKeyReleased(Key::S) || System::IsKeyReleased(Key::Down)) {
			S->Set(false);
		}
	}
	
};

class Plane : public DynamicObject
{
	Controller ix;
	AController* x = &ix;

	void fly() {
		m_position.x++;
		Controller();
		this->SetPosition(m_position);
	}

	void Controller() {

		if (x->W->ON()) {
			m_position.y++;
		}
		if (x->S->ON()) {
			m_position.y--;

		}
	}

public:

	Plane(sf::RectangleShape* rectangle) : DynamicObject(rectangle) {

	};

	void update() {
		fly();
	};

	void action() {
		x->Action();
	}


};

