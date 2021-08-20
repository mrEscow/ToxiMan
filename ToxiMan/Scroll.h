// ▼
#pragma once
#include "System.h"

class Scroll
{
private:

	Shape m_shape_scroll;
	Shape m_shape_back;
	//Shape m_shape_colored;
	string m_name_id;

	float m_value;

	bool is_inside = false;
	bool is_pressed = false;

public:

	Scroll(v2f pos, v2f siz, string name_id, float value);
	void Update();
	void Draw();
	void Action();
	float GetValue();
	string GetNameId();
	~Scroll();
};

