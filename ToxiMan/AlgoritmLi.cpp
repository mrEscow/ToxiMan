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
					System::cur_p)
					)
				{
					is_finish = true;
				}
			}

			m_pair.first.x = x;
			m_pair.first.y = y;
			
			if (is_unfree) {
				cout << "1";
				m_pair.second = eCell::UNFREE;
			}
			else if (is_start) {
				cout << "S";
				m_pair.second = eCell::START;
			}
			else if (is_finish) {
				cout << "F";
				m_pair.second = eCell::FINISH;
			}
			else {
				cout << "0";
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

bool AlgoritmLi::CreateRoad()
{

	cout << "MAP:" << endl;
	CreateMap();
	cout << "--------------" << endl;
	//TekeStart();
	//TakeStop();

	for (auto &pair : m_vec_map) {
		if (pair.second == eCell::START) {
			cout << pair.first.x << endl;
			cout << pair.first.y << endl;
		}
	}

	   



	return true;
}
