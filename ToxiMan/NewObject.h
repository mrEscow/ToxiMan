#pragma once
#include "GameObject.h"
class NewObject : public IGameObject, public IDynamicObject  {
public:
	// Унаследовано через IGameObject
	virtual void Draw() override
	{
		System::wnd.draw(*MainShape, &MainShader);
		System::wnd.draw(*MidlShape);
		System::wnd.draw(*TreygolShape);


		for (auto& littleShape : LittleShapes)
			System::wnd.draw(*littleShape);

		for (auto& ganShape : GanShapes)
			System::wnd.draw(*ganShape);
	}
	// Унаследовано через IDynamicObject
	virtual void Move() override {
		MainShape->move(m_direction * m_speed * (System::time / 1000));
		MidlShape->move(m_direction * m_speed * (System::time / 1000));
		TreygolShape->move(m_direction * m_speed * (System::time / 1000));
		TreygolShape->setRotation(System::GetAngle(*TreygolShape, v2f(-System::cur_p.x, -System::cur_p.y))-45.f);
	};
	virtual void SetDirection(v2f direction) override {
		m_direction = v2f((System::cur_p_wnd.x - System::scr_w / 2) / 1920, (System::cur_p_wnd.y - System::scr_h / 2) / 1080);
	};
	virtual void SetSpeed(float speed) override {
		m_speed = speed;
	};
	virtual void SetAngle(float angle) override {
		
	};
	// Player public
	v2f GetPosition() {
		return MainShape->getPosition();
	}
	Shape* GetShape() {
		return MainShape;
	}
protected:
	float m_speed;
	v2f m_direction;

	v2f Uniform_Cam;
	sf::Shader MainShader;

	Shape* MainShape;
	Shape* MidlShape;
	Shape* TreygolShape;

	vector<Shape*> LittleShapes;
	vector<Shape*> GanShapes;
public:

	NewObject() {

		Uniform_Cam = v2f(System::cam.getSize());

		System::resources.texture.LoadMonster();

		MainShape = new sf::RectangleShape(v2f(0, 0));
		MainShape->setSize(v2f(500, 500));
		MainShape->setOrigin(250, 250);
		MainShape->setTexture(&System::resources.texture.BigCyrkl);


		MidlShape = new sf::RectangleShape(v2f(0, 0));
		MidlShape->setSize(v2f(500, 500));
		MidlShape->setOrigin(250, 250);
		//MidlShape->setFillColor(sf::Color(0, 0, 0, 0));
		MidlShape->setTexture(&System::resources.texture.MidlCyrkl);

		TreygolShape = new sf::RectangleShape(v2f(0, 0));
		TreygolShape->setSize(v2f(500, 500));
		TreygolShape->setOrigin(250, 250);
		//TreygolShape->setFillColor(sf::Color(0, 0, 0, 0));
		TreygolShape->setTexture(&System::resources.texture.Treugol);

		//

		//LittleShapes = new sf::RectangleShape(v2f(0, 0));
		//LittleShapes->setSize(v2f(500, 500));
		//LittleShapes->setOrigin(250, 250);
		//LittleShapes->setTexture(&System::resources.texture.MidlCyrkl);

		vAllPlayers.push_back(this);
		vDynamicObjects.push_back(this);
	}


};

