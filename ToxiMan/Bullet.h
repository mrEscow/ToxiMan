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
	b2CircleShape m_circle;
	b2Body* m_circlebody;

	//b2Vec2 m_mouse;
	float m_massa;

	int		magic;
	float	radius;
	float	dx;
	float	sizeGun;
	

	bool	is_shoot;
public:

	//static int ammo_counter;
	Bullet(v2f pos, b2Vec2 &mouse, PlayerDir &dir) {
		// круглая пуля
		m_massa = 0.5;
		magic = 30;
		radius = 20;
		sizeGun = 5;
		is_shoot = false;
		switch (dir)
		{
		case PlayerDir::RIGHT:
			
			if (mouse.x > 0) {
				is_shoot = true;
				m_circleshape = System::CreateCircleShape(pos, radius, 30, -3, Color::Green, Color::Black);
				m_bodyDef.position.Set((m_circleshape.getPosition().x + sizeGun) / SCALE, m_circleshape.getPosition().y / SCALE);
				m_bodyDef.type = b2_dynamicBody;
				m_circle.m_radius = m_circleshape.getRadius() / SCALE;
				m_circlebody = World::world->CreateBody(&m_bodyDef);
				m_circlebody->CreateFixture(&m_circle, m_massa);
				m_circlebody->SetBullet(false);
				m_circlebody->SetAngularDamping(10);
				m_circlebody->ApplyLinearImpulseToCenter(mouse, true);
			}			
			break;
		case PlayerDir::LEFT:
			if (mouse.x < 0) {
				is_shoot = true;
				m_circleshape = System::CreateCircleShape(pos, radius, 30, -3, Color::Green, Color::Black);
				m_bodyDef.position.Set((m_circleshape.getPosition().x - sizeGun) / SCALE, m_circleshape.getPosition().y / SCALE);
				m_bodyDef.type = b2_dynamicBody;
				m_circle.m_radius = m_circleshape.getRadius() / SCALE;
				m_circlebody = World::world->CreateBody(&m_bodyDef);
				m_circlebody->CreateFixture(&m_circle, m_massa);
				m_circlebody->SetBullet(false);
				m_circlebody->SetAngularDamping(10);
				m_circlebody->ApplyLinearImpulseToCenter(mouse, true);
			}			
			break;
		default:
			break;
		}
	}
	~Bullet() {
		
	}
	void Update() {
		if (is_shoot) {
			b2Vec2 b2pos = m_circlebody->GetPosition();
			b2pos.y += ((radius + 1)) / SCALE;
			for (b2Body* it = World::world->GetBodyList(); it != 0; it = it->GetNext())
				for (b2Fixture* f = it->GetFixtureList(); f != 0; f = f->GetNext())
					if (f->TestPoint(b2pos)) {
						//m_mouse.Set(0, 0); 
						//World::world->DestroyBody(m_circlebody);
						//m_circlebody->DestroyFixture(f);
						//this->~Bullet();
					}
			b2pos.y -= ((radius + 1)) / SCALE;
			for (b2Body* it = World::world->GetBodyList(); it != 0; it = it->GetNext())
				for (b2Fixture* f = it->GetFixtureList(); f != 0; f = f->GetNext())
					if (f->TestPoint(b2pos)) {
						//m_mouse.Set(0, 0); 
						//World::world->DestroyBody(m_circlebody);
						//m_circlebody->DestroyFixture(f);
						//this->~Bullet();
					}
			b2pos.x += ((radius + 1)) / SCALE;
			for (b2Body* it = World::world->GetBodyList(); it != 0; it = it->GetNext())
				for (b2Fixture* f = it->GetFixtureList(); f != 0; f = f->GetNext())
					if (f->TestPoint(b2pos)) {
						//m_mouse.Set(0, 0);
						//World::world->DestroyBody(m_circlebody);
						//m_circlebody->DestroyFixture(f);
						//this->~Bullet();
					}
			b2pos.x -= ((radius + 1)) / SCALE;
			for (b2Body* it = World::world->GetBodyList(); it != 0; it = it->GetNext())
				for (b2Fixture* f = it->GetFixtureList(); f != 0; f = f->GetNext())
					if (f->TestPoint(b2pos)) {
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
	bool Check_is_shoot() {
		return is_shoot;
	}
	void Action() {
		
	}
};

