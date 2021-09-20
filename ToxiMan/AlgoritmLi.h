#pragma once

#include "Architect.h"
#include "Player.h"
#include "System.h"

class AlgoritmLi 
{
public:
	AlgoritmLi(Architect* arch);

	enum class A : uint
	{
		START,
		STOP,
		FREE,
		UNFREE
	};

	v2i m_start;
	v2i m_stop;
	v2i m_map_size;

	Architect * m_arch;

	std::pair<bool, A> m_is_unfree;

	vector<v2i> m_go;



	void CreateMap();

	void TekeStart(Player p);
	void TakeStop();

public:
	bool CreateRoad( Player p);

};

