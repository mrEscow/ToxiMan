#pragma once
#include "Player.h"




Player::Player(v2f firstPos, v2f size_map)
{
	// параметры игрока
	name = "player";
	massa = 10.f;
	m_size_h = 96;
	m_size_w = 96;
	magic = 2;
	width = m_size_w / magic; // ќбъем бокса вли€ет на скорость и импульс
	dinamic = true;	
	fixRotat = true;
	m_firstPos = firstPos;
	// дл€ камеры
	m_size_map = size_map;
	// создание картинки игрока SFML
	m_shape = System::CreateShape(m_firstPos, v2f(m_size_w, m_size_h), System::resources.texture.player);
	// создание тела игрока BOX2D
	b2PolygonShape box;
	b2CircleShape circle;

	b2BodyDef bodyDef;
	bodyDef.type = b2_dynamicBody;
	bodyDef.position.Set(m_firstPos.x / SCALE,m_firstPos.y / SCALE);

	b2Body* body = World::world->CreateBody(&bodyDef);
	b2FixtureDef fdef;
	fdef.density = massa;		// плотность (масса)
	fdef.restitution = 0; // упругость (от 0 до 1)
	fdef.friction = 1;		// трение (от 0 до 1)

	fdef.shape = &box;
	box.SetAsBox((m_size_w - width - 2) / 2 / SCALE , m_size_h / 4 / SCALE);
	body->CreateFixture(&fdef);

	circle.m_radius = (m_size_w - width) / 2 / SCALE;
	fdef.shape = &circle;
	circle.m_p.Set(0, m_size_h / 4 / SCALE);
	body->CreateFixture(&fdef);
	circle.m_p.Set(0, -m_size_h / 4 / SCALE);
	body->CreateFixture(&fdef);

	body->SetFixedRotation(true);

	m_body = body;
	//m_body = World::CreateBodyBox(m_shape, name, massa, width, true, true);
	 
	// движение
	m_speed = 0.4 * 5 / magic;
	dx = 0; dy = 0;
	is_onGround = false;
	// оружие
	MyFirstGun = new Gun(m_shape.getPosition(), m_dir);
}

void Player::Action(StateGame& state_game)
{
	if (System::IsKeyPressed(Key::F1) || System::IsKeyPressed(Key::F1)) {
		// GET OBJECT FIXIT
		state_game = StateGame::ON_ARCITECT;
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

			m_body->ApplyLinearImpulseToCenter(b2Vec2(0, (-190 / magic) * System::time), true);
		}
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

	if(m_body->GetLinearVelocity().y == 0)
		is_onGround = true;
	else
		is_onGround = false;


	if (is_onGround) {
		if (m_body->GetLinearVelocity().x < -10)
			m_body->SetLinearVelocity(b2Vec2(-10, 0));
		if (m_body->GetLinearVelocity().x > 10)
			m_body->SetLinearVelocity(b2Vec2(10, 0));
		m_body->ApplyLinearImpulseToCenter(b2Vec2(dx * System::time, dy * System::time), true);
	}
	else {
		m_body->ApplyLinearImpulseToCenter(b2Vec2(dx * System::time / (magic * 2), dy * System::time * World::gravity), true);
	}

	m_body->SetLinearDamping(0.1); // затухание 

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

v2f Player::GetPosCam()
{
	v2f temp;
	float
		x = m_shape.getPosition().x,
		y = m_shape.getPosition().y;

	if (m_shape.getPosition().x < (System::scr_w - 64) / 2)
		x = (System::scr_w - 64) / 2;
	if (m_shape.getPosition().x > ((64 * m_size_map.x) - 32) - ((System::scr_w) / 2))
		x = ((64 * m_size_map.x) - 32) - ((System::scr_w) / 2);

	if (m_shape.getPosition().y > ((System::scr_h + (64 * m_size_map.y)) / 2) - 128 - 16)
		y = ((System::scr_h + (64 * m_size_map.y)) / 2) - 128 - 16;

	if (m_shape.getPosition().y < (System::scr_h / 2) - 32)
		y = (System::scr_h / 2) - 32;

	temp = v2f(x, y);

	return temp;
}


v2f Player::GetPosition()
{
	return m_shape.getPosition();
}

Player::~Player()
{
}
