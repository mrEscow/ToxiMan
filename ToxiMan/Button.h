// ▼
#pragma once
#include "System.h"
#include "GameSettings.h"
namespace UI {
	const Color color_button_border = Color(0, 79, 114);
	const Color color_button_default = Color(54, 159, 194);
	const Color color_button_second = Color(43, 137, 206);

	class Button
	{
	private:

		Shape m_shape;
		string m_name_id;

		GameSettings* m_game_settings_ptr;

		Text text_button;
		sf::Sound s_button;

		bool is_inside = false;
		bool is_pressed = false;

	public:

		Button(Shape shape, string name_id, GameSettings& m_game_settings);
		void Update(float zoom = 1);
		void Draw();
		bool IsAction();
		string GetNameId();
		void SetNameID(string newname);
		Shape* GetShape();
		v2f GetPos();
		~Button();

	};
}



