#include "Map.h"

Map::Map()
{
	//m_id = (int)number;
}

string Map::GetName()
{
	return m_name;
}

//uint Map::GetId()
//{
//	return m_id;
//}

v2i Map::GetMapSize()
{
	return m_map_size;
}

v2f Map::GetStartPos()
{
	return m_start_pos;
}

v2f Map::GetFinalPos()
{
	return m_final_pos;
}

void Map::SetName(string name)
{
	m_name = name;
}

//void Map::SetId(uint id)
//{
//	m_id = id;
//}

void Map::SetMapSize(v2i size)
{
	m_map_size = size;
}

void Map::SetStartPos(v2f s_pos)
{
	m_start_pos = s_pos;
}

void Map::SetFinalPos(v2f f_pos)
{

	m_final_pos = f_pos;
}

//IMap* Map::GetMap()
//{
//	return LoadMap();
//}
