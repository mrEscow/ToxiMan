#include "AlgoritmLi.h"

AlgoritmLi::AlgoritmLi(Architect* arch,Player* player)
{
		m_arch = arch;
		m_player = player;
}

void AlgoritmLi::CreateMap()
{
	m_map_size = m_arch->GetMap().GetMapSize();

	m_vec_i_str.clear();
	m_vec_map_bool.clear();
	m_vec_map_int.clear();
	m_vec_map.clear();

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
				//cout << "#";
				m_vec_i_str.push_back(std::pair<v2i,string>((m_pair.first), "#"));
				m_vec_map_bool.push_back(std::pair<v2i, bool >(m_pair.first, true));
				m_vec_map_int.push_back(std::pair<v2i, int >(m_pair.first, -1));
				m_pair.second = eCell::UNFREE;
			}
			else if (is_start) {
				//cout << "S";
				m_vec_i_str.push_back(std::pair<v2i, string>((m_pair.first), "S"));
				m_vec_map_bool.push_back(std::pair<v2i, bool >(m_pair.first, false));
				m_vec_map_int.push_back(std::pair<v2i, int >(m_pair.first, -2));
				m_pair.second = eCell::START;
				m_start = m_pair.first;
			}
			else if (is_finish) {
				//cout << "F";
				m_vec_i_str.push_back(std::pair<v2i, string>((m_pair.first), "F"));
				m_vec_map_bool.push_back(std::pair<v2i, bool >(m_pair.first, false));
				m_vec_map_int.push_back(std::pair<v2i, int >(m_pair.first, -2));
				m_pair.second = eCell::FINISH;
				m_finish = m_pair.first;
			}
			else {
				//cout << " ";
				m_vec_i_str.push_back(std::pair<v2i, string>((m_pair.first), " "));
				m_vec_map_bool.push_back(std::pair<v2i, bool >(m_pair.first, false));
				m_vec_map_int.push_back(std::pair<v2i, int >(m_pair.first, -2));
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

bool AlgoritmLi::CheckSearch()
{
	//const_cast<int&>();
	//int W2 = m_map_size.x;

	//const int W = const_cast<const int&>(m_map_size.x);         // ������ �������� ����
	//const int W = static_cast<const int>(m_map_size.x);         // ������ �������� ����
	//const int W = reinterpret_cast<const int>(m_map_size.x);         // ������ �������� ����

	//const int W = 12;				// ������ �������� ����
	//const int H = 8;				// ������ �������� ����
	const int WALL = -1;			// ������������ ������
	const int BLANK = -2;			// ��������� ������������ ������

	//int px[W * H], py[W * H];      // ���������� �����, ��������  ����

	int* px = new int[m_map_size.x * m_map_size.y];
	int* py = new int[m_map_size.x * m_map_size.y];


	int len;                       // ����� ����
	//int grid[H][W];                // ������� ����
	//int grid[m_map_size.y][m_map_size.x];
	//int grid[] = new int [H][W];

	int** grid = new int* [m_map_size.y];		// ������� 
	for (int i = 0; i < m_map_size.y; i++) {			// ���������
		grid[i] = new int[m_map_size.x];				// ������ 
	}													// !

	//cout << "SIZE " << m_vec_map_int.size() << endl;
	//cout << "SIZE " << m_vec_i_str.size() << endl;
	
	for (int i = 0; i < m_map_size.y; i++) {
		//cout << "������� �����" << "(" << i + 1 << ")" << ":";
		for (int j = 0; j < m_map_size.x; j++) {
			grid[i][j] = m_vec_map_int[j + (i * m_map_size.x)].second;;
		}
	}

	//cout << "GRID:" << endl;
	for (int i = 0; i < m_map_size.y; i++) {		
		for (int j = 0; j < m_map_size.x; j++) {
			//cout << grid[i][j];
		}
		//cout << endl;
	}


	// ����� ������� lee() ������ grid �������� ���������� WALL � BLANK

	//bool lee // ����� ���� �� ������ (ax, ay) � ������ (bx, by)
	int ax = m_start.x;
	int ay = m_start.y;
	int bx = m_finish.x;
	int by = m_finish.y;

	
	int dx[4] = { 1, 0, -1, 0 };   // ��������, ��������������� ������� ������
	int dy[4] = { 0, 1, 0, -1 };   // ������, �����, ����� � ������
	int d, x, y, k;
	bool stop;

	if (grid[ay][ax] == WALL || grid[by][bx] == WALL) {

		for (int i = 0; i < m_map_size.y; i++) 
				delete grid[i];
		delete px;
		delete py;

		return false;  // ������ (ax, ay) ��� (bx, by) - �����
	}

	// ��������������� �����
	d = 0;
	grid[ay][ax] = 0;            // ��������� ������ �������� 0
	do {
		stop = true;               // ������������, ��� ��� ��������� ������ ��� ��������
		for (y = 0; y < m_map_size.x; ++y)
			for (x = 0; x < m_map_size.y; ++x)
				if (grid[y][x] == d)                         // ������ (x, y) �������� ������ d
				{
					for (k = 0; k < 4; ++k)                    // �������� �� ���� ������������ �������
					{
						int iy = y + dy[k], ix = x + dx[k];
						if (iy >= 0 && iy < m_map_size.x && ix >= 0 && ix < m_map_size.y &&
							grid[iy][ix] == BLANK)
						{
							stop = false;              // ������� ������������ ������
							grid[iy][ix] = d + 1;      // �������������� �����
						}
					}
				}
		d++;
	} while (!stop && grid[by][bx] == BLANK);

	//cout << "GRID_2:" << endl;
	for (int i = 0; i < m_map_size.y; i++) {
		for (int j = 0; j < m_map_size.x; j++) {
			//cout << grid[i][j];
		}
		//cout << endl;
	}


	if (grid[by][bx] == BLANK) {

		for (int i = 0; i < m_map_size.y; i++)
			delete grid[i];
		delete px;
		delete py;

		return false;  // ���� �� ������
	}

	// �������������� ����
	len = grid[by][bx];            // ����� ����������� ���� �� (ax, ay) � (bx, by)
	x = bx;
	y = by;
	d = len;
	while (d > 0)
	{
		px[d] = x;
		py[d] = y;                   // ���������� ������ (x, y) � ����
		d--;
		for (k = 0; k < 4; ++k)
		{
			int iy = y + dy[k], ix = x + dx[k];
			if (iy >= 0 && iy < m_map_size.x && ix >= 0 && ix < m_map_size.y &&
				grid[iy][ix] == d)
			{
				x = x + dx[k];
				y = y + dy[k];           // ��������� � ������, ������� �� 1 ����� � ������
				break;
			}
		}
	}

	px[0] = ax;
	py[0] = ay;                    // ������ px[0..len] � py[0..len] - ���������� ����� ����

	//cout << endl;

	for (size_t y = 0; y < len; y++) {
		//cout << "x=" << px[y] << " y=" << py[y] << endl;
		//v2i temp = v2i(px[y], py[y]);
		m_go.push_back(v2i(px[y], py[y]));
	}
		
	//cout << endl;

	for (auto& p : m_go) {
		p *= 64;
		p.x += 32;
		p.y += 32;
		//cout << "x=" << p.x << " y=" << p.y << endl;
	}

	//cout << endl;

	for (size_t y = 0; y < m_map_size.y; y++)
	{
		for (size_t x = 0; x < m_map_size.x; x++)
		{
			if (m_vec_i_str[x + (y * m_map_size.x)].second == " ")
				if(grid[y][x] != -2)
					m_vec_i_str[x + (y * m_map_size.x)].second = to_string(grid[y][x]);

		}
	}

	for (int i = 0; i < m_map_size.y; i++)
		delete grid[i];
	delete px;
	delete py;

	return true;	
}


bool AlgoritmLi::CreateRoad()
{
	CreateMap();

	if(CheckSearch())
		return true;

	return false;
}
