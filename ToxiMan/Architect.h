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
	ArchtectMenu m_menu;

	Shape	m_mouse;

	//v2f		m_zoom;
	float	m_zoom;

	ArcitectVector m_Z_vec = ArcitectVector::ZERO;

	vector<ObjectManager>::iterator it;

	vector<ObjectManager> *m_ptr_objectListBeck;
	vector<ObjectManager> *m_ptr_objectListZero;
	vector<ObjectManager> *m_ptr_objectListFront;

	uint m_size_x;
	uint m_size_y;

	// Сетка
	Shape m_cell;
	vector<Shape> m_cell_vec;


public:
	Architect(vector<ObjectManager>&objectListBeck, vector<ObjectManager>&objectListZero,vector<ObjectManager>&objectListFront, v2f size_map);

	void Action(StateGame& state_game, bool& is_from_arhitetc,JsonSaveMenager &jsonSM, LevelNumber& number);

	void CreateObject();

	void DeleteObject();

	void Update();

	void Draw(StateGame& state_game, Player* player);
	//~Architect();
};

