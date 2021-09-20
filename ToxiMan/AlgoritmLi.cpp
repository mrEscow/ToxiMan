#include "AlgoritmLi.h"

AlgoritmLi::AlgoritmLi(Architect* arch)
{
		m_arch = arch;

}

void AlgoritmLi::CreateMap()
{


	int i = 0, j = 0;

	cout << m_arch->GetVecCell().size() << endl; // 2400
	cout << m_arch->GetVecZero().size() << endl; // 768

	for (auto& cell : m_arch->GetVecCell()) {
		for (auto& obj : m_arch->GetVecZero()) {
			if (System::IsContains(cell, obj.GetShape().getPosition())) {
				//m_go.push_back()
				cout << "1";
			}
			// cout << "0";

			i++;
		}
		cout << endl;
		j++;
	}

	m_map_size.x = i;
	m_map_size.y = j;

}

void AlgoritmLi::TekeStart(Player p)
{
}

void AlgoritmLi::TakeStop()
{
}



bool AlgoritmLi::CreateRoad( Player p)
{
	CreateMap();
	TekeStart(p);
	TakeStop();

	return true;
}
