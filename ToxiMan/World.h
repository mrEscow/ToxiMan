// ▼
#pragma once
#include "System.h"
class World {
public:

	static float		wind;
	static float		gravity;
	static b2Vec2		worldParam;
	static b2World*		world;
	static int			id;

	World(string init)  {
		if (init == "init") {
			wind = 0;
			gravity = 9.8;
			worldParam.Set(wind, gravity);
			static b2World wrd(worldParam);
			//wrd.DrawDebugData();
			world = &wrd;

			id = 0;
		}
	}
	World(void) {

	}
	// Позиция и размер
	static void SetStaticBox(float x, float y, float w, float h) {

		// auto SCALE = 30.f для перевода из метров в пиксели

		// Создание фигуры (может состоять из множества тел)
		b2PolygonShape polygonShape;
		// Размер делиться на два потому что размер берется из середины
		polygonShape.SetAsBox(w / 2 / SCALE, h / 2 / SCALE);  // Создание квадрата

		// Определение и свойства тела (позиция, масса, угол и т.д.)
		b2BodyDef bodyDef;
		// Позиция
		bodyDef.position.Set(x / SCALE, y / SCALE);

		// Создаем тело по предыдущим парамметрам
		b2Body* body = world->CreateBody(&bodyDef);

		// Присоединение тела к фигуре
		body->CreateFixture(&polygonShape, 1); // Второй параметр это плотность( чкм больше тем тяжелее тело)
		// без этого не работает проверка на OnGround!!!
		const char* name = "no_name" + id++;
		body->SetUserData(const_cast<char*>(name));

	}

	static void SetStaticBox(Shape& box) {

		// auto SCALE = 30.f для перевода из метров в пиксели

		// Создание фигуры (может состоять из множества тел)
		b2PolygonShape polygonShape;
		// Размер делиться на два потому что размер берется из середины
		polygonShape.SetAsBox((box.getSize().x / 2) / SCALE, (box.getSize().y / 2) / SCALE); // Создание квадрата

		// Определение и свойства тела (позиция, масса, угол и т.д.)
		b2BodyDef bodyDef;
		// Позиция
		bodyDef.position.Set(box.getPosition().x / SCALE, box.getPosition().y / SCALE);

		// Создаем тело по предыдущим парамметрам
		b2Body* body = world->CreateBody(&bodyDef);

		// Присоединение тела к фигуре
		body->CreateFixture(&polygonShape, 1);
		// без этого не работает проверка на OnGround!!!
		const char* name = "no_name" + id++;
		body->SetUserData(const_cast<char*>(name));
	}

	// Позиция и размер
	static void SetDynamicBox(float x, float y, float w, float h) {

		b2PolygonShape polygonShape;
		polygonShape.SetAsBox(w / 2 / SCALE, h / 2 / SCALE);  // Делиться на два потому что размер берется из середины

		b2BodyDef bodyDef;
		bodyDef.position.Set(x / SCALE, y / SCALE);

		bodyDef.type = b2_dynamicBody; // теперь на него влияют гравитация, ветер и тд

		b2Body* body = world->CreateBody(&bodyDef);
		body->CreateFixture(&polygonShape, 1);
		// без этого не работает проверка на OnGround!!!
		const char* name = "no_name" + id++;
		body->SetUserData(const_cast<char*>(name));
	}


	static void SetDynamicBox(Shape& box) {

		b2PolygonShape polygonShape;
		polygonShape.SetAsBox((box.getSize().x / 2) / SCALE, (box.getSize().y / 2) / SCALE); // размер

		b2BodyDef bodyDef;
		bodyDef.position.Set(box.getPosition().x / SCALE, box.getPosition().y / SCALE); // позиция

		bodyDef.type = b2_dynamicBody; // теперь на него влияют гравитация, ветер и тд

		b2Body* body = world->CreateBody(&bodyDef);
		body->CreateFixture(&polygonShape, 1);
		// без этого не работает проверка на OnGround!!!
		const char* name = "no_name" + id++;
		body->SetUserData(const_cast<char*>(name));
	}

	static void SetStaticCircle(CircleShape& a_circle) {

		//b2PolygonShape polygonShape;
		//polygonShape.SetAsBox((a_circle.getSize().x / 2) / SCALE, (a_circle.getSize().y / 2) / SCALE); // размер

		b2BodyDef bodyDef;
		bodyDef.position.Set(a_circle.getPosition().x / SCALE, a_circle.getPosition().y / SCALE); // позиция

		b2CircleShape b_circle;
		b_circle.m_radius = 3;

		b2Body* body = world->CreateBody(&bodyDef);
		body->CreateFixture(&b_circle, 1);
		// без этого не работает проверка на OnGround!!!
		const char* name = "no_name" + id++;
		body->SetUserData(const_cast<char*>(name));
	}

	static b2Body* CreateBodyCircle(CircleShape& circle, bool dinamic = false, float massa = 1.f) {
		b2BodyDef bodyDef;
		bodyDef.position.Set(circle.getPosition().x / SCALE, circle.getPosition().y / SCALE); // позиция
		if (dinamic)
			bodyDef.type = b2_dynamicBody; // теперь на него влияют гравитация и ветер
		b2CircleShape b_circle;
		b_circle.m_radius = circle.getRadius() / SCALE;
		
		b2Body* body = world->CreateBody(&bodyDef);
		body->CreateFixture(&b_circle, massa);
		// без этого не работает проверка на OnGround!!!
		const char* name = "no_name" + id++;
		body->SetUserData(const_cast<char*>(name));

		return body;
	}

	static b2Body* CreateBodyBox(Shape& box, const char* name = "no_name", float massa = 1.f, float width = 0.f, bool dinamic = false, bool fixRotat = false) {

		b2PolygonShape polygonShape;
		polygonShape.SetAsBox(((box.getSize().x - width) / 2) / SCALE, (box.getSize().y / 2) / SCALE); // размер
		
		b2BodyDef bodyDef;
		bodyDef.position.Set(box.getPosition().x / SCALE, box.getPosition().y / SCALE); // позиция
		if(dinamic)
			bodyDef.type = b2_dynamicBody; // теперь на него влияют гравитация и ветер

		b2FixtureDef fdef;
		fdef.density = massa;	// плотность
		fdef.restitution = 0;	// упругость (от 0 до 1)
		fdef.friction = 0.3;		// трение
		fdef.shape = &polygonShape;

		b2Body* body = world->CreateBody(&bodyDef);
		body->CreateFixture(&fdef);
		body->SetUserData(const_cast<char*>(name)); // stackoverflow
		//body->SetUserData(name); // stackoverflow
		body->SetFixedRotation(fixRotat); // не крутися
		return body;
	}

};