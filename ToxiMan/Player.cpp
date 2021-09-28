#pragma once
#include "Player.h"
#include "AlgoritmLi.h"


Player::Player(Map &map, v2f firstPos, v2f size_map)
{
	m_map = &map;

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
	m_firstPos = m_map->GetStartPos();
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
	m_speed = 0.4f * 5 / magic;
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
		
	if (System::IsMousePressed(MouseButton::Left)){
		is_shoot = true;
	}
	if (System::IsMouseReleased(MouseButton::Left)) {
		is_shoot = false;
	}

	MyFirstGun->Action();
}

void Player::Update(bool & is_reset)
{

	cout << m_map->GetStartPos().x << endl;
	cout << m_map->GetStartPos().y << endl;

	m_firstPos = m_map->GetStartPos();
	

	if (m_shape.getPosition().x - System::cam.getCenter().x > 1.5)
		dxCam = 1;
	if (m_shape.getPosition().x - System::cam.getCenter().x < 1.5)
		dxCam = -1;
	//if (m_shape.getPosition().x - System::cam.getCenter().x == 0)
	//	dxCam = 0;

	if (m_shape.getPosition().y - System::cam.getCenter().y > 1.5)
		dyCam = 1;
	if (m_shape.getPosition().y - System::cam.getCenter().y < 1.5)
		dyCam = -1;
	//if (m_shape.getPosition().y - System::cam.getCenter().y == 0)
	//	dyCam = 0;

	v2f dCam = v2f(dxCam, dyCam);
	v2f go = v2f(m_body->GetLinearVelocity().x * System::time, m_body->GetLinearVelocity().y * System::time) / 25.f;

	if (go == v2f(0, 0)) {
		dCam.x *= 0.1f * System::time;
		dCam.y *= 0.1f * System::time;
		//cout << "true" << endl;
		//cout << dCam.x << endl;
		//cout << dCam.y << endl;
	}

	else {
		dCam = v2f(dxCam, dyCam) + go;
		//cout << "false" << endl;
		//cout << dCam.x << endl;
		//cout << dCam.y << endl;
	}



	//v2f go = v2f(m_body->GetLinearVelocity().x , m_body->GetLinearVelocity().y);
	//v2f dCam = v2f(dxCam, dyCam) * 1.5f + v2f(go);

	//cout << System::cam.getCenter().x - m_shape.getPosition().x << endl;
	//if (System::cam.getCenter() != m_shape.getPosition())
	//		System::cam.move(dCam );
	if (!System::IsContains(m_shape, System::cam.getCenter() + v2f(1, 1)) && !System::IsContains(m_shape, System::cam.getCenter() - v2f(1, 1))) {

	System::cam.move(dCam);

	}
	else
		dCam = v2f(0, 0);


	System::wnd.setView(System::cam);

	if (is_button_Left) 
		dx = -m_speed;
	if (is_button_Righr)
		dx = m_speed;


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


	m_body->SetLinearDamping(0.1f); // затухание 

	m_shape.setPosition(m_body->GetPosition().x * SCALE, m_body->GetPosition().y * SCALE);
	m_shape.setRotation(m_body->GetAngle() * static_cast<float> (DEG));

	if (!System::IsShapeInCamera(m_shape))
		is_dead = true;
	 
	if (is_dead) {
		is_reset = true;
		m_body->SetTransform(b2Vec2(m_map->GetStartPos().x / SCALE, m_map->GetStartPos().y / SCALE), m_body->GetAngle());
		System::cam.setCenter(m_shape.getPosition());
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
		x = (System::scr_w - 64.f) / 2.f;
	if (m_shape.getPosition().x > ((64 * m_size_map.x) - 32) - ((System::scr_w) / 2))
		x = ((64 * m_size_map.x) - 32) - ((System::scr_w) / 2);

	if (m_shape.getPosition().y > ((System::scr_h + (64 * m_size_map.y)) / 2) - 128 - 16)
		y = ((System::scr_h + (64 * m_size_map.y)) / 2) - 128 - 16;

	if (m_shape.getPosition().y < (System::scr_h / 2) - 32)
		y = (System::scr_h / 2.f) - 32.f;

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
