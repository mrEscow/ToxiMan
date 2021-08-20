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

public:

	GameSettings();
	void CreateSettings();
	void ReadSettings();
	void SaveSettings();

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