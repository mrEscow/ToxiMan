#pragma once
#include "System.h"
class Map
{
private:
	v2f m_map_size;
	v2f m_start_pos;
	v2f m_final_pos;
public:
	v2f GetMapSize();
	v2f GetStartPos();
	v2f GetFinalPos();
};

