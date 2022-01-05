#pragma once
#include "Define.h"
#include "System.h"
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

	enum class GS : uint
	{
		CHECK_MAP,

		START,
		STOP,

		PAUSA,

		GAME_MENU,

		REBOOT,

		STOP_LEVEL,

		NEXT_LEVEL,

		NEW_LEVEL,

		FINISH,

		GO,

		MY_NULL,
		BACK_LEVEL
	};
public:
	static GS gs;

	void CreateDefaultMap() {

		string Name{"DEFAULT"};

		v2i Size{40,30};

		v2f StartPoint{ 64 * 5,64 * 5 };
		v2f EndPoint{ 64 * 35,64 * 10 };

		Json json;

		json["Name"] = Name;	// string

		json["MapSizeX"] = Size.x;	// int
		json["MapSizeY"] = Size.y;	// int

		json["MapStartPosX"] = StartPoint.x;	// float
		json["MapStartPosY"] = StartPoint.y;	// float

		json["MapFinalPosX"] = EndPoint.x;	// float
		json["MapFinalPosY"] = EndPoint.y;	// float

		string m_serializedString = json.dump();
		Name += ".json";

		ofstream m_fout;
		m_fout.open("Resources/JsonSave/maps/map_" + to_string(GameLevel) + ".json", ofstream::app);
		m_fout << m_serializedString << "\n";
		m_fout.close();

	}
	void CreateNewMap() {

	}
public:
	static GS Get() {
		return gs;
	}
	void Set(GS gs) {
		this->gs = gs;
	}
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
private:
	bool b1;
	bool b2;
	bool b3;
	bool b4;
	bool b5;
	bool b6;
	bool b7;
	bool b8;
	bool b9;
	bool b10;
public:
	void Updata();
	

};

