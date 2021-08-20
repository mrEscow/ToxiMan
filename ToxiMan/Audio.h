// ▼
#pragma once
#include "Define.h"
class Music
{
public:

	OGG menu_music;

	Music() {

	}

	void LoadMenuMusic()
	{
		menu_music.openFromFile("Resources/audio/music/music_menu.ogg");
	}


	void LoadLevel_0() {
		// код загрузки файлов музыки
		cout << "Music Loaded: [Level 0]\n";
	}
	void LoadLevel_1() {
		cout << "Music Loaded: [Level 1]\n";
		// код загрузки файлов музыки
	}
	void Clearmemory() {
		cout << "Music Clear Memory: [Level 1]\n";
		// Код очистки памяти
	}

	~Music() {

	}
};

class Sound
{
public:

	sf::SoundBuffer button_sound;

	Sound() {

	}

	void LoadMenuSound()
	{
		button_sound.loadFromFile("Resources/audio/sounds/buttonMenu.ogg");
	}

	void LoadLevel_0() {
		// код загрузки файлов звуков
		cout << "Sound Loaded: [Level 0]\n";
	}
	void LoadLevel_1() {
		cout << "Sound Loaded: [Level 1]\n";
		// код загрузки файлов звуков
	}
	void Clearmemory() {
		cout << "Sound Clear Memory: [Level 1]\n";
		// Код очистки памяти
	}

	~Sound() {

	}
};

class Audio
{
public:

	Music music;
	Sound sound;

	Audio() {
	}

	void Crlearmemory() {
		cout << "Audio Clear Memory: (Music and Sound)\n";
		music.Clearmemory();
		sound.Clearmemory();
	}

	~Audio() {
	}
};
