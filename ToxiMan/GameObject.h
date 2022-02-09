#pragma once
#include "System.h"

class IGameObject {
public:
	virtual void Draw() = 0;
	virtual void SetPosition(v2f position) = 0;
};

class GameObject :public IGameObject {
	sf::Shape* pShape_ = nullptr;
	// Shader
	v2f m_direction{ 0,0 };
	v2f m_position{ 0,0 };
public:
	GameObject(sf::Shape* shape) {
		pShape_ = shape;
	};
	virtual void Draw() override {
		if (pShape_)
			System::wnd.draw(*pShape_/*Shader*/);
	};
	virtual void SetPosition(v2f position) override {
		m_position = position;
		if (pShape_)
			pShape_->setPosition(m_position);
	};
	virtual ~GameObject() {
		delete pShape_;
	}

};

class DynamicObject :public GameObject {
	float m_speed;
	sf::Shape* pShape_;
public:
	DynamicObject(sf::Shape* shape):GameObject(shape){
		pShape_ = shape;
	};
	void SetSpeed(float speed) {
		m_speed = speed;
	}
	virtual void Move(v2f direction){
		if (pShape_)
			pShape_->move(direction * m_speed);
	};
};

class BigSquare :public DynamicObject {
public:
	BigSquare(sf::RectangleShape* shape):DynamicObject(shape) {};
};