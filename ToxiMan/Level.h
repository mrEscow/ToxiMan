#pragma once

#include "GameStates.h"
#include "ObjectManager.h"
#include "JsonSaveMenager.h"
#include "Player.h"
#include "Architect.h"


class Level
{
private:

	LevelNumber *m_ptr_number;

	JsonSaveMenager  m_jsonSM;

	v2f m_firstPos;
	v2f m_size_map;
	

	Player* m_ptr_player;

	Architect* m_ptr_arhitevt;

	bool is_from_arhitetc;

	vector<ObjectManager> m_objectListBeck;
	vector<ObjectManager> m_objectListZero;
	vector<ObjectManager> m_objectListFront;

	// Shader	

	//sf::Shader shaderOne;
	//sf::Shader shaderTwo;
	//sf::Shader shaderTree;

	//sf::Glsl::Vec2 offsetOne;
	//sf::Glsl::Vec2 offsetTwo;
	//sf::Glsl::Vec2 offsetTree;

	// Shader	

	sf::Shader shaderBg5_a;
	sf::Shader shaderBg5_b;
	sf::Shader shaderBg5_c;
	sf::Shader shaderBg5_d;
	sf::Shader shaderBg5_e;

	sf::Glsl::Vec2 offsetBg5_a;
	sf::Glsl::Vec2 offsetBg5_b;
	sf::Glsl::Vec2 offsetBg5_c;
	sf::Glsl::Vec2 offsetBg5_d;
	sf::Glsl::Vec2 offsetBg5_e;

	// beckground
	//Shape m_beckground;

	//Shape m_backOne;
	//Shape m_backTwo;
	//Shape m_backTree;

	// beckground2
	Shape m_bg5_a;
	Shape m_bg5_b;
	Shape m_bg5_c;
	Shape m_bg5_d;
	Shape m_bg5_e;

	Shape m_bg5_g;

public:

	v2f GetPositionPlayer();

	void LoadLevel(LevelNumber &number);


	Level(LevelNumber& number);
	void Action(StateGame& state_game, LevelNumber& number);
	void Update(StateGame& state_game, LevelNumber& number);
	void Draw(StateGame& state_game, LevelNumber& number);
	~Level();
};

