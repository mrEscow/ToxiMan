#pragma once
#include"Define.h"

enum class StateGame : uint
{
	ON_MAIN_MENU,
	ON_GAME,
	ON_ARCITECT
};

enum class StateMainMenu : uint
{
	ON_MAIN,
	ON_OPTIONS,
	ON_EXIT
};

enum class LevelNumber : uint
{
	zero, one, two, tree, four, five, six, seven, eight, nine, ten
};

enum class ArcitectVector : uint
{
	BECK,
	ZERO,
	FRONT
};


enum class PlayerDir : uint
{
	RIGHT,
	LEFT
};



enum class StateLevel : uint
{
	ON_PLAYED,
	ON_PAUSED
};