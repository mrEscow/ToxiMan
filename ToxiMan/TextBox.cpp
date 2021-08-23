﻿#include "TextBox.h"
namespace UI {


	short	 TextBoxEditHelper::timer_blink;
	Shape	 TextBoxEditHelper::shape_blink_line;
	size_t	 TextBoxEditHelper::char_position;
	sf::Text TextBoxEditHelper::text_left;
	sf::Text TextBoxEditHelper::text_middle;
	string	 TextBoxEditHelper::value_left;
	string	 TextBoxEditHelper::value_middle;
	bool	 TextBoxEditHelper::is_left_mouse_pressed = false;




	TextBoxEditHelper::TextBoxEditHelper()
	{
	}

	void TextBoxEditHelper::Reset(v2f pos, int height)
	{
		shape_blink_line.setPosition(pos);
		shape_blink_line.setSize(v2f(1, height));
		shape_blink_line.setOrigin(shape_blink_line.getSize() / 2.f);
	}

	void TextBoxEditHelper::Update()
	{
		timer_blink < 60 ? timer_blink++ : timer_blink = 0;
		if (timer_blink > 30) shape_blink_line.setFillColor(Color(0, 0, 0, 255));
		else shape_blink_line.setFillColor(Color(0, 0, 0, 0));
	}

	TextBox::TextBox(v2f pos, v2f siz, const string data_id, const string value, uint max_value)
		:
		m_value_default(value),
		m_data_id(data_id),
		m_max_value(max_value)
	{
		m_input_type = InputType::TEXT;
		m_shape_box = CreateShape(pos, siz, -1, Color(150, 150, 150), Color(40, 40, 40));
		m_text = CreateText(v2f(pos.x - (m_shape_box.getSize().x / 2) + 2, pos.y), siz.y - 8, m_value_default, resources.font.erica_type, Color::Black);
		m_text.setOrigin(0, (siz.y - 8) / 2);
		m_value = m_value_default;
	}

	void TextBox::Update()
	{
	}

