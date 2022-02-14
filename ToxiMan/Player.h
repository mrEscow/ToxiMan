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
//	float m_size_h;		// высота спрайта
//	float m_size_w;		// ширина спрайта
//	const char* name;	// им€
//	float massa;		// масса
//	float width;		// делаем бокс поуже спрайта
//	bool dinamic;		// динамический бокс
//	bool fixRotat;		// запретить повороты
//
//	bool is_dead;
//
//	// ќбъем бокса вли€ет на скорость и импульс
//	float magic;
//	float m_koeficent;
//
//	// отрисовка и физика
//	Shape m_shape;
//
//	b2PolygonShape m_box;
//	b2CircleShape m_circle;
//	b2BodyDef m_bodyDef;
//	b2FixtureDef m_fdef;
//	b2Body* m_body;
//
//	// перемещение
//	float m_speed;
//
//	float dx;
//	float dy;
//
//	float dxCam;
//	float dyCam;
//	// начальна€ позици€
//	v2f m_firstPos;
//	v2f m_size_map;
//
//
//	Gun *MyFirstGun;
//	b2Vec2 m_mouse;
//	// на земле
//	bool is_onGround;
//	// пушка
//	bool is_shoot;
//	// состо€ни€ клавиш
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
//	LifeBar lifeBarPlayer;//экземпл€р класса полоски здоровь€
//	int m_life;
//
//	// Ўейдер
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




