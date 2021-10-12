// ▼
#pragma once
#include "Define.h"

struct Font
{
	sf::Font common;
	sf::Font erica_type;

	//sf::Font testFont;

	Font()
	{
		cout << "Font Loaded\n";
		common.loadFromFile("Resources/fonts/Common.ttf");
		erica_type.loadFromFile("Resources/fonts/Erica_Type.ttf");

		//testFont.
	}

	~Font()
	{

	}
};
