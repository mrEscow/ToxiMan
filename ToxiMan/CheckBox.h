// ▼
#pragma once
#include "System.h"
#include "GameSettings.h"
namespace UI {
	const Color color_checkbox_border = Color(0, 79, 114);
	const Color color_checkbox_default = Color(54, 159, 194);
	const Color color_checkbox_second = Color(43, 137, 206);

	class CheckBox
	{
	private:

		Shape m_shape;
		string m_name_id;

		GameSettings* m_game_settings_ptr;

		Text text_button;
		sf::Sound s_button;

		bool is_ON;

		bool is_inside = false;
		bool is_pressed = false;

	public:

		CheckBox(Shape shape, string name_id, bool is_value, GameSettings& m_game_settings);
		void Update();
		void Draw();
		void Action();
		bool GetValue();
		string GetNameId();
		~CheckBox();

	};
}


