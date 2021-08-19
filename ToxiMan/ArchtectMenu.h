#pragma once
#include "System.h"
#include "GameStates.h"

class ArchtectMenu
{
private:
	sf::View archMenu;
	Shape	m_menu;
	Text	m_main_text;
	Text	m_name_vector_text;
public:
	ArchtectMenu();
	void Action();
	void Update(ArcitectVector &m_Z_vec);
	void Draw();
	~ArchtectMenu();
};

