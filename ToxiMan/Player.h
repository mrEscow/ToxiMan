#pragma once
#include "System.h"
#include "World.h"
#include "Gun.h"
#include "GameStates.h"
#include "Map.h"
#include "Timer.h"
#include "LifeBar.h"

//class Player
//{
//private:
//	PlayerDir m_dir = PlayerDir::RIGHT;
//
//	float m_size_h;		// ������ �������
//	float m_size_w;		// ������ �������
//	const char* name;	// ���
//	float massa;		// �����
//	float width;		// ������ ���� ����� �������
//	bool dinamic;		// ������������ ����
//	bool fixRotat;		// ��������� ��������
//
//	bool is_dead;
//
//	// ����� ����� ������ �� �������� � �������
//	float magic;
//	float m_koeficent;
//
//	// ��������� � ������
//	Shape m_shape;
//
//	b2PolygonShape m_box;
//	b2CircleShape m_circle;
//	b2BodyDef m_bodyDef;
//	b2FixtureDef m_fdef;
//	b2Body* m_body;
//
//	// �����������
//	float m_speed;
//
//	float dx;
//	float dy;
//
//	float dxCam;
//	float dyCam;
//	// ��������� �������
//	v2f m_firstPos;
//	v2f m_size_map;
//
//
//	Gun *MyFirstGun;
//	b2Vec2 m_mouse;
//	// �� �����
//	bool is_onGround;
//	// �����
//	bool is_shoot;
//	// ��������� ������
//	bool is_button_Righr;
//	bool is_button_Left;
//	bool is_button_Up;
//
//	Map *m_map;
//
//	//enum class eDirection : uint
//	//{
//	//	UP,
//	//	UP_RIGHT,
//	//	RIGHT,
//	//	DOWN_RIGHT,
//	//	DOWN,
//	//	DOWN_LEFT,
//	//	LEFT,
//	//	UP_LEFT
//	//};
//
//	//eDirection eDir;
//
//	bool is_li_go;
//	v2f m_v2f_go;
//
//	bool a; //= false;
//	bool b; //= false;
//	bool c; //= true;
//
//	Escow::Timer testTimer;
//
//	LifeBar lifeBarPlayer;//��������� ������ ������� ��������
//	int m_life;
//
//	// ������
//	sf::Shader m_shader;
//
//	float ms_time;
//	sf::Time mst_time;
//
//	sf::Shader m_shader_fire;
//	Shape m_shape_fire;
//
//
//
//public:
//
//	Player(Map& map,v2f firstPos, v2f size_map);
//	v2f GetPosition();
//	v2f GetPosCam();
//	float GetDx();
//	b2Body* GetBody();
//	void Action(StateGame &state_game);
//	void Update(bool & is_reset);
//	void Draw();
//
//	~Player();
//};




