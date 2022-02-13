#pragma once
#include "GameObject.h" // Super class
#include "Controller.h"



class Bullet : public DynamicObject {
public:

	Bullet(sf::RectangleShape* rectangle,v2f pos): DynamicObject(rectangle){
		rectangle->setPosition(pos);
		SetSpeed(10000);

		//cout << (System::cur_p_wnd.x - System::scr_w / 2) << endl;
		//cout << cos(System::cur_p_wnd.x - System::scr_w / 2) << endl;
		//int x, y{0};
		//if (System::cur_p_wnd.x - System::scr_w / 2 < 0)
		//	x = -1;
		//else
		//	x = 1;
		//cout << tan(x) << endl;;
		//SetDirection(v2f(x, y));

		SetDirection(v2f((System::cur_p_wnd.x - System::scr_w/2)/1920, (System::cur_p_wnd.y - System::scr_h/2)/1080));
	};
};

class IGun {
public:
	virtual void SetPozition(v2f position) = 0;
	virtual void fire(v2f direction, float speed) = 0;
};

class Gun: public DynamicObject, public IGun{
protected:
	//v2f m_size{ 0,0 };

	//vector<IDynamicObject*> vBullets;
public:

	Gun(sf::RectangleShape* rectangle) : DynamicObject(rectangle) {};

	// Унаследовано через IGun
	virtual void fire(v2f direction, float speed = 1000) override {

			Bullet* pBullet = new Bullet(new sf::RectangleShape(v2f(10, 10)), this->pShape_->getPosition());
			vDynamicObjects.push_back(pBullet);
			vGemeObjects.push_back(pBullet);

	}
	virtual void SetPozition(v2f position) override {
		this->pShape_->setPosition(position);
	};
	virtual ~Gun() {};
};

class MyGun :public Gun {
public:
	MyGun(sf::RectangleShape* rectangle) : Gun(rectangle) {};
};

class Iplane {
	virtual void fly() = 0;
	virtual void SetSize(v2f size = v2f(10, 10)) = 0;
	virtual v2f GetPosition() = 0;
};
// plane как и гаме тоже фасад или как паттерн посредник
class Plane : public DynamicObject, public Iplane
{


	//v2f m_size{ 0,0 };

	Controller* xyu = new PlayerController;

	IDynamicObject* slot_1;
	IDynamicObject* slot_2;
	IDynamicObject* slot_3;

	int x{ 0 }, y{ 0 };

	void fly() {
		//m_position.x++;
		Controller();
		this->SetDirection(v2f(x, y));
	}

	void fire() {
		dynamic_cast<IGun*>(slot_1)->fire(System::cur_p, 100);
		dynamic_cast<IGun*>(slot_2)->fire(System::cur_p, 100);
		dynamic_cast<IGun*>(slot_3)->fire(System::cur_p, 100);
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
			fire();
			//this->SetSpeed(1);
			//this->SetDirection(System::cur_p);
			//slot_1->fire(System::cur_p,100);
		}
	}
public:
	sf::RectangleShape* m_rectangle;

