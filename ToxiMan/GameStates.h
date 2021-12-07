#pragma once
#include "Define.h"
#include "GameSettings.h"

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


class GameStates {
private:
	UINT32 GameLevel;
	
public:
	GameStates(UINT32 GameLevel)
	{
		this->GameLevel = GameLevel;
	}

	void NextGameLevel()
	{ 
		if(GameLevel <= GameSettings::GetGemeLevels())
			GameLevel++;
		else
		{
			//Finish
		}
	}

	const UINT32 GetGameLevel()
	{
		return GameLevel;
	}
};