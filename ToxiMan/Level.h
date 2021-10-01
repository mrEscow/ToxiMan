#pragma once

#include "GameStates.h"
#include "ObjectManager.h"
#include "JsonSaveMenager.h"
#include "Player.h"
#include "Architect.h"
#include "AlgoritmLi.h"


class Level
{
private:

	LevelNumber *m_ptr_number;

	JsonSaveMenager  m_jsonSM;

	Map *m_map_ptr;

	v2f m_size_map;

	v2f m_StartPos;
	v2f m_FinishPos;
	
	Player* m_ptr_player;

	Architect* m_ptr_arhitevt;


	sf::Thread* m_ptr_thread;

	AlgoritmLi* m_ptr_Li;

	vector<v2f> m_Li_go;

	bool is_from_arhitetc;

	bool is_reset;
//protected:
	vector<ObjectManager> m_objectListBack;
	vector<ObjectManager> m_objectListZero;
	vector<ObjectManager> m_objectListFront;

private:
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
	Shape m_beckground;

	// beckground2
	Shape m_bg5_a;
	Shape m_bg5_b;
	Shape m_bg5_c;
	Shape m_bg5_d;
	Shape m_bg5_e;

	Shape m_bg5_g;

	// final point
	Shape m_s_final;

	void LI();

public:

	v2f GetPositionPlayer();

	void LoadLevel(LevelNumber &number);


	Level(LevelNumber& number, GameSettings& game_settings);

	void Action(StateGame& state_game, StateGame& previous_state, LevelNumber& number);
	void Update(StateGame& state_game, LevelNumber& number);
	void Draw(StateGame& state_game, LevelNumber& number);

	bool check_lvl();

	~Level();
};

