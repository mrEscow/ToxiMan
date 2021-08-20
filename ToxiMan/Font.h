// ▼
#pragma once
#include "Define.h"

struct Font
{
	sf::Font common;
	sf::Font erica_type;

	Font()
	{
		cout << "Font Loaded\n";
		common.loadFromFile("Resources/fonts/Common.ttf");
		erica_type.loadFromFile("Resources/fonts/Erica_Type.ttf");
	}

	~Font()
	{

	}
};
