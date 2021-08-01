#pragma once
#include "bullet.h"
#include "GameStates.h"
class Gun {
private:
	Shape m_shape;
	b2Body* m_body;
	vector<Bullet> vec_bullets;
	PlayerDir m_dir;
	b2Vec2 m_mouse;
	
public:

	Gun(v2f pos,PlayerDir &dir) {

	}
	void shoot(v2f pos, b2Vec2 &mouse, PlayerDir &dir) {
		
		vec_bullets.push_back(Bullet(pos, mouse, dir));
	
	}
	void Update(v2f pos, v2f mouse) {

		for (auto &bullet : vec_bullets) { bullet.Update(); }
	}
	void Draw() {
		for (auto &bullet : vec_bullets) { bullet.Draw(); }

	}
	void Action() {
		for (auto &bullet : vec_bullets) { bullet.Action(); }

	}
};