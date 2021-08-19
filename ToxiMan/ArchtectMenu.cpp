#include "ArchtectMenu.h"

ArchtectMenu::ArchtectMenu()
{
	archMenu.setViewport(sf::FloatRect(0.f, 0.f, 0.25f, 1.f));
	m_menu = System::CreateShape(archMenu.getCenter(), archMenu.getSize(), Color::White);	
	m_main_text = System::CreateText(v2f(10, 15 ), 70, "ArchitectMode:", System::resources.font.common, Color::Black);
	m_name_vector_text = System::CreateText(v2f(archMenu.getCenter().x + 10, 15), 70, "Vector Zero", System::resources.font.common, Color::Black);
}

void ArchtectMenu::Action()
{
}

void ArchtectMenu::Update(ArcitectVector &Z_vec)
{
	switch (Z_vec)
	{
	case ArcitectVector::BECK:
		m_name_vector_text.setString("Vector Beck");
		break;
	case ArcitectVector::ZERO:
		m_name_vector_text.setString("Vector Zero");
		break;
	case ArcitectVector::FRONT:
		m_name_vector_text.setString("Vector Front");
		break;
	default:
		break;
	}

}

void ArchtectMenu::Draw()
{
	System::wnd.setView(archMenu);
	System::wnd.draw(m_menu);
	System::wnd.draw(m_main_text);
	System::wnd.draw(m_name_vector_text);
}

ArchtectMenu::~ArchtectMenu()
{
}
