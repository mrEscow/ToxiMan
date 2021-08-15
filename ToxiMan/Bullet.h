#pragma once
#include "System.h"
#include "World.h"
#include "GameStates.h"


class Bullet{

private:
	//Shape m_shape;
	//b2Body* m_body;

	CircleShape m_circleshape;
	b2BodyDef m_bodyDef;
	//b2FixtureDef m_fixDef;
	b2CircleShape m_circle;


	b2Vec2 m_mouse;
	b2Vec2 m_mouse2;
	float m_massa;

	int		magic;
	float	radius;
	float	dx;
	float	sizeGun;
	
	float len;
	float x, y;

	bool	is_shoot;
	bool	is_live;
	float	timer_live = 150; // 60000 минута
	PlayerDir m_dir;
	//float m_test;
public:
	
	b2Body* m_circlebody;
	b2FixtureDef m_fixDef;
	//  всё под корнем (x2-x1)2+(y2-y1)2
	//	static int ammo_counter;
	Bullet(Shape &gunPos, PlayerDir &dir) {
		m_dir = dir;
		// круглая пуля
		m_massa = 0.5;
		//magic = 10;
		radius = 20;
		sizeGun = 10;
		//is_shoot = false;
		//m_test = -5;
		//m_mouse.Set((mouse.x ), (mouse.y - 200));

		switch (dir)
		{
		case PlayerDir::RIGHT:
			
			//if (mouse.x > 0) {
				is_shoot = true;
				is_live = true;
				m_circleshape = System::CreateCircleShape(v2f(gunPos.getPosition().x + 5 + (gunPos.getSize().x / 2), gunPos.getPosition().y), radius, 30, -3, Color::Green, Color::Black);
				m_bodyDef.position.Set((gunPos.getPosition().x + 5 + (gunPos.getSize().x / 2)) / SCALE, m_circleshape.getPosition().y / SCALE);
				m_bodyDef.type = b2_dynamicBody;
				
				m_circle.m_radius = m_circleshape.getRadius() / SCALE;
				m_circlebody = World::world->CreateBody(&m_bodyDef);

				m_fixDef.density = m_massa;		// плотность (масса)
				m_fixDef.restitution = 0; // упругость (от 0 до 1)
				m_fixDef.friction = 0;		// трение (от 0 до 1)
				m_fixDef.shape = &m_circle;


				m_circlebody->CreateFixture(&m_fixDef);
				m_circlebody->SetGravityScale(0);
				//m_circlebody->SetBullet(true);
				m_circlebody->SetFixedRotation(true);
				m_circlebody->SetAngularDamping(1);
				m_circlebody->ApplyLinearImpulseToCenter(b2Vec2(15,0), true);
			//}			
			break;
		case PlayerDir::LEFT:
			//if (mouse.x < 0) {
				is_shoot = true;
				is_live = true;
				m_circleshape = System::CreateCircleShape(v2f(gunPos.getPosition().x - 5 - (gunPos.getSize().x / 2), gunPos.getPosition().y), radius, 30, -3, Color::Green, Color::Black);
				m_bodyDef.position.Set((gunPos.getPosition().x - 5 - (gunPos.getSize().x / 2)) / SCALE, m_circleshape.getPosition().y / SCALE);
				m_bodyDef.type = b2_dynamicBody;
				m_circle.m_radius = m_circleshape.getRadius() / SCALE;
				m_circlebody = World::world->CreateBody(&m_bodyDef);

				m_fixDef.density = m_massa;		// плотность (масса)
				m_fixDef.restitution = 0; // упругость (от 0 до 1)
				m_fixDef.friction = 0;		// трение (от 0 до 1)				
				m_fixDef.shape = &m_circle;

				m_circlebody->CreateFixture(&m_fixDef);
				m_circlebody->SetGravityScale(0);
				//m_circlebody->SetBullet(true);
				m_circlebody->SetFixedRotation(true);
				m_circlebody->SetAngularDamping(1);
				m_circlebody->ApplyLinearImpulseToCenter(b2Vec2(-15, 0), true);
			//}			
			break;
		default:
			
			break;
		}
	}
	void Update(PlayerDir& dir) {
		
		if( m_circlebody->GetLinearVelocity().y != 0)
			is_shoot = false;
		switch (m_dir)
		{
		case PlayerDir::RIGHT:
			if (m_circlebody->GetLinearVelocity().x <= 0)
				is_shoot = false;
			break;
		case PlayerDir::LEFT:
			if (m_circlebody->GetLinearVelocity().x >= 0)
				is_shoot = false;
			break;
		default:
			break;
		}
		//if (m_circlebody->IsBullet()) {
		//	cout << "m_circlebody->IsBullet()" << endl;
		//	is_shoot = false;
		//}

		if (is_shoot) {
			//b2Vec2 b2pos = m_circlebody->GetPosition();
			////cout << "y1 " << b2pos.y << endl;
			//b2pos.y += ((radius + 3)) / SCALE;
			////cout << "y2 " << b2pos.y << endl;
			//for (b2Body* it = World::world->GetBodyList(); it != 0; it = it->GetNext())
			//	for (b2Fixture* f = it->GetFixtureList(); f != 0; f = f->GetNext())
			//		if (f->TestPoint(b2pos)) {
			//			is_shoot = false;
			//		}
			//b2pos = m_circlebody->GetPosition();
			//b2pos.y -= ((radius + 3)) / SCALE;
			//for (b2Body* it = World::world->GetBodyList(); it != 0; it = it->GetNext())
			//	for (b2Fixture* f = it->GetFixtureList(); f != 0; f = f->GetNext())
			//		if (f->TestPoint(b2pos)) {
			//			is_shoot = false;
			//		}
			//b2pos = m_circlebody->GetPosition();
			//b2pos.x += ((radius + 3)) / SCALE;
			//for (b2Body* it = World::world->GetBodyList(); it != 0; it = it->GetNext())
			//	for (b2Fixture* f = it->GetFixtureList(); f != 0; f = f->GetNext())
			//		if (f->TestPoint(b2pos)) {

			//			is_shoot = false;

			//		}
			//b2pos = m_circlebody->GetPosition();
			//b2pos.x -= ((radius + 3)) / SCALE;
			//for (b2Body* it = World::world->GetBodyList(); it != 0; it = it->GetNext())
			//	for (b2Fixture* f = it->GetFixtureList(); f != 0; f = f->GetNext())
			//		if (f->TestPoint(b2pos)) {
			//			is_shoot = false;
			//		}


			m_circleshape.setPosition(m_circlebody->GetPosition().x * SCALE, m_circlebody->GetPosition().y * SCALE);
			//m_circleshape.setRotation(m_circlebody->GetAngle() * DEG);


		}
		if(!is_shoot) {
			m_bodyDef.type = b2_staticBody;
			
			//m_circlebody = World::world->CreateBody(&m_bodyDef);
			m_circleshape.setScale(5, 5);
			m_circleshape.setFillColor(Color::Red);
			timer_live -= System::time;
			if (timer_live < 0) {
				
				is_live = false;
			}
		}

	}
	void Draw() {
			System::wnd.draw(m_circleshape);					
	}
	bool Check_is_live() {
		return is_live;
	}
	void Action() {
		//cout << "TEST" << m_test << endl;
		//if (System::IsKeyPressed(Key::Z)) {
		//	m_test+=0.5;
		//}

		//if (System::IsKeyPressed(Key::X)) {
		//	m_test-= 0.5;
		//}
	}
	~Bullet() {
		//delete m_circlebody;
		//World::world->DestroyBody();
	}
};

