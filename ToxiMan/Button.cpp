#include "Button.h"
namespace UI{
	Button::Button(Shape shape, string name_id)
	{
		m_name_id = name_id;
		m_shape = shape;

		s_button.setBuffer(System::resources.audio.sound.button_sound);
		text_button = System::CreateText(shape.getPosition(), static_cast<uint>(shape.getSize().y) / 2U, name_id, System::resources.font.erica_type, Color::Yellow);
		System::CenteringText(text_button);

	}

	bool Button::IsAction()
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
				if (is_inside) return true;
			}
		}
		return false;
	}

	void Button::Update()
	{
		if (System::IsContains(m_shape, System::cur_for_UI))
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



		if (is_pressed) {
			text_button.setScale(0.95f, 0.95f);
			m_shape.setScale(0.95f, 0.95f); 
		}
		else {
			text_button.setScale(1.f, 1.f);
			m_shape.setScale(1.f, 1.f);
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

	void Button::SetNameID(string newname)
	{
		m_name_id = newname;
		text_button.setString(m_name_id);
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
