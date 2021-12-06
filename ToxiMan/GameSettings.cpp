#pragma once
#include "GameSettings.h"

/*
isMusic
volumeMusic
isSound
volumeSound
*/

GameSettings::GameSettings()
{

}

// file
void GameSettings::ReadSettings()
{
	ifstream in("Settings/Settings.txt");
	if (in.is_open()) {
		in >> is_music_on >> music_volume >> is_sound_effect_on >> sound_volume >> GameLevels;

		if (is_music_on != 1 && is_music_on != 0)
			is_music_on = true;
		if (music_volume > 100 || music_volume < 0)
			music_volume = 80.f;
		if (is_sound_effect_on != 1 && is_sound_effect_on != 0)
			is_sound_effect_on = true;
		if (sound_volume > 100 || music_volume < 0)
			sound_volume = 80.f;
	}
	else
		SaveSettings();
	in.close();
}

void GameSettings::SaveSettings()
{
	ofstream out("Settings/Settings.txt");
	out << is_music_on << endl;
	out << music_volume << endl;
	out << is_sound_effect_on << endl;
	out << sound_volume << endl;
	out << GameLevels << endl;
	out.close();
}

//GameLevels
void GameSettings::SetGameLevels(UINT32 value)
{
	GameLevels = value;
}

const UINT32 GameSettings::GetGemeLevels()
{
	return GameLevels;
}

//music
void GameSettings::SetMusicVolume(float value)
{
	music_volume = value;
}

const float GameSettings::GetMusicVolume()
{
	return music_volume;
}


void GameSettings::SetMusicOn(bool value)
{
	is_music_on = value;
}

const bool GameSettings::GetMusicOn()
{
	return is_music_on;
}
// sound
void GameSettings::SetSoundVolume(float value)
{
	sound_volume = value;

}

const float GameSettings::GetSoundVolume()
{
	return sound_volume;
}


void GameSettings::SetSoundOn(bool value)
{
	is_sound_effect_on = value;
}

const bool GameSettings::GetSoundOn()
{
	return is_sound_effect_on;
}
GameSettings::~GameSettings()
{
}

