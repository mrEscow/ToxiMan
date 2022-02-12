#pragma once
#include "System.h"

class IGameObject {
public:
	virtual void Draw() = 0;
};

inline 	vector<IGameObject*> vGemeObjects;

const Uint Grounds = 0;
inline 	vector<IGameObject*> vAllGrounds;
const Uint Houses = 25;
inline 	vector<IGameObject*> vAllHouses;
const Uint Tanks = 50;
inline 	vector<IGameObject*> vAllTanks;
const Uint Players = 75;
inline 	vector<IGameObject*> vAllPlayers;
const Uint Plans = 100;
inline 	vector<IGameObject*> vAllPlans;
const Uint Guis = 125;
inline 	vector<IGameObject*> vAllGuis;


inline 	vector<pair<Uint32, vector<IGameObject*>>> vGemeObjectsV01;






class GameObject :public IGameObject {
protected:

	sf::Shape* pShape_ = nullptr;

	v2f m_size{ 0,0 };

public:

	GameObject(sf::Shape* shape) {
		pShape_ = shape;
	};
	GameObject(sf::Shape* shape, v2f pos) {
		pShape_ = shape;
		pShape_->setPosition(pos);
	};
	virtual void Draw() override {
		if (pShape_ != nullptr){}
			System::wnd.draw(*pShape_);
	};

	virtual ~GameObject() {
		delete pShape_;
	}

};
/// <summary>
/// /////////////////////////////////////////////////////////////
/// </summary>
class IDynamicObject {
public:
	virtual void Move() = 0;
	virtual void SetDirection(v2f direction) = 0;
	virtual void SetSpeed(float speed) = 0;
};

inline vector<IDynamicObject*> vDynamicObjects;

class DynamicObject :public GameObject, public IDynamicObject {
protected:
	
	v2f m_direction{ 1,1 };
	float m_speed{ 100 };

public:
	DynamicObject(sf::Shape* shape):GameObject(shape){
		pShape_ = shape;

	};
	virtual void SetSpeed(float speed) {
		m_speed = speed;
	}
	virtual void SetDirection(v2f direction) {
		m_direction = direction;
	};

	virtual void Move() override{
		if (pShape_)
			pShape_->move(m_direction * m_speed * (System::time/1000));
	};

};

class BigSquare :public DynamicObject {
protected:
	sf::RectangleShape* m_rectangle;
public:
	BigSquare(sf::RectangleShape* rectangle) :DynamicObject(rectangle) {
		m_rectangle = rectangle;
		m_size = rectangle->getSize();
	}
};



class IStaticObject {
public:
	virtual void SetPozition(v2f pos)=0;
	virtual void SetSize(v2f size)=0;
};

inline 	vector<IStaticObject*> vStaticObjects;

class StaticObject : public GameObject, public IStaticObject {
protected:
	sf::RectangleShape* m_rectangle;
public:
	StaticObject(sf::RectangleShape* rectangle) :GameObject(rectangle) {
		m_size = rectangle->getSize();
	}

	// Унаследовано через IStaticObject
	virtual void SetPozition(v2f pos) override {
		this->SetPozition(pos);
	};
	virtual void SetSize(v2f size) override {
		this->SetSize(size);
	};
};

class BackGround :public StaticObject {
public:
	BackGround(sf::RectangleShape* rectangle) :StaticObject(rectangle) {
		m_size = rectangle->getSize();
	}
};


class GUI :public GameObject {
	sf::RectangleShape* pGUI = new sf::RectangleShape((v2f)System::wnd.getSize());
	Controller* pController = new GuiController;
public:
	GUI() : GameObject(pGUI){
		pGUI->setOrigin(v2f(pGUI->getSize().x, pGUI->getSize().y));
		pGUI->setFillColor(sf::Color::Color(0, 0, 0, 0));
	};

	void Update() {

		pGUI->setPosition(System::cam.getCenter());
	}


};