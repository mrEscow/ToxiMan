#pragma once
#include "GameObject.h"
class NewObject : IGameObject {
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
protected:
	v2f Uniform_Pos;
	sf::Shader MainShader;

	Shape* MainShape;
	Shape* MidlShape;
	Shape* TreygolShape;

	vector<Shape*> LittleShapes;
	vector<Shape*> GanShapes;
public:

	NewObject() {

		Uniform_Pos = v2f(System::cam.getSize());

		System::resources.texture.LoadMonster();

		MainShape = new sf::RectangleShape(v2f(0, 0));
		MainShape->setSize(v2f(500, 500));
		MainShape->setOrigin(250, 250);
		MainShape->setTexture(&System::resources.texture.BigCyrkl);


		MidlShape = new sf::RectangleShape(v2f(0, 0));
		MidlShape->setSize(v2f(500, 500));
		MidlShape->setOrigin(250, 250);
		MidlShape->setTexture(&System::resources.texture.MidlCyrkl);

		TreygolShape = new sf::RectangleShape(v2f(0, 0));
		TreygolShape->setSize(v2f(500, 500));
		TreygolShape->setOrigin(250, 250);
		TreygolShape->setTexture(&System::resources.texture.MidlCyrkl);

		//

		MidlShape = new sf::RectangleShape(v2f(0, 0));
		MainShape->setSize(v2f(500, 500));
		MainShape->setOrigin(250, 250);
		MidlShape->setTexture(&System::resources.texture.MidlCyrkl);

		vAllPlayers.push_back(this);
	}
};

