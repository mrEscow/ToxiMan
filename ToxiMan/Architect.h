#pragma once
#include"System.h"
#include"World.h"
#include "ObjectManager.h"
#include "GameStates.h"
/*
		Управление:
	a d s w  - вверх.вниз
	q e - приблизить отдалить 
	ЛКМ - поставить объект
	ПКМ - удалить объект
		Параметры:
	Все объекты по одной оси кратны 32!
	Z - уменьшить ось Х
	X - увеличить ось Х
	C - уменьшить ось Y
	V - увеличить ось Y

*/
class Architect
{
	Shape m_shape;
	vector<ObjectManager> objectList;

public:
	Architect();
	void Action(StateGame& state_game);
	void DeleteObject();
	void Update();
	void Draw(StateGame& state_game);
	//~Architect();
};

