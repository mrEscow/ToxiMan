#pragma once
#include "GameObject.h"
#include "Plane.h"
class Factory
{
};

class Tank : public DynamicObject{

public:
	sf::RectangleShape* m_rectangle;
	Tank(sf::RectangleShape* rectangle) : DynamicObject(rectangle) {
		m_rectangle = rectangle;
	};
};

class Product :public DynamicObject {
public:
	Product(sf::RectangleShape* rectangle) : DynamicObject(rectangle) {};
	virtual ~Product() {};
	//virtual GameObject* Operation() const = 0;
};

class DynamicTank : public Tank {
public:
	//SetDirection()
};

class ConcreteProductPlane : public Product {
public:
	//GameObject* Operation() const override {
	//	return new Plane(new sf::RectangleShape(v2f(50, 150)));;
	//}
};

class Creator {
public:
	virtual ~Creator() {};
	virtual GameObject* FactoryMethod() const = 0;
	GameObject* CreateGameObject() const {
		// Вызываем фабричный метод, чтобы получить объект-продукт.
		GameObject* product = this->FactoryMethod();
		// Далее, работаем с этим продуктом.
		//vGemeObjects.push_back(dynamic_cast<IGameObject*>(product));
		vDynamicObjects.push_back(dynamic_cast<DynamicObject*>(product));
		vDynamicObjects.push_back(dynamic_cast<IDynamicObject*>(product));
		//std::string result = "Creator: The same creator's code has just worked with " + product->Operation();
		return product;
	}
};

class CreateDynamicTank : public Creator {
public:
	GameObject* FactoryMethod() const override {
		Tank* newTank = new Tank(new sf::RectangleShape(v2f(200, 150)));
		newTank->SetSpeed(rand()%1000);
		newTank->SetDirection(v2f((System::cur_p_wnd.x - System::scr_w / 2) / 1920, (System::cur_p_wnd.y - System::scr_h / 2) / 1080));
		vAllTanks.push_back(newTank);
		return newTank;
	}
};



class CreateDynamicPlanFighter : public Creator {
public:
	GameObject* FactoryMethod() const override {

		sf::RectangleShape* rectangle = new sf::RectangleShape;
		rectangle->setSize(v2f(200, 200));
		rectangle->setOrigin(100, 100);
		rectangle->setTexture(&System::resources.texture.Figter);
		PlaneFighter* Plane = new PlaneFighter(rectangle);
		Plane->SetSpeed(rand() % 1500);
		Plane->SetDirection(v2f(1,0));
		vAllPlans.push_back(Plane);
		return Plane;
	}
};

class CreateDynamicPlanInterceptor : public Creator {
public:
	GameObject* FactoryMethod() const override {
		sf::RectangleShape* rectangle = new sf::RectangleShape;
		rectangle->setSize(v2f(250, 250));
		rectangle->setOrigin(125, 125);
		rectangle->setTexture(&System::resources.texture.Interceptor);
		PlaneInterceptor* Plane = new PlaneInterceptor(rectangle);
		Plane->SetSpeed(rand() % 1000 );
		Plane->SetDirection(v2f(1, 1));
		vAllPlans.push_back(Plane);
		return Plane;
	}
};

class CreateDynamicPlanBomber : public Creator {
public:
	GameObject* FactoryMethod() const override {
		sf::RectangleShape* rectangle = new sf::RectangleShape;
		rectangle->setSize(v2f(300, 300));
		rectangle->setOrigin(150, 150);
		rectangle->setTexture(&System::resources.texture.Bomber);
		PlaneBomber* Plane = new PlaneBomber(rectangle);
		Plane->SetSpeed(rand() % 700);
		Plane->SetDirection(v2f(1, -1));
		vAllPlans.push_back(Plane);
		return Plane;
	}
};

/// <summary>
/// Фабрика самолетов
/// </summary>
class FactoryPlans {
	CreateDynamicPlanFighter CDPF;
	CreateDynamicPlanInterceptor CDPI;
	CreateDynamicPlanBomber CDPB;
public:
	FactoryPlans() {
		System::resources.texture.LoadPlans();
	}
	vector< GameObject*> CreateTrheeFighter() {
		vector< GameObject*> plans;	
		plans.push_back(CDPF.CreateGameObject());
		plans.push_back(CDPF.CreateGameObject());
		plans.push_back(CDPF.CreateGameObject());
		return plans;
	};
	vector< GameObject*> CreateTwoInterceptors() {
		vector< GameObject*> plans;
		plans.push_back(CDPI.CreateGameObject());
		plans.push_back(CDPI.CreateGameObject());
		return plans;
	};
	vector< GameObject*> CreateOneBomber() {
		vector< GameObject*> plans;
		plans.push_back(CDPB.CreateGameObject());
		return plans;
	};
};