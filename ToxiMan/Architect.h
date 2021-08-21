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

	Выбор вектора объектов:
	Num1 - Vector BECK  (Только для рисования)
	Num2 - Vector ZERO  (Только для игровых объектов)
	Num3 - Vector FRONT (Только для рисования)

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
	ArcitectVector m_Z_vec = ArcitectVector::ZERO;


	ArchtectMenu *m_ptr_menu;

	Shape	m_mouse;

	float	m_zoom;

	vector<ObjectManager>::iterator it;

	vector<ObjectManager> *m_ptr_objectListBeck;
	vector<ObjectManager> *m_ptr_objectListZero;
	vector<ObjectManager> *m_ptr_objectListFront;

	uint m_size_x;
	uint m_size_y;

	Shape m_cell;
	vector<Shape> m_cell_vec;

	bool is_create;
	bool is_delete;

public:
	Architect(vector<ObjectManager>&objectListBeck, vector<ObjectManager>&objectListZero,vector<ObjectManager>&objectListFront, v2f size_map, GameSettings& game_settings);

	void Action(StateGame& state_game, bool& is_from_arhitetc,JsonSaveMenager &jsonSM, LevelNumber& number);

	void Update(StateGame& state_game);

	void Draw(StateGame& state_game, Player* player);

	void CreateObject();

	void DeleteObject();

	~Architect();
};

