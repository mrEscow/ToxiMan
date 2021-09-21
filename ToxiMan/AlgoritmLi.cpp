#include "AlgoritmLi.h"

AlgoritmLi::AlgoritmLi(Architect* arch,Player* player)
{
		m_arch = arch;
		m_player = player;
}

void AlgoritmLi::CreateMap()
{
	m_map_size = m_arch->GetMap().GetMapSize();

	for (size_t y = 0; y < m_map_size.y; y++)
	{
		for (size_t x = 0; x < m_map_size.x; x++)
		{
			bool is_unfree = false;

			for (auto& obj : m_arch->GetVecZero()) {
				if (!is_unfree && System::IsContains(
					m_arch->GetVecCell()[x + (y * m_map_size.x)], 
					obj.GetShape().getPosition())
					) 
				{
					cout << "1";
					is_unfree = true;
				}

			}
			if (!is_unfree) {
				cout << "0";				
			}



			m_pair.first.x = x;
			m_pair.first.x = y;

			if (is_unfree)
				m_pair.second = eCell::UNFREE;
			else
				m_pair.second = eCell::FREE;

			m_vec_map.push_back(m_pair);
		}
		cout << endl;
	}


}

void AlgoritmLi::TekeStart()
{
	for (auto& cell : m_arch->GetVecCell()) {
		if (System::IsContains(cell, m_player->GetPosition())) {
			cout << "S";
		}
	}
}

void AlgoritmLi::TakeStop()
{
	for (auto& cell : m_arch->GetVecCell()) {
		if (System::IsContains(cell, System::cur_p)) {
			cout << "F";
		}
	}
}

bool AlgoritmLi::CreateRoad( Player p)
{
	CreateMap();
	TekeStart();
	TakeStop();

	return true;
}
