#pragma once
#include "System.h"
#include "GameStates.h"
class Map
{
private:

	// bAckGround //FIXIT ore not

	string m_name;
	//uint m_id;

	v2i m_map_size;
	v2f m_start_pos;
	v2f m_final_pos;

public:
	Map();

	string GetName();
	//uint GetId();
	v2i GetMapSize();
	v2f GetStartPos();
	v2f GetFinalPos();

	void SetName(string name);
	//void SetId(uint id);
	void SetMapSize(v2i size);
	void SetStartPos(v2f s_pos);
	void SetFinalPos(v2f f_pos);
};

