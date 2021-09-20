#pragma once
#include "System.h"

namespace UI {

	class TextBoxEditHelper : public System {
	public:

		static short timer_blink;			// 
		static Shape shape_blink_line;		// 
		static size_t char_position;		// 
		static sf::Text text_left;			// 
		static sf::Text text_middle;		// 
		static string value_left;			// 
		static string value_middle;			// 
		static bool is_left_mouse_pressed;	// 

		TextBoxEditHelper();

		static void Reset(v2f pos, int height);

		static void Update();

	};

	enum class InputType {
		TEXT = 0u,
		INTEGER = 1u,
		REAL = 2u
	};

	class TextBox : public System
	{
	private:

		using TBEH = TextBoxEditHelper;

	protected:

		Shape m_shape_box;
		sf::Text m_text;
		bool m_is_picked = false;
		string m_value;
		const string m_value_default;
		const string m_data_id;
		const uint m_max_value;
		InputType m_input_type;

	public:

		TextBox(v2f pos, v2f siz, const string data_id = "", const string value = "", uint max_value = 4);

		virtual void Update(); 
		virtual void Action();
		virtual void Draw();
		void SetData(string data);
		string GetData();
		void SetPosition(const v2f position);
	};

	class TextBoxInt : public TextBox {
	public:

		TextBoxInt(v2f pos, v2f siz, string data_id = "1", string value = "1", uint max_value = 1024);

		virtual void Action() override;
		virtual ~TextBoxInt();
	};

	class Label : public System {

		const string m_data_id;

		Shape m_shp_label;


	public:

		Label(
			const string data_id,
			v2f pos, 
			v2f siz
		) :
			m_data_id(data_id)
		{

			m_shp_label = CreateShape(v2f(0,0),v2f(0,0));

		}


	};

}


