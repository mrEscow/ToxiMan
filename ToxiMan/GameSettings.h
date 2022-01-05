#pragma once
#include "System.h"

class GameSettings
{
private:

	static bool is_music_on;// = true;
	static float music_volume;// = 80.F;

	static bool is_sound_effect_on;// = true;
	static float sound_volume;// = 80.F;

	static UINT32 GameLevels;

public:

	GameSettings();

	static void ReadSettings();
	static void SaveSettings();

	static void SetGameLevels(UINT32 value);
	static const UINT32 GetGemeLevels();

	static void SetMusicVolume(float value);
	static const float GetMusicVolume();

	static void SetMusicOn(bool value);
	static const bool GetMusicOn();

	static void SetSoundVolume(float value);
	static const float GetSoundVolume();

	static void SetSoundOn(bool value);
	static const bool GetSoundOn();

	~GameSettings();
};