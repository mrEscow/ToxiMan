#pragma once
#include"System.h"
#include"World.h"
#include "ObjectManager.h"
#include "GameStates.h"
/*
		����������:
	a d s w  - �����.����
	q e - ���������� �������� 
	��� - ��������� ������
	��� - ������� ������
		���������:
	��� ������� �� ����� ��� ������ 32!
	Z - ��������� ��� �
	X - ��������� ��� �
	C - ��������� ��� Y
	V - ��������� ��� Y

*/
class Architect
{
	Shape m_shape;
	vector<ObjectManager> objectList;

	uint m_size_x;
	uint m_size_y;

public:
	Architect();
	void Action(StateGame& state_game);
	void DeleteObject();
	void Update();
	void Draw(StateGame& state_game);
	//~Architect();
};

