#include "CheckBox.h"

namespace UI {
	CheckBox::CheckBox(Shape shape, string name_id, bool is_on)
	{
		is_ON = is_on;
		if (is_ON) shape.setTexture(&System::resources.texture.menu_checkbox_ON);
		if (!is_ON) shape.setTexture(&System::resources.texture.menu_checkbox_OFF);
		m_name_id = name_id;
		m_shape = shape;

		s_button.setBuffer(System::resources.audio.sound.button_sound);
		text_button = System::CreateText(shape.getPosition(), static_cast<uint>(shape.getSize().y), name_id, System::resources.font.erica_type, Color::Red);
		System::CenteringText(text_button);
		text_button.setPosition(shape.getPosition().x - (shape.getSize().x * 3.5f), shape.getPosition().y - (shape.getSize().y / 1.5f));
	}

	void CheckBox::Update()
	{
		if (System::IsContains(m_shape, System::cur_p))
		{
			m_shape.setFillColor(color_checkbox_second);
			is_inside = true;
		}
		else
		{
			m_shape.setFillColor(color_checkbox_second);
			is_inside = false;
		}

		if (is_pressed) m_shape.setScale(0.95f, 0.95f); // ������ ������� ������
		else m_shape.setScale(1.f, 1.f); // ����������� ������ ������
	}

	void CheckBox::Draw()
	{
		System::wnd.draw(m_shape);
		System::wnd.draw(text_button);
	}

	void CheckBox::Action()
	{
		if (is_inside && System::IsMousePressed(sf::Mouse::Left)) {
			s_button.setVolume(GameSettings::GetSoundVolume());
			if (GameSettings::GetSoundOn()) s_button.play();
			is_pressed = true;
		}


		if (System::IsMouseReleased(sf::Mouse::Left))
		{
			if (is_pressed)
			{
				is_pressed = false;

				if (is_inside) is_ON = !is_ON;
				if (is_ON)
				{
					m_shape.setTexture(&System::resources.texture.menu_checkbox_ON);

				}
				else
				{
					m_shape.setTexture(&System::resources.texture.menu_checkbox_OFF);

				}
			}
		}
	}

	bool CheckBox::GetValue()
	{
		return is_ON;
	}

	string CheckBox::GetNameId()
	{
		return m_name_id;
	}

	CheckBox::~CheckBox()
	{

	}
}