	void TextBox::Action()
	{
		if (IsMousePressed(sf::Mouse::Left)) {
			m_is_picked = false;

			if (IsContains(m_shape_box, (System::cur_p / System::zoom - System::cam.getCenter() / System::zoom))) {
				cout << "CLICK" << endl;
				TBEH::value_left = "";
				TBEH::text_left = m_text;
				TBEH::text_left.setString(TBEH::value_left);

				for (auto c : m_value)
				{
					if (TBEH::text_left.getPosition().x + TBEH::text_left.getGlobalBounds().width < cur_p_wnd.x) {
						TBEH::value_left += c;
						TBEH::text_left.setString(TBEH::value_left);
						TBEH::Reset(v2f(TBEH::text_left.getPosition().x + TBEH::text_left.getGlobalBounds().width, m_shape_box.getPosition().y), m_shape_box.getSize().y - 6);
					}
					else if (m_value == TBEH::value_left) {
						TBEH::Reset(v2f(m_text.getPosition().x + m_text.getGlobalBounds().width, m_shape_box.getPosition().y), m_shape_box.getSize().y - 6);
						break;
					}
					else if (TBEH::value_left == "") {
						TBEH::Reset(v2f(m_text.getPosition().x, m_shape_box.getPosition().y), m_shape_box.getSize().y - 6);
						break;
					}
				}
				TBEH::char_position = TBEH::value_left.length();
				TBEH::is_left_mouse_pressed = true;
				m_is_picked = true;
			}
		}

		if (m_is_picked) {
			if (IsMouseReleased(sf::Mouse::Left)) {
				TBEH::value_middle = "";
				TBEH::text_middle = m_text;
				TBEH::text_middle.setString(TBEH::value_middle);
				TBEH::is_left_mouse_pressed = false;
			}

			if (IsKeyPressed(Key::Left)) {
				if (!TBEH::value_left.empty()) {
					TBEH::value_left.pop_back();
					TBEH::char_position = TBEH::value_left.length();
					TBEH::text_left.setString(TBEH::value_left);
					TBEH::Reset(v2f(TBEH::text_left.getPosition().x + TBEH::text_left.getGlobalBounds().width, m_shape_box.getPosition().y), m_shape_box.getSize().y - 6);
				}
				else {
					TBEH::value_left = "";
				}
			}
			if (IsKeyPressed(Key::Right)) {
				if (TBEH::value_left != m_value) {
					TBEH::value_left.push_back(m_value[TBEH::char_position]);
					TBEH::text_left.setString(TBEH::value_left);
					TBEH::char_position = TBEH::value_left.length();
					TBEH::Reset(v2f(TBEH::text_left.getPosition().x + TBEH::text_left.getGlobalBounds().width, m_shape_box.getPosition().y), m_shape_box.getSize().y - 6);
				}
				else {
					TBEH::value_left = m_value;
				}
			}

			if (event.type == sf::Event::TextEntered) {
				if (event.text.unicode < 128) {
					if (event.text.unicode == 8) {
						if (!m_value.empty()) {
							if (TBEH::char_position > 0) {
								m_value.erase(TBEH::char_position - 1, 1);
								TBEH::value_left.erase(TBEH::char_position - 1, 1);
								TBEH::text_left.setString(TBEH::value_left);
								TBEH::Reset(v2f(TBEH::text_left.getPosition().x + TBEH::text_left.getGlobalBounds().width, m_shape_box.getPosition().y), m_shape_box.getSize().y - 6);
								TBEH::char_position--;
							}
						}
						else {
							m_value = "";
						}
					}
					else if (m_text.getString().toAnsiString().length() < m_max_value) { // Åñëè ââîäèì òåêñò è ñòðîêà êîðî÷å çàäàííîãî ìàêñèìóìâ
						TBEH::value_left += event.text.unicode;
						TBEH::char_position++;
						TBEH::text_left.setString(TBEH::value_left);
						m_value.insert(TBEH::value_left.length() - 1, &TBEH::value_left.back());
						TBEH::Reset(v2f(TBEH::text_left.getPosition().x + TBEH::text_left.getGlobalBounds().width, m_shape_box.getPosition().y), m_shape_box.getSize().y - 6);
					}
					m_text.setString(m_value);
				}
				else {
					TBEH::Reset(v2f(m_text.getPosition().x + m_text.getGlobalBounds().width, m_shape_box.getPosition().y), m_shape_box.getSize().y - 6);
				}
			}
		}
	}

	void TextBox::Draw()
	{
		wnd.draw(m_shape_box);
		wnd.draw(m_text);
		if (m_is_picked)
			wnd.draw(TBEH::shape_blink_line);
	}

	void TextBox::SetData(string data)
	{
		m_text.setString(data);
	}

	string TextBox::GetData()
	{
		return m_text.getString();
	}

	void TextBox::SetPosition(const v2f position)
	{
		m_shape_box.setPosition(position);
	}

	TextBoxInt::TextBoxInt(v2f pos, v2f siz, string data_id, string value, uint max_value)
		: 
		TextBox(pos, siz, data_id, value, max_value)
	{
		m_input_type = InputType::INTEGER;
	}

