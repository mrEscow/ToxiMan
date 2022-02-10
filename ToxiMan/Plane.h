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
	IButton* A = new Button;
	IButton* D = new Button;
	IButton* LKM = new Button;
public:
	virtual void Action() = 0;
	virtual ~AController() {
		delete W;
		delete S;
		delete LKM;
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

class IGun {
public:
	virtual void fire(v2f direction, float speed) = 0;
};

class Gun: public DynamicObject, public IGun{
protected:
	//v2f m_size{ 0,0 };
	bool isFire{ 0 };
public:

	Gun(sf::RectangleShape* rectangle) : DynamicObject(rectangle) {};

	// Унаследовано через IGun
	virtual void fire(v2f direction, float speed = 1000) override {
		if (!isFire) {
			this->SetSpeed(speed);
			this->SetDirection(direction);
		}
	}
	virtual ~Gun() {};
};

class MyGun :public Gun {
public:
	MyGun(sf::RectangleShape* rectangle) : Gun(rectangle) {};
};

class Iplane {
	virtual void fly() = 0;
	virtual void SetSize(v2f size = v2f(10, 10)) = 0;
};
// plane как и гаме тоже фасад или как паттерн посредник
class Plane : public DynamicObject, public Iplane
{
	sf::RectangleShape* m_rectangle;

	//v2f m_size{ 0,0 };

	Controller ix;
	AController* xyu = &ix;

	IDynamicObject* slot_1 = new MyGun(new sf::RectangleShape(v2f(30,30)));
	vector<IDynamicObject*> vSlots;

	int x{ 0 }, y{ 0 };

	void fly() {
		//m_position.x++;
		Controller();
		this->SetDirection(v2f(x, y));
	}

	void fire() {
		dynamic_cast<IGun*>(slot_1)->fire(System::cur_p, 100);
	}

	void Controller() {

		if (xyu->W->ON()) {
			this->SetSpeed(100);
			y == 1?y = 0 : y = -1;
			//y = -1;
			//this->SetDirection(v2f(0, -1));
		}
		if (xyu->S->ON()) {
			this->SetSpeed(100);
			y == -1 ? y = 0 : y = 1;
			//y = 1;
			//this->SetDirection(v2f(0, 1));
		}
		if (xyu->A->ON()) {
			this->SetSpeed(100);
			x = -1;
			//this->SetDirection(v2f(-1, 0));
		}
		if (xyu->D->ON()) {
			this->SetSpeed(100);
			x = 1;
			//this->SetDirection(v2f(1, 0));
		}
		if (xyu->LKM->ON()) {
			this->SetSpeed(1);
			this->SetDirection(System::cur_p);
			//slot_1->fire(System::cur_p,100);
		}
	}

public:

	Plane(sf::RectangleShape* rectangle) : DynamicObject(rectangle) {
		m_rectangle = rectangle;
		m_size = rectangle->getSize();
		vSlots.push_back(slot_1);
	};

	virtual void SetSize(v2f size = v2f(10,10)) override {
		m_size = size;
		m_rectangle->setSize(m_size);
	}



	void Update() {
		fly();
		fire();

		System::cam.move(m_rectangle->getPosition());
		System::wnd.setView(System::cam);

	};

	void action() {
		xyu->Action();
	}
};

