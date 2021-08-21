#pragma once
#include "System.h"
#include "World.h"
#include "ObjectManager.h"
#include "GameStates.h"
#include "Player.h"
#include "JsonSaveMenager.h"
#include "ArchtectMenu.h"

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
	��� ������� �� ����� ��� ������ 64!
	//Z - ��������� ��� �
	//X - ��������� ��� �
	//C - ��������� ��� Y
	//V - ��������� ��� Y
	������� ���������

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

