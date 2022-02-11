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
		// �������� ��������� �����, ����� �������� ������-�������.
		GameObject* product = this->FactoryMethod();
		// �����, �������� � ���� ���������.
		vGemeObjects.push_back(dynamic_cast<IGameObject*>(product));
		vDynamicObjects.push_back(dynamic_cast<DynamicObject*>(product));
		//std::string result = "Creator: The same creator's code has just worked with " + product->Operation();
		return product;
	}
};

class CreateDynamicTank : public Creator {
	/**
	 * �������� ��������, ��� ��������� ������ ��-�������� ���������� ���
	 * ������������ ��������, ���� ���������� �� ������ ������������ ����������
	 * �������. ����� �������, ��������� ����� ���������� ����������� ��
	 * ���������� ������� ���������.
	 */
public:
	GameObject* FactoryMethod() const override {
		Tank* newTank = new Tank(new sf::RectangleShape(v2f(200, 150)));
		newTank->SetSpeed(rand()%1000);
		//newTank->SetDirection(v2f(PLAYER));
		newTank->SetDirection(v2f((System::cur_p_wnd.x - System::scr_w / 2) / 1920, (System::cur_p_wnd.y - System::scr_h / 2) / 1080));
		return newTank;
	}
};