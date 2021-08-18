#pragma once
#include "System.h"
#include "World.h"
#include "GameStates.h"


class Bullet{

public:
	PlayerDir m_dir;

	CircleShape m_circleshape;
	b2BodyDef m_bodyDef;
	b2CircleShape m_circle;
	b2Body* m_circlebody; 
	b2FixtureDef m_fixDef;
	

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
	

	Bullet(Shape &gunPos, PlayerDir &dir) {

		m_dir = dir;
		m_massa = 0.5;
		radius = 20;
		sizeGun = 10;

		is_shoot = true;
		is_live = true;


		

		switch (dir)
		{
		case PlayerDir::RIGHT:
			
				m_circleshape = System::CreateCircleShape(v2f(gunPos.getPosition().x + 5 + (gunPos.getSize().x / 2), gunPos.getPosition().y), radius, 30, -3, Color::Green, Color::Black);
				m_bodyDef.position.Set((gunPos.getPosition().x + 5 + (gunPos.getSize().x / 2)) / SCALE, m_circleshape.getPosition().y / SCALE);
				m_bodyDef.type = b2_dynamicBody;				
				m_circle.m_radius = m_circleshape.getRadius() / SCALE;
				if (World::world->IsLocked()) {
					is_live = false;
				}
				else {
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
					//m_circlebody->
					//m_circlebody->ApplyLinearImpulse(b2Vec2(System::cur_p.x, System::cur_p.y), b2Vec2(15, 0),true);
					m_circlebody->ApplyLinearImpulseToCenter(b2Vec2(15, 0), true);
				}

	
			break;
		case PlayerDir::LEFT:

				m_circleshape = System::CreateCircleShape(v2f(gunPos.getPosition().x - 5 - (gunPos.getSize().x / 2), gunPos.getPosition().y), radius, 30, -3, Color::Green, Color::Black);
				m_bodyDef.position.Set((gunPos.getPosition().x - 5 - (gunPos.getSize().x / 2)) / SCALE, m_circleshape.getPosition().y / SCALE);
				m_bodyDef.type = b2_dynamicBody;
				m_circle.m_radius = m_circleshape.getRadius() / SCALE;					
				if (World::world->IsLocked()) {
					is_live = false;
				}
				else {
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
				}
					
			break;
		default:
			
			break;
		}
	}

	void Update(PlayerDir& dir) {

		if (is_shoot) {
			if (m_circlebody->GetLinearVelocity().y != 0)
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

			m_circleshape.setPosition(m_circlebody->GetPosition().x * SCALE, m_circlebody->GetPosition().y * SCALE);
			
		}
		if(!is_shoot) {
			//m_bodyDef.type = b2_staticBody;
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

	}
	~Bullet() {

	}
};

