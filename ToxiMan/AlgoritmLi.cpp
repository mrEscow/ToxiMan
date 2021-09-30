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
			bool is_start = false;
			bool is_finish = false;


			for (auto& obj : m_arch->GetVecZero()) {
				if (!is_unfree && System::IsContains(
					m_arch->GetVecCell()[x + (y * m_map_size.x)], 
					obj.GetShape().getPosition())
					) 
				{
					is_unfree = true;
				}
			}

			for (auto& obj : m_arch->GetVecZero()) {
				if (!is_start && System::IsContains(
					m_arch->GetVecCell()[x + (y * m_map_size.x)],
					m_player->GetPosition())
					)
				{
					is_start = true;
				}
			}

			for (auto& obj : m_arch->GetVecZero()) {
				if (!is_finish && System::IsContains(
					m_arch->GetVecCell()[x + (y * m_map_size.x)],
					m_arch->GetMap().GetFinalPos())
					//System::cur_p)					
					)
				{
					is_finish = true;
				}
			}

			m_pair.first.x = static_cast<int>(x);
			m_pair.first.y = static_cast<int>(y);
			
			if (is_unfree) {
				cout << "#";
				m_vec_i_str.push_back(std::pair<v2i,string>((m_pair.first), "#"));
				m_vec_map_bool.push_back(std::pair<v2i, int >(m_pair.first, true));
				m_pair.second = eCell::UNFREE;
			}
			else if (is_start) {
				cout << "S";
				m_vec_i_str.push_back(std::pair<v2i, string>((m_pair.first), "S"));
				m_vec_map_bool.push_back(std::pair<v2i, int >(m_pair.first, true));
				m_pair.second = eCell::START;
				m_start = m_pair.first;
			}
			else if (is_finish) {
				cout << "F";
				m_vec_i_str.push_back(std::pair<v2i, string>((m_pair.first), "F"));
				m_vec_map_bool.push_back(std::pair<v2i, int >(m_pair.first, false));
				m_pair.second = eCell::FINISH;
				m_finish = m_pair.first;
			}
			else {
				cout << " ";
				m_vec_i_str.push_back(std::pair<v2i, string>((m_pair.first), " "));
				m_vec_map_bool.push_back(std::pair<v2i, int >(m_pair.first, false));
				m_pair.second = eCell::FREE;
			}

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

bool AlgoritmLi::CheckVeck()
{
	for (auto& a : m_vec_map_bool)
		if (a.second == false)
			return true;
	return false;
}

bool AlgoritmLi::CreateRoad()
{

	cout << "MAP:" << endl;
	CreateMap();
	cout << "--------------" << endl;
	/*
		ЦИКЛ
			ДЛЯ каждой ячейки loc, помеченной числом d
			пометить все соседние свободные непомеченные ячейки числом d + 1
			КЦ
			d : = d + 1
			ПОКА(финишная ячейка не помечена) И(есть возможность распространения волны)
	*/
	/*
	int d = 0;
	m_vec_map_int.push_back(std::pair<v2i, int >(m_start,d));
	//m_vec_map_bool.push_back(std::pair<v2i, int >(m_start, true));
	do
	{
		for (auto& bl : m_vec_map_bool) {
			
			if(bl.first == v2i(m_start.x, m_start.y - 1))
				if (bl.second = false) {
					bl.second = true;
					m_vec_map_int.push_back(std::pair<v2i, int >(m_start, d + 1));
					m_vec_map_bool[m_start.x + (m_start.y * m_map_size.x)].second = true;
				}
			if (bl.first == v2i(m_start.x + 1, m_start.y ))
				if (bl.second = false) {
					bl.second = true;
					m_vec_map_int.push_back(std::pair<v2i, int >(m_start, d + 1));
					m_vec_map_bool[m_start.x + (m_start.y * m_map_size.x)].second = true;
				}
			if (bl.first == v2i(m_start.x , m_start.y + 1))
				if (bl.second = false) {
					bl.second = true;
					m_vec_map_int.push_back(std::pair<v2i, int >(m_start, d + 1));
					m_vec_map_bool[m_start.x + (m_start.y * m_map_size.x)].second = true;
				}
			if (bl.first == v2i(m_start.x - 1, m_start.y))
				if (bl.second = false) {
					bl.second = true;
					m_vec_map_int.push_back(std::pair<v2i, int >(m_start, d + 1));
					m_vec_map_bool[m_start.x + (m_start.y * m_map_size.x)].second = true;
				}
		}

		d++;
		
	} while ( 
		CheckVeck()
		);
	*/



	cout << "--------------" << endl;
	for (size_t y = 0; y < m_map_size.y; y++)
	{
		for (size_t x = 0; x < m_map_size.x; x++)
		{
			cout << m_vec_i_str[x + (y * m_map_size.x)].second;

		}

		cout << endl;
	}
	cout << "--------------" << endl;
	return true;
}
