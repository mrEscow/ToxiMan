#pragma once
#include "System.h"
#include "World.h"
#include "ObjectManager.h"
#include "GameStates.h"
#include "Player.h"

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
	Shape	m_mouse;
	Text	m_main_text;
	Text	m_name_vector_text;
	v2f		m_zoom_for_text;
	float	m_koef;

	ArcitectVector m_Z_vec = ArcitectVector::ZERO;

	vector<ObjectManager> m_objectListBeck;
	vector<ObjectManager> m_objectListZero;
	vector<ObjectManager> m_objectListFront;

	uint m_size_x;
	uint m_size_y;

	// �����
	Shape m_cell;
	vector<Shape> m_cell_vec;


public:
	Architect();
	void Action(StateGame& state_game, bool& is_from_arhitetc);
	void DeleteObject();
	void Update();
	void Draw(StateGame& state_game, Player* player);
	//~Architect();
};

