#pragma once
#include"Define.h"

enum class StateGame : uint
{
	ON_MAIN_MENU,
	ON_GAME
};


enum class PlayerDir : uint
{
	RIGHT,
	LEFT
};



enum class StateMainMenu : uint
{
	ON_MAIN,
	ON_OPTIONS,
	ON_EXIT
};

enum class StateLevel : uint
{
	ON_PLAYED,
	ON_PAUSED
};