#pragma once
#include "Map.h"

//#include "GameStates.h"
//#include "ObjectManager.h"
//#include "JsonSaveMenager.h"
//#include "Player.h"
//#include "Architect.h"
//#include "AlgoritmLi.h"

class Level
{
public:
	Map m_Map;
	//	BackGround m_BackGround;
	//	Objeckts m_Objekts;
	//	Enemy m_Enemy;
	//	Points m_Points;
	//	Coins m_Coins;
	//	Musiks m_Musics;

public:

};



//class Level
//{
//private:
//
//	std::map<uint32_t, Map> Maps;
//
//	GameStates* m_ptr_GS;
//
//	UINT32 m_GameLevel;
//
//
//	JsonSaveMenager  m_jsonSM;
//
//	//Map *m_map_ptr;
//
//	v2f m_size_map;
//
//	v2f m_StartPos;
//	v2f m_FinishPos;
//	
//	//Player* m_ptr_player;
//
//	Architect* m_ptr_arhitevt;
//
//
//	sf::Thread* m_ptr_thread;
//
//	AlgoritmLi* m_ptr_Li;
//
//	vector<v2f> m_Li_go;
//
//	bool is_from_arhitetc;
//
//	bool is_reset;
//
//	bool is_Next_Level;
//
//	vector<ObjectManager> m_objectListBack;
//	vector<ObjectManager> m_objectListZero;
//	vector<ObjectManager> m_objectListFront;
//
//	// Shader	
//	sf::Shader m_shader_start;
//	sf::Shader m_shader_stop;
//
//	sf::Shader shaderBg5_a;
//	sf::Shader shaderBg5_b;
//	sf::Shader shaderBg5_c;
//	sf::Shader shaderBg5_d;
//	sf::Shader shaderBg5_e;
//
//	sf::Glsl::Vec2 offsetBg5_a;
//	sf::Glsl::Vec2 offsetBg5_b;
//	sf::Glsl::Vec2 offsetBg5_c;
//	sf::Glsl::Vec2 offsetBg5_d;
//	sf::Glsl::Vec2 offsetBg5_e;
//
//	// beckground
//	Shape m_beckground;
//
//	// beckground2
//	Shape m_bg5_a;
//	Shape m_bg5_b;
//	Shape m_bg5_c;
//	Shape m_bg5_d;
//	Shape m_bg5_e;
//
//	Shape m_bg5_g;
//
//	// final point
//	Shape m_s_start;
//	Shape m_s_final;
//
//	float m_time = 0;
//
//	void LI();
//
//
//public:
//
//	v2f GetPositionPlayer();
//
//	void NextLevel();
//	void LoadLevel(UINT32 GameLevel);
//
//
//	Level(GameStates&, GameSettings& game_settings);
//
//	void Action(StateGame& state_game, StateGame& previous_state, UINT32 GameLevel);
//	void Update(StateGame& state_game, UINT32 GameLevel);
//	void Draw(StateGame& state_game, UINT32 GameLevel);
//
//	bool check_lvl();
//
//	~Level();
//};

