#pragma once
#include "GameObject.h"
#include "Plane.h"
class NewObject : public IGameObject, public IDynamicObject  {
public:
	// Унаследовано через IGameObject
	virtual void Draw() override
	{
		System::wnd.draw(*MainShape);
		System::wnd.draw(*MidlShape,&MainShader);
		System::wnd.draw(*TreygolShape);


		for (auto& littleShape : LittleShapes)
			System::wnd.draw(*littleShape);

		for (auto& ganShape : GanShapes)
			ganShape->Draw();
	}
	// Унаследовано через IDynamicObject
	virtual void Move() override {


		m_direction = v2f((System::cur_p_wnd.x - System::scr_w / 2) / 1920, (System::cur_p_wnd.y - System::scr_h / 2) / 1080);

		TreygolShape->setRotation(System::GetAngle(*TreygolShape, v2f(-System::cur_p.x, -System::cur_p.y)) - 45.f);

		System::cam.move(MainShape->getPosition());
		System::wnd.setView(System::cam);

		v2f go = m_direction * m_speed * (System::time / 1000);

		MainShape->move(go);
		MidlShape->move(go);
		TreygolShape->move(go);

		for (auto& ganShape : GanShapes)
			ganShape->SetPozition(MainShape->getPosition());

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

	vector<Gun*> GanShapes;
public:

	NewObject() {



		m_speed = 1500.f;

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

		Gun* WeaponSlot = new MyGun(new sf::RectangleShape(v2f(0, 0)));
		//LittleShapes->setSize(v2f(500, 500));
		//LittleShapes->setOrigin(250, 250);

		GanShapes.push_back(WeaponSlot);

		vAllPlayers.push_back(this);
		vDynamicObjects.push_back(this);
	}

	public:
		void Fire() {
			for (auto& ganShape : GanShapes)
				ganShape->fire(m_direction, 2000);
		}
};

