#pragma once

#include "Architect.h"
#include "Player.h"
#include "System.h"

class AlgoritmLi 
{
public:
	AlgoritmLi(Architect* arch, Player* player);

	enum class eCell : uint
	{
		START,
		FINISH,
		FREE,
		UNFREE
	};

	v2i m_start;
	v2i m_stop;
	v2i m_map_size;

	Architect * m_arch;
	Player* m_player;

	//std::pair<bool, eCell> m_is_unfree;

	std::pair<v2i, eCell> m_pair;

	vector<std::pair<v2i, eCell>> m_vec_map;

	vector<v2i> m_go;



	void CreateMap();
	void TekeStart();
	void TakeStop();

public:
	bool CreateRoad( Player p);

};