public:

	Plane(sf::RectangleShape* rectangle) : DynamicObject(rectangle) {
		m_rectangle = rectangle;

		m_size = rectangle->getSize();

		slot_1 = new MyGun(new sf::RectangleShape(v2f(30, 30)));
		vDynamicObjects.push_back(slot_1);
		vGemeObjects.push_back(dynamic_cast<IGameObject*>(slot_1));

		slot_2 = new MyGun(new sf::RectangleShape(v2f(30, 30)));
		vDynamicObjects.push_back(slot_2);
		vGemeObjects.push_back(dynamic_cast<IGameObject*>(slot_2));

		slot_3 = new MyGun(new sf::RectangleShape(v2f(30, 30)));
		vDynamicObjects.push_back(slot_3);
		vGemeObjects.push_back(dynamic_cast<IGameObject*>(slot_3));

		vAllControllers.push_back(xyu);
	};

	virtual void SetSize(v2f size = v2f(10,10)) override {
		m_size = size;
		m_rectangle->setSize(m_size);
		m_rectangle->setOrigin(size.x / 2, size.y / 2);
	}



	void Update() {

		dynamic_cast<IGun*>(slot_1)->SetPozition(v2f(m_rectangle->getPosition().x, m_rectangle->getPosition().y - 30));
		dynamic_cast<IGun*>(slot_2)->SetPozition(v2f(m_rectangle->getPosition().x, m_rectangle->getPosition().y + 50 ));
		dynamic_cast<IGun*>(slot_3)->SetPozition(v2f(m_rectangle->getPosition().x+100, m_rectangle->getPosition().y+10));
		fly();
		System::cam.move(m_rectangle->getPosition());
		System::wnd.setView(System::cam);

		SetSpeed(800);
		SetDirection(v2f((System::cur_p_wnd.x - System::scr_w / 2) / 1920, (System::cur_p_wnd.y - System::scr_h / 2) / 1080));
	};

	void action() {
		//xyu->Action();
	}

	virtual v2f GetPosition() override {
		return m_rectangle->getPosition();
	}
};



// Абстракция 
class APlane : public GameObject, public IDynamicObject, public Iplane {
private:
	bool isDead{ false };

	float m_speed{ 0 };

	v2f m_direction{0,0};

	float distance{ 0 };

	GameObject* destination; // место назначения


	void Controller() {
		//захватить цель
		//установить направление к цели
		//проверить росстояние до цели
		//открыть огонь
	}

protected:
	APlane(sf::RectangleShape* rectangle) : GameObject(rectangle){
		m_rectangle = rectangle;
	}
	
public:
	sf::RectangleShape* m_rectangle{ nullptr };
	virtual void Move() override {
		if (pShape_) {};
			pShape_->move(m_direction * m_speed * (System::time / 1000));
	};

	virtual void SetSize(v2f size = v2f(10, 10)) override {
		m_size = size;
		m_rectangle->setSize(size);
		m_rectangle->setOrigin(size.x / 2, size.y / 2);
	};
	virtual void SetSpeed(float speed) override {
		m_speed = speed;
	};
	virtual void SetDirection(v2f direction) override {
		m_direction = direction;
	};

	virtual void SetAngle(float angle) override {
		pShape_->setRotation(angle);
	}

	virtual void fly() override {
		Controller();
		this->SetDirection(v2f(m_direction));
	};

	virtual v2f GetPosition() override {
		return pShape_->getPosition();
	};
	void Daed() {
		isDead = true;
	}

	bool isDaed() {
		return isDead;
	}

};

class PlaneFighter : public APlane {
public:
	PlaneFighter(sf::RectangleShape* rectangle) : APlane(rectangle) {
		m_rectangle = rectangle;
	}
	virtual void SetShape(sf::RectangleShape* rectangle) {
		m_rectangle = rectangle;
	};

	virtual void SetTexture(sf::Texture* textura) {
		m_rectangle->setTexture(textura);
	};
};

class PlaneInterceptor : public APlane {
public:
	PlaneInterceptor(sf::RectangleShape* rectangle) : APlane(rectangle) {
		m_rectangle = rectangle;
	}
	virtual void SetShape(sf::RectangleShape* rectangle) {
		m_rectangle = rectangle;
	};

	virtual void SetTexture(sf::Texture* textura) {
		m_rectangle->setTexture(textura);
	};
};

class PlaneBomber : public APlane {
public:
	PlaneBomber(sf::RectangleShape* rectangle) : APlane(rectangle) {
		m_rectangle = rectangle;
	}
	virtual void SetShape(sf::RectangleShape* rectangle) {
		m_rectangle = rectangle;
	};

	virtual void SetTexture(sf::Texture* textura) {
		m_rectangle->setTexture(textura);
	};
};