#pragma once
#include"System.h"
class IButton {
public:
	virtual bool ON() = 0;
	virtual void Set(bool) = 0;
};

class Button : public IButton
{
public:
	bool stage{ false };
public:
	virtual bool ON() override {
		return stage;
	}
	virtual void Set(bool stage) override {
		this->stage = stage;
	}
private:
};

class Controller {
public:
	IButton* W = new Button;
	IButton* S = new Button;
	IButton* A = new Button;
	IButton* D = new Button;

	IButton* LKM = new Button;
	IButton* PKM = new Button;

	IButton* NUM1 = new Button;
	IButton* NUM2 = new Button;
	IButton* NUM3 = new Button;

public:
	virtual void Action() = 0;
	virtual ~Controller() {
		delete W;
		delete S;
		delete A;
		delete D;
		delete LKM;
		delete PKM;
		delete NUM1;
		delete NUM2;
		delete NUM3;
	};
};

class PlayerController: public Controller {
public:
	PlayerController() {};
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
		if (System::IsKeyPressed(Key::A) || System::IsKeyPressed(Key::Left)) {
			A->Set(true);
		}
		if (System::IsKeyReleased(Key::A) || System::IsKeyReleased(Key::Left)) {
			A->Set(false);
		}
		if (System::IsKeyPressed(Key::D) || System::IsKeyPressed(Key::Right)) {
			D->Set(true);
		}
		if (System::IsKeyReleased(Key::D) || System::IsKeyReleased(Key::Right)) {
			D->Set(false);
		}
		if (System::IsMousePressed(MouseButton::Left)) {
			LKM->Set(true);
		}
		if (System::IsMouseReleased(MouseButton::Left)) {
			LKM->Set(false);
		}
	}
};


class GuiController : public Controller {
public:
	virtual void Action() override {
		if (System::IsKeyPressed(Key::Num1)) {
			NUM1->Set(true);
		}
		if (System::IsKeyReleased(Key::Num1)) {
			NUM1->Set(false);
		}
		if (System::IsKeyPressed(Key::Num2)) {
			NUM2->Set(true);
		}
		if (System::IsKeyReleased(Key::Num2)) {
			NUM2->Set(false);
		}
		if (System::IsKeyPressed(Key::Num3)) {
			NUM3->Set(true);
		}
		if (System::IsKeyReleased(Key::Num3)) {
			NUM3->Set(false);
		}
	}
};

class AIController :public Controller {
	virtual void Action() override {

	};
};