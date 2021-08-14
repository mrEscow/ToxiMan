#pragma once
#include "System.h"
#include "World.h"
#include "Boby.h"
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

	// ����� ����� ������ �� �������� � �������
	float magic;		

	Shape m_shape;
	b2Body* m_body;

	float m_speed;
	bool is_onGround;
	float dx;
	float dy;
	// ��������� �������
	v2f m_firstPos;
	// �����
	Gun *MyFirstGun;
	b2Vec2 m_mouse;

public:

	Player(v2f firstPos);
	v2f GetPosition();
	void Action(StateGame &state_game);
	void Update();
	void Draw();

	~Player();
};




