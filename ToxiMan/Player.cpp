#pragma once
#include "Player.h"




Player::Player()
{
	// параметры игрока
	name = "player";
	massa = 20.f;
	m_size_h = 96;
	m_size_w = 96;
	magic = 2;
	width = m_size_w / magic; // Объем бокса влияет на скорость и импульс
	dinamic = true;	
	fixRotat = true;	
	// сщздание игрока
	m_shape = System::CreateShape(v2f(0, 0), v2f(96, m_size_h), System::resources.texture.player);	
	m_body = World::CreateBodyBox(m_shape, name, massa, width, true, true);
	 
	// движение
	m_speed = 0.5 * 5 / magic;
	dx = 0; dy = 0;

	is_onGround = false;
	
	MyFirstGun = new Gun(m_shape.getPosition(), m_dir);
}

void Player::Action(StateGame& state_game)
{
	if (System::IsKeyPressed(Key::F1) || System::IsKeyPressed(Key::F1)) {
		state_game = StateGame::ON_ARCITECT;
	}

	if (System::IsKeyReleased(Key::F1) || System::IsKeyReleased(Key::F1)) {

	}

	if (System::IsKeyPressed(Key::Left) || System::IsKeyPressed(Key::A)) {		
		dx = -m_speed;
	}

	if (System::IsKeyReleased(Key::Left) || System::IsKeyReleased(Key::A)) {
		dx = 0;
	}

	if (System::IsKeyPressed(Key::Right) || System::IsKeyPressed(Key::D)) {		
		dx = m_speed;
	}

	if (System::IsKeyReleased(Key::Right) || System::IsKeyReleased(Key::D)) {
		dx = 0;
	}
	
	if (System::IsKeyPressed(Key::Up) || System::IsKeyPressed(Key::W)) {
		if (is_onGround) {
			//m_body->ApplyLinearImpulse(b2Vec2(dx , (-400 / magic) * System::time), m_body->GetPosition(), true);
			m_body->ApplyLinearImpulseToCenter(b2Vec2(0 , (-400 / magic) * System::time), true);
			is_onGround = false;
		}
	}
		
	if ((System::IsKeyReleased(Key::Up) || System::IsKeyReleased(Key::W))) {

	}

	if (System::IsMousePressed(Button::Left)){
		MyFirstGun->shoot(m_shape.getPosition(), m_mouse, m_dir);

	}

	if (dx > 0)
		m_dir = PlayerDir::RIGHT;
	if (dx < 0)
		m_dir = PlayerDir::LEFT;

	MyFirstGun->Action();
}

void Player::Update()
{
	if(is_onGround)
		m_body->ApplyLinearImpulseToCenter(b2Vec2( dx * System::time, dy * System::time), true);
	else
		m_body->ApplyLinearImpulseToCenter(b2Vec2(dx * System::time / magic, dy * System::time), true);
	

	b2Vec2 pos = m_body->GetPosition();
	pos.y += ((m_size_h + 1) / 2) / SCALE;
	for (b2Body* it = World::world->GetBodyList(); it != 0; it = it->GetNext())
		for (b2Fixture* f = it->GetFixtureList(); f != 0; f = f->GetNext())
			if (f->TestPoint(pos)) { is_onGround = true; }


	m_shape.setPosition(m_body->GetPosition().x * SCALE, m_body->GetPosition().y * SCALE);
	m_shape.setRotation(m_body->GetAngle() * DEG);

	switch (m_dir) {
	case PlayerDir::RIGHT:
		m_shape.setScale(1, 1);
		break;
	case PlayerDir::LEFT:
		m_shape.setScale(-1, 1);
		break;
	default:
		break;
	}


	m_mouse.Set((System::cur_p_wnd.x - System::scr_w / 2) / magic, (System::cur_p_wnd.y - System::scr_h / 2) / magic);

	MyFirstGun->Update(m_shape.getPosition(), System::cur_p_wnd);
}

void Player::Draw()
{
	MyFirstGun->Draw();
	System::wnd.draw(m_shape);
}



v2f Player::GetPosition()
{	
	return m_shape.getPosition();
}

Player::~Player()
{
}
