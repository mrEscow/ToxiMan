// ▼
#pragma once
#include "System.h"
#include "Boby.h"
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

		b2Body* body = world->CreateBody(&bodyDef);
		body->CreateFixture(&polygonShape, massa);
		body->SetUserData(const_cast<char*>(name)); // stackoverflow
		//body->SetUserData(name); // stackoverflow
		body->SetFixedRotation(fixRotat); // не крутися
		return body;
	}

	// не получилось)
	 
	//static BodyBox GetBodyBox(Shape& box, float massa = 1.f,const char* name = "no_name", bool dinamic = false, bool fixRotat = false) {
	//	BodyBox b;
	//	b.m_polygonShape.SetAsBox((box.getSize().x / 2) / SCALE, (box.getSize().y / 2) / SCALE);

	//	
	//	b.m_bodyDef.position.Set(box.getPosition().x / SCALE, box.getPosition().y / SCALE);
	//	if(dinamic)
	//		b.m_bodyDef.type = b2_dynamicBody;


	//	b.m_body = world->CreateBody(&b.m_bodyDef);
	//	b.m_body->CreateFixture(&b.m_polygonShape, massa);
	//	b.m_body->SetUserData(const_cast<char*>(name));
	//	b.m_body->SetFixedRotation(fixRotat);

	//	return b;
	//}
	//static void CheckParam(BodyBox& b) {
	//	b.m_body = world->CreateBody(&b.m_bodyDef);
	//}
};









// box2d
//ptr_world = &World;

// статическое тело
//setWall(55, 438, 64, 60);
//setWall(710, 435, 100, 60);

//b2BodyDef groundBodyDef;
//groundBodyDef.position.Set(0.0f, -10.0f);
//b2Body* groundBody = World.CreateBody(&groundBodyDef);

//b2PolygonShape groundBox;
//groundBox.SetAsBox(50.0f, 10.0f);
//groundBody->CreateFixture(&groundBox, 0.0f);

	//// динамическое тело


//b2BodyDef bodyDef;
//bodyDef.type = b2_dynamicBody;
//bodyDef.position.Set(0.0f, 4.0f);
//b2Body* body = World.CreateBody(&bodyDef);

//b2PolygonShape dynamicBox;
//dynamicBox.SetAsBox(1.0f, 1.0f);

//b2FixtureDef fixtureDef;
//fixtureDef.shape = &dynamicBox;
//fixtureDef.density = 1.0f;
//fixtureDef.friction = 0.3f;

//body->CreateFixture(&fixtureDef);
//// моделирование мира
//float timeStep = 1.0f / 60.0f;
//int32 velocityIterations = 6;
//int32 positionIterations = 2;

//for (int32 i = 0; i < 60; ++i)
//{
//	World.Step(timeStep, velocityIterations, positionIterations);
//	b2Vec2 position = body->GetPosition();
//	float angle = body->GetAngle();
//	printf("%4.2f %4.2f %4.2f\n", position.x, position.y, angle);
//}
//----------------------------------------------