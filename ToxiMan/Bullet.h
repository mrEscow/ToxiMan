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
	float timer_live = 2000; // 60000 минута
public:
	b2Body* m_circlebody;
	b2FixtureDef m_fixDef;
	//  всё под корнем (x2-x1)2+(y2-y1)2
	//	static int ammo_counter;
	Bullet(Shape &gunPos, PlayerDir &dir) {
		// круглая пуля
		m_massa = 0.5;
		//magic = 10;
		radius = 20;
		sizeGun = 10;
		is_shoot = false;

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
				m_fixDef.restitution = 1; // упругость (от 0 до 1)
				m_fixDef.friction = 1;		// трение (от 0 до 1)
				m_fixDef.shape = &m_circle;


				m_circlebody->CreateFixture(&m_fixDef);
				m_circlebody->SetGravityScale(0);
				m_circlebody->SetBullet(true);
				m_circlebody->SetAngularDamping(1);

				m_circlebody->ApplyLinearImpulseToCenter(b2Vec2(10,0), true);
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
				m_fixDef.restitution = 1; // упругость (от 0 до 1)
				m_fixDef.friction = 1;		// трение (от 0 до 1)
				m_fixDef.shape = &m_circle;

				m_circlebody->CreateFixture(&m_fixDef);
				m_circlebody->SetGravityScale(0);
				m_circlebody->SetBullet(true);
				m_circlebody->SetAngularDamping(1);
				m_circlebody->ApplyLinearImpulseToCenter(b2Vec2(-10, 0), true);
			//}			
			break;
		default:
			
			break;
		}
	}
	void Update() {

		cout << "timer_live: "<< timer_live << endl;
		timer_live -= System::time;
		if(timer_live < 0)
			is_live = false;

		if (is_shoot) {
			b2Vec2 b2pos = m_circlebody->GetPosition();
			//cout << "y1 " << b2pos.y << endl;
			b2pos.y += ((radius + 1)) / SCALE;
			//cout << "y2 " << b2pos.y << endl;
			for (b2Body* it = World::world->GetBodyList(); it != 0; it = it->GetNext())
				for (b2Fixture* f = it->GetFixtureList(); f != 0; f = f->GetNext())
					if (f->TestPoint(b2pos)) {
						//cout << "y+ " << b2pos.y << endl;
						//is_live = false;
						//m_mouse.Set(0, 0); 
						//World::world->DestroyBody(m_circlebody);
						//m_circlebody->DestroyFixture(f);
						//this->~Bullet();
					}
			b2pos = m_circlebody->GetPosition();
			b2pos.y -= ((radius - 1)) / SCALE;
			for (b2Body* it = World::world->GetBodyList(); it != 0; it = it->GetNext())
				for (b2Fixture* f = it->GetFixtureList(); f != 0; f = f->GetNext())
					if (f->TestPoint(b2pos)) {
						//cout << "y- " <<  b2pos.y << endl;
						//is_live = false;
						//m_mouse.Set(0, 0); 
						//World::world->DestroyBody(m_circlebody);
						//m_circlebody->DestroyFixture(f);
						//this->~Bullet();
					}
			b2pos = m_circlebody->GetPosition();
			b2pos.x += ((radius + 1)) / SCALE;
			for (b2Body* it = World::world->GetBodyList(); it != 0; it = it->GetNext())
				for (b2Fixture* f = it->GetFixtureList(); f != 0; f = f->GetNext())
					if (f->TestPoint(b2pos)) {
						//cout << "x+ " << b2pos.x << endl;
						//is_live = false;
						//m_mouse.Set(0, 0);
						//World::world->DestroyBody(m_circlebody);
						//m_circlebody->DestroyFixture(f);
						//this->~Bullet();
					}
			b2pos = m_circlebody->GetPosition();
			b2pos.x -= ((radius - 1)) / SCALE;
			for (b2Body* it = World::world->GetBodyList(); it != 0; it = it->GetNext())
				for (b2Fixture* f = it->GetFixtureList(); f != 0; f = f->GetNext())
					if (f->TestPoint(b2pos)) {
						//cout << "x- " << b2pos.x << endl;
						//is_live = false;
						//m_mouse.Set(0, 0); 
						//World::world->DestroyBody(m_circlebody);
						//m_circlebody->DestroyFixture(f); 
						//this->~Bullet();
					}


			m_circleshape.setPosition(m_circlebody->GetPosition().x * SCALE, m_circlebody->GetPosition().y * SCALE);
			m_circleshape.setRotation(m_circlebody->GetAngle() * DEG);


		}

	}
	void Draw() {
		if (is_shoot)
			System::wnd.draw(m_circleshape);		
			
	}
	bool Check_is_live() {
		return is_live;
	}
	void Action() {
		
	}
	~Bullet() {
		//delete m_circlebody;
		//World::world->DestroyBody();
	}
};

