#pragma once
#include "Player.h"




Player::Player(v2f firstPos, v2f size_map)
{
	// параметры игрока
	name = "player";
	is_dead = false;
	massa = 10.f;
	m_size_h = 96;
	m_size_w = 96;
	magic = 2;
	width = m_size_w / magic; // Объем бокса влияет на скорость и импульс
	dinamic = true;	
	fixRotat = true;
	m_firstPos = firstPos;
	is_shoot = false;

	// для камеры
	m_size_map = size_map;

	// создание картинки игрока SFML
	m_shape = System::CreateShape(m_firstPos, v2f(m_size_w, m_size_h), System::resources.texture.player);

	// создание тела игрока BOX2D
	m_bodyDef.type = b2_dynamicBody;
	m_bodyDef.position.Set(m_firstPos.x / SCALE,m_firstPos.y / SCALE);

	m_body  = World::world->CreateBody(&m_bodyDef);

	m_fdef.density = massa;		// плотность (масса)
	m_fdef.restitution = 0; // упругость (от 0 до 1)
	m_fdef.friction = 1;		// трение (от 0 до 1)

	m_fdef.shape = &m_box;
	m_box.SetAsBox((m_size_w - width - 2) / 2 / SCALE , m_size_h / 4 / SCALE);
	m_body->CreateFixture(&m_fdef);

	m_circle.m_radius = (m_size_w - width) / 2 / SCALE;
	m_fdef.shape = &m_circle;
	m_circle.m_p.Set(0, m_size_h / 4 / SCALE);
	m_body->CreateFixture(&m_fdef);
	m_circle.m_p.Set(0, -m_size_h / 4 / SCALE);
	m_body->CreateFixture(&m_fdef);

	m_body->SetFixedRotation(true);
	 
	// движение
	m_koeficent = 10;
	m_speed = 0.4 * 5 / magic;
	dx = 0; dy = 0;
	is_onGround = false;
	// оружие
	MyFirstGun = new Gun(m_shape.getPosition());


	// состояния клавишь
	is_button_Righr	= false;
	is_button_Left	= false;
	is_button_Up	= false;
}

void Player::Action(StateGame& state_game)
{
	if (System::IsKeyPressed(Key::F1) || System::IsKeyPressed(Key::F1)) {
		state_game = StateGame::ON_ARCITECT;
	}

	if (System::IsKeyPressed(Key::Left) || System::IsKeyPressed(Key::A)) {	
		is_button_Left = true;
	}

	if (System::IsKeyReleased(Key::Left) || System::IsKeyReleased(Key::A)) {
		is_button_Left = false;
	}

	if (System::IsKeyPressed(Key::Right) || System::IsKeyPressed(Key::D)) {	
		is_button_Righr = true;
	}

	if (System::IsKeyReleased(Key::Right) || System::IsKeyReleased(Key::D)) {
		is_button_Righr = false;

	}

	if (System::IsKeyPressed(Key::Up)|| System::IsKeyPressed(Key::W)) {
		is_button_Up = true;
	}

	if (System::IsKeyReleased(Key::Up) || System::IsKeyReleased(Key::W)) {
		is_button_Up = false;
	}
		
	if (System::IsMousePressed(Button::Left)){
		is_shoot = true;
	}
	if (System::IsMouseReleased(Button::Left)) {
		is_shoot = false;
	}

	MyFirstGun->Action();
}

void Player::Update(bool & is_reset)
{
	if (is_button_Left) dx = -m_speed;
	if (is_button_Righr) dx = m_speed;
	if (!is_button_Left && !is_button_Righr) dx = 0;

	if (is_button_Up) 
		if (is_onGround) 
			m_body->ApplyLinearImpulseToCenter(b2Vec2(0, (-190 / magic) * m_koeficent), true);
		
	if (dx > 0)
		m_dir = PlayerDir::RIGHT;
	if (dx < 0)
		m_dir = PlayerDir::LEFT;

	if(m_body->GetLinearVelocity().y == 0)
		is_onGround = true;
	else
		is_onGround = false;

	if (is_onGround) {
		if (m_body->GetLinearVelocity().x < -10)
			m_body->SetLinearVelocity(b2Vec2(-10, 0));
		if (m_body->GetLinearVelocity().x > 10)
			m_body->SetLinearVelocity(b2Vec2(10, 0));
			m_body->SetLinearVelocity(b2Vec2(7 * dx, 0));
		m_body->ApplyLinearImpulseToCenter(b2Vec2(dx * m_koeficent, dy * m_koeficent), true);
	}
	else {
		//m_body->SetLinearVelocity(b2Vec2(7 * dx, 5 * dy));
		m_body->ApplyLinearImpulseToCenter(b2Vec2(dx * m_koeficent / 5, dy * m_koeficent ), true);
	}


	m_body->SetLinearDamping(0.1); // затухание 

	m_shape.setPosition(m_body->GetPosition().x * SCALE, m_body->GetPosition().y * SCALE);
	m_shape.setRotation(m_body->GetAngle() * DEG);

	if (!System::IsShapeInCamera(m_shape))
		is_dead = true;
	 
	if (is_dead) {
		is_reset = true;
		m_body->SetTransform(b2Vec2(m_firstPos.x / SCALE, m_firstPos.y / SCALE), m_body->GetAngle());
		is_dead = false;
	}

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

	if (is_shoot) {
		MyFirstGun->shoot(m_dir);
	}

	MyFirstGun->Update(m_shape.getPosition(), m_dir);	
}

void Player::Draw()
{	
	System::wnd.draw(m_shape);
	MyFirstGun->Draw();
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
	World::world->DestroyBody(m_body);
	delete MyFirstGun;
}

float Player::GetDx()
{
	return dx;
}

b2Body* Player::GetBody()
{
	return m_body;
}
