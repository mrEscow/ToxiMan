#pragma once
#include "System.h"
#include "World.h"
#include "ObjectManager.h"
#include "GameStates.h"
#include "Player.h"
#include "JsonSaveMenager.h"
#include "ArchtectMenu.h"

/*
	Управление:
	a d s w  - вверх.вниз
	q e - приблизить отдалить 
	ЛКМ - поставить объект
	ПКМ - удалить объект

	Параметры:
	Все объекты по одной оси кратны 64!
	//Z - уменьшить ось Х
	//X - увеличить ось Х
	//C - уменьшить ось Y
	//V - увеличить ось Y
	функция отключина

*/
class Architect
{
	std::map<uint32_t, Map>* m_Maps;

	ArcitectVector m_Z_vec = ArcitectVector::ZERO;

	ArchtectMenu *m_ptr_menu;

	//friend AlgoritmLi;

	//Map *m_map_ptr;

	Shape	m_mouse;

	Shape	m_start;
	Shape	m_finish;

	//float	m_zoom;

	vector<ObjectManager>::iterator it;

	vector<ObjectManager> *m_ptr_objectListBack;
	vector<ObjectManager> *m_ptr_objectListZero;
	vector<ObjectManager> *m_ptr_objectListFront;

	vector<Shape> m_cell_vec;


	uint m_size_x;
	uint m_size_y;

	Shape m_cell;

	//menu
	bool is_grid;

	bool is_create;

	bool is_next;

	bool is_delete;

	bool is_back;

	//map

	bool is_new_start;
	bool is_new_finish;
	bool is_save_map;
	bool is_next_level;

public:
	Architect(std::map<uint32_t, Map>& Maps, vector<ObjectManager>& objectListBack, vector<ObjectManager>& objectListZero, vector<ObjectManager>& objectListFront, v2f size_map, GameSettings& game_settings);

	void Action(StateGame& state_game, StateGame& previous_state, bool& is_from_arhitetc,JsonSaveMenager &jsonSM, UINT32 GameLevel, bool& is_Next_Level);

	void Update();

	void Draw(StateGame& state_game);

	void CreateObject();

	void DeleteObject();

	void CreateStart();

	void CreateFinish();

	vector<ObjectManager>& GetVecZero();
	vector<Shape>& GetVecCell();


	//Map GetMap();

	~Architect();
};

