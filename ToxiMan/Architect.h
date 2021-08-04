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

	����� ������� ��������:
	Num1 - Vector BECK  (������ ��� ���������)
	Num2 - Vector ZERO  (������ ��� ������� ��������)
	Num3 - Vector FRONT (������ ��� ���������)

	���������:
	��� ������� �� ����� ��� ������ 32!
	Z - ��������� ��� �
	X - ��������� ��� �
	C - ��������� ��� Y
	V - ��������� ��� Y

*/
class Architect
{
	Shape m_mouse;
	Text m_text;

	ArcitectVector m_Z_vec = ArcitectVector::ZERO;

	vector<ObjectManager> m_objectListBeck;
	vector<ObjectManager> m_objectListZero;
	vector<ObjectManager> m_objectListFront;

	uint m_size_x;
	uint m_size_y;

public:
	Architect(vector<ObjectManager> &objectListBeck, vector<ObjectManager> &objectListZero, vector<ObjectManager> &objectListFront);
	void Action(StateGame& state_game);
	void DeleteObject();
	void Update();
	void Draw(StateGame& state_game);
	//~Architect();
};

