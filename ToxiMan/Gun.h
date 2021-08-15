#pragma once
#include "bullet.h"
#include "GameStates.h"
class Gun {
private:
	Shape m_shape;
	//b2Body* m_body;
	vector<Bullet> vec_bullets;
	
	PlayerDir m_dir;
	b2Vec2 m_mouse;
	
public:

	Gun(v2f pos) {
		m_shape = System::CreateShape(pos, v2f(80, 30),System::resources.texture.skaermbillede);
	}
	void shoot(PlayerDir dir) {
		
		vec_bullets.push_back(Bullet(m_shape,dir));
	
	}
	void Update(v2f playerPos, PlayerDir dir) {
		switch (dir)
		{
		case PlayerDir::RIGHT:
			m_shape.setPosition(v2f(playerPos.x + 15, playerPos.y + 15) );
			m_shape.setRotation(1);
			m_shape.setScale(1, 1);
			break;
		case PlayerDir::LEFT:
			m_shape.setPosition(v2f(playerPos.x - 15, playerPos.y + 15));
			m_shape.setScale(-1, 1);
			break;
		default:
			break;
		}



		//m_shape.setRotation();
		//for (auto &bullet : vec_bullets) { bullet.Update(); }

		for (auto it = vec_bullets.begin(); it != vec_bullets.end(); ) {
			auto& object = it;
			if (object->Check_is_live()) { object->Update(); it++; }
			else { it = vec_bullets.erase(it); }				
		}


		//for (auto it = vec_bullets.begin(); it != vec_bullets.end(); it++) {
		//	auto& object = it;
		//	if (object->Check_is_live()) { object->Update(); it++; }
		//	else { it = vec_bullets.erase(it); }
		//}

	}
	void Draw() {
		for (auto &bullet : vec_bullets) { bullet.Draw(); }
		System::wnd.draw(m_shape);

	}
	void Action() {
		for (auto &bullet : vec_bullets) { bullet.Action(); }

	}
	~Gun() {
		//World::world->DestroyBody(m_body);
	}
};