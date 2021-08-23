#pragma once
#include "System.h"
#include "World.h"
#include "Gun.h"
#include "GameStates.h"

class Player
{
private:
	PlayerDir m_dir = PlayerDir::RIGHT;

	float m_size_h;		// ������ �������
	float m_size_w;		// ������ �������
	const char* name;	// ���
	float massa;		// �����
	float width;		// ������ ���� ����� �������
	bool dinamic;		// ������������ ����
	bool fixRotat;		// ��������� ��������

	bool is_dead;

	// ����� ����� ������ �� �������� � �������
	float magic;
	float m_koeficent;

	// ��������� � ������
	Shape m_shape;

	b2PolygonShape m_box;
	b2CircleShape m_circle;
	b2BodyDef m_bodyDef;
	b2FixtureDef m_fdef;
	b2Body* m_body;

	// �����������
	float m_speed;

	float dx;
	float dy;

	float dxCam;
	float dyCam;
	// ��������� �������
	v2f m_firstPos;
	v2f m_size_map;


	Gun *MyFirstGun;
	b2Vec2 m_mouse;
	// �� �����
	bool is_onGround;
	// �����
	bool is_shoot;
	// ��������� ������
	bool is_button_Righr;
	bool is_button_Left;
	bool is_button_Up;


public:

	Player(v2f firstPos, v2f size_map);
	v2f GetPosition();
	v2f GetPosCam();
	float GetDx();
	b2Body* GetBody();
	void Action(StateGame &state_game);
	void Update(bool & is_reset);
	void Draw();

	~Player();
};




