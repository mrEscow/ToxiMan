#pragma once
#include "System.h"
class Map
{
private:
	// bAckGround //FIXIT ore not
	uint m_id;
	v2f m_map_size;
	v2f m_start_pos;
	v2f m_final_pos;

public:

	uint GetId();
	v2f GetMapSize();
	v2f GetStartPos();
	v2f GetFinalPos();

	void SetId(uint id);
	void SetMapSize(v2f size);
	void SetStartPos(v2f s_pos);
	void SetFinalPos(v2f f_pos);
};

