#include "Scroll.h"
namespace UI {
	Scroll::Scroll(v2f pos, v2f siz, string name_id, float value)
	{
		m_value = value;
		m_name_id = name_id;
		m_shape_back = System::CreateShape(pos, siz, -2, Color::Black, Color::Green);
		v2f px_scroll = v2f(pos.x - (siz.x / 2) + (siz.x / 100) * m_value, pos.y);
		m_shape_scroll = System::CreateShape(px_scroll, v2f(siz.y, siz.y), -2, Color::Yellow, Color::Green);
	}


	void Scroll::Update()
	{
		if (System::IsContains(m_shape_scroll, System::cur_p))
		{
			//m_shape.setFillColor(color_button_second);
			is_inside = true;
		}
		else
		{
			//m_shape.setFillColor(color_button_default);
			is_inside = false;
		}

		if (is_pressed)
		{
			m_shape_scroll.setScale(1.05, 1.05);
			m_shape_scroll.setPosition(B::cur_p.x, m_shape_back.getPosition().y);

			m_value = 100 + ((m_shape_scroll.getPosition().x - m_shape_back.getPosition().x) - (m_shape_back.getSize().x / 2)) / m_shape_back.getSize().x * 100;
			if (m_shape_scroll.getPosition().x < (m_shape_back.getPosition().x) - (m_shape_back.getSize().x / 2)) {
				m_shape_scroll.setPosition((m_shape_back.getPosition().x) - (m_shape_back.getSize().x / 2) + (m_shape_scroll.getSize().x / 2), m_shape_back.getPosition().y);
				m_value = 0;
			}
			if (m_shape_scroll.getPosition().x > (m_shape_back.getPosition().x) + (m_shape_back.getSize().x / 2)) {
				m_shape_scroll.setPosition((m_shape_back.getPosition().x) + (m_shape_back.getSize().x / 2) - (m_shape_scroll.getSize().x / 2), m_shape_back.getPosition().y);
				m_value = 100;
			}
		}
		else m_shape_scroll.setScale(1.f, 1.f);
	}

	void Scroll::Draw()
	{
		System::wnd.draw(m_shape_back);
		System::wnd.draw(m_shape_scroll);
	}

	void Scroll::Action()
	{
		if (is_inside && System::IsMousePressed(sf::Mouse::Left))
		{
			is_pressed = true;
		}


		if (System::IsMouseReleased(sf::Mouse::Left))
		{
			if (is_pressed)
				is_pressed = false;
		}
	}

	float Scroll::GetValue()
	{
		return m_value;
	}

	string Scroll::GetNameId()
	{
		return m_name_id;
	}

	Scroll::~Scroll()
	{
	}
}