	void TextBoxInt::Action()
	{
		if (IsMousePressed(sf::Mouse::Left)) {
			m_is_picked = false;
			if (IsContains(m_shape_box, cur_p_wnd)) {
				TBEH::value_left = "";
				TBEH::text_left = m_text;
				TBEH::text_left.setString(TBEH::value_left);

				for (auto c : m_value)
				{
					if (TBEH::text_left.getPosition().x + TBEH::text_left.getGlobalBounds().width < cur_p_wnd.x) {
						TBEH::value_left += c;
						TBEH::text_left.setString(TBEH::value_left);
						TBEH::Reset(v2f(TBEH::text_left.getPosition().x + TBEH::text_left.getGlobalBounds().width, m_shape_box.getPosition().y), m_shape_box.getSize().y - 6);
					}
					else if (m_value == TBEH::value_left) {
						TBEH::Reset(v2f(m_text.getPosition().x + m_text.getGlobalBounds().width, m_shape_box.getPosition().y), m_shape_box.getSize().y - 6);
						break;
					}
					else if (TBEH::value_left == "") {
						TBEH::Reset(v2f(m_text.getPosition().x, m_shape_box.getPosition().y), m_shape_box.getSize().y - 6);
						break;
					}
				}
				TBEH::char_position = TBEH::value_left.length();
				TBEH::is_left_mouse_pressed = true;
				m_is_picked = true;
			}
		}

		if (m_is_picked) {
			if (IsMouseReleased(sf::Mouse::Left)) {
				TBEH::value_middle = "";
				TBEH::text_middle = m_text;
				TBEH::text_middle.setString(TBEH::value_middle);
				TBEH::is_left_mouse_pressed = false;
			}

			if (IsKeyPressed(Key::Left)) {
				if (!TBEH::value_left.empty()) {
					TBEH::value_left.pop_back();
					TBEH::char_position = TBEH::value_left.length();
					TBEH::text_left.setString(TBEH::value_left);
					TBEH::Reset(v2f(TBEH::text_left.getPosition().x + TBEH::text_left.getGlobalBounds().width, m_shape_box.getPosition().y), m_shape_box.getSize().y - 6);
				}
				else {
					TBEH::value_left = "";
				}
			}
			if (IsKeyPressed(Key::Right)) {
				if (TBEH::value_left != m_value) {
					TBEH::value_left.push_back(m_value[TBEH::char_position]);
					TBEH::text_left.setString(TBEH::value_left);
					TBEH::char_position = TBEH::value_left.length();
					TBEH::Reset(v2f(TBEH::text_left.getPosition().x + TBEH::text_left.getGlobalBounds().width, m_shape_box.getPosition().y), m_shape_box.getSize().y - 6);
				}
				else {
					TBEH::value_left = m_value;
				}
			}

			if (event.type == sf::Event::TextEntered) {
				if (event.text.unicode > 47 && event.text.unicode < 58 || event.text.unicode == 8) {
					if (event.text.unicode == 8) {
						if (!m_value.empty()) {
							if (TBEH::char_position > 0) {
								m_value.erase(TBEH::char_position - 1, 1);
								TBEH::value_left.erase(TBEH::char_position - 1, 1);
								TBEH::text_left.setString(TBEH::value_left);
								TBEH::Reset(v2f(TBEH::text_left.getPosition().x + TBEH::text_left.getGlobalBounds().width, m_shape_box.getPosition().y), m_shape_box.getSize().y - 6);
								TBEH::char_position--;
							}
						}
						else {
							m_value = "";
						}
					}
					else if ((m_value.empty() || std::stoi(m_text.getString().toAnsiString()) < m_max_value) && m_text.getString().toAnsiString().length() < 3) {
						TBEH::value_left += event.text.unicode;
						TBEH::char_position++;
						TBEH::text_left.setString(TBEH::value_left);
						m_value.insert(TBEH::value_left.length() - 1, &TBEH::value_left.back());
						if (std::stoi(m_value) > m_max_value) {
							m_value = to_string(m_max_value);
						}
						TBEH::Reset(v2f(TBEH::text_left.getPosition().x + TBEH::text_left.getGlobalBounds().width, m_shape_box.getPosition().y), m_shape_box.getSize().y - 6);
					}
					m_text.setString(m_value);
				}
				else {
					TBEH::Reset(v2f(m_text.getPosition().x + m_text.getGlobalBounds().width, m_shape_box.getPosition().y), m_shape_box.getSize().y - 6);
				}
			}
		}
	}

	TextBoxInt::~TextBoxInt()
	{
	}

}