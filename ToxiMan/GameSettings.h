#pragma once
#include "System.h"
#include "GameStates.h"

class GameSettings
{
private:

	bool is_music_on = true;
	float music_volume = 80.F;

	bool is_sound_effect_on = true;
	float sound_volume = 80.F;

	UINT32 GameLevels;

public:

	GameSettings();
	//void CreateSettings();
	void ReadSettings();
	void SaveSettings();

	void SetGameLevels(UINT32 value);
	const UINT32 GetGemeLevels();

	void SetMusicVolume(float value);
	const float GetMusicVolume();

	void SetMusicOn(bool value);
	const bool GetMusicOn();

	void SetSoundVolume(float value);
	const float GetSoundVolume();

	void SetSoundOn(bool value);
	const bool GetSoundOn();

	~GameSettings();
};