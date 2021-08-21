#include "Button.h"
namespace UI{
	Button::Button(Shape shape, string name_id ,GameSettings& m_game_settings)
	{
		m_name_id = name_id;
		m_shape = shape;

		m_game_settings_ptr = &m_game_settings;

		
		s_button.setBuffer(System::resources.audio.sound.button_sound);
		text_button = System::CreateText(shape.getPosition(), shape.getSize().y / 2, name_id, System::resources.font.erica_type, Color::Yellow);
		System::CenteringText(text_button);

	}

	bool Button::IsAction()
	{
		if (is_inside && System::IsMousePressed(sf::Mouse::Left)) {
			s_button.setVolume(m_game_settings_ptr->GetSoundVolume());
			if (m_game_settings_ptr->GetSoundOn())s_button.play();
			is_pressed = true;
		}

		if (System::IsMouseReleased(sf::Mouse::Left))
		{
			if (is_pressed)
			{
				is_pressed = false;
				if (is_inside) return true;
			}
		}
		return false;
	}

	void Button::Update(StateGame& state_game)
	{
		switch (state_game)
		{
		case StateGame::ON_MAIN_MENU:
			if (System::IsContains(m_shape, System::cur_p))
			{
				text_button.setFillColor(Color::Magenta);
				m_shape.setFillColor(color_button_second);
				is_inside = true;
			}
			else
			{
				text_button.setFillColor(Color::Green);
				m_shape.setFillColor(color_button_default);
				is_inside = false;
			}
			break;
		case StateGame::ON_GAME:
			break;
		case StateGame::ON_ARCITECT:
			if (System::IsContains(m_shape, System::cur_p_wnd))
			{
				text_button.setFillColor(Color::Magenta);
				m_shape.setFillColor(color_button_second);
				is_inside = true;
			}
			else
			{
				text_button.setFillColor(Color::Green);
				m_shape.setFillColor(color_button_default);
				is_inside = false;
			}
			break;
		default:
			break;
		}


		if (is_pressed) {
			text_button.setScale(0.95, 0.95);
			m_shape.setScale(0.95, 0.95); // Размер зажатой кнопки
		}
		else {
			text_button.setScale(1.f, 1.f);
			m_shape.setScale(1.f, 1.f); // Изначальный размер кнопки
		}
	}

	void Button::Draw()
	{
		System::wnd.draw(m_shape);
		System::wnd.draw(text_button);
	}

	string Button::GetNameId()
	{
		return m_name_id;
	}

	Shape* Button::GetShape()
	{
		return &m_shape;
	}

	v2f Button::GetPos()
	{
		return m_shape.getPosition();
	}

	Button::~Button()
	{

	}
}
