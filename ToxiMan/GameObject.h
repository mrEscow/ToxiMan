#pragma once
#include "System.h"

class IGameObject {
public:
	virtual void Draw() = 0;
	virtual void SetPosition(v2f position) = 0;
};

class GameObject :public IGameObject {
protected:
	sf::Shape* pShape_ = nullptr;
	v2f m_direction{ 0,0 };
	v2f m_position{ 0,0 };
public:
	GameObject(sf::Shape* shape) {
		pShape_ = shape;
	};
	virtual void Draw() override {
		if (pShape_){}
			System::wnd.draw(*pShape_);
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
	//sf::Shape* pShape_;
public:
	DynamicObject(sf::Shape* shape):GameObject(shape){
		pShape_ = shape;
	};
	void SetSpeed(float speed) {
		m_speed = speed;
	}
	virtual void SetDirection(v2f direction) {
		m_direction = direction;
	};
	virtual void Move(float time){
		if (pShape_)
			pShape_->move(m_direction * m_speed * time);
	};

};

class BigSquare :public DynamicObject {
protected:
	v2f m_size{ 0,0 };
public:
	BigSquare(sf::RectangleShape* rectangle) :DynamicObject(rectangle) {
		m_size = rectangle->getSize();
	}
};