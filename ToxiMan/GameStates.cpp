#pragma once

#include "GameStates.h"

GameStates::GS GameStates::gs;

void GameStates::Updata()
{
	switch (gs)
	{
	case GameStates::GS::CHECK_MAP:
	{
		string path{ "Resources/JsonSave/maps/map_" + to_string(GameLevel) + ".json"};
		ifstream Stream_IN;

		Stream_IN.open(path);

		if (Stream_IN.is_open())
		{
			gs = GameStates::GS::START;
		}
		else
		{
			cout << "NOT_OPEN: " << path << endl;
			CreateDefaultMap();
		}

	}

	break;

	case GameStates::GS::START:
		break;
	case GameStates::GS::STOP:
		break;
	case GameStates::GS::PAUSA:
		break;
	case GameStates::GS::GAME_MENU:
		break;
	case GameStates::GS::REBOOT:
		break;


	case GameStates::GS::STOP_LEVEL:
		break;
	case GameStates::GS::NEXT_LEVEL:
		break;
	case GameStates::GS::NEW_LEVEL:
	{
		gs = GameStates::GS::START;
	}
	break;
	case GameStates::GS::BACK_LEVEL:
		break;



	case GameStates::GS::MY_NULL:
		break;

	case GameStates::GS::GO:

	{
		// WAIT 
	}

	break;

	case GameStates::GS::FINISH:
		break;
	default:
		break;
	}
}
