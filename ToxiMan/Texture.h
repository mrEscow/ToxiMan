// ▼
#pragma once
#include "Define.h"

class Texture
{
private:

	IMG Load(const string file, bool isSmooth = false) {

		IMG texture;
		texture.loadFromFile("resources/images/" + file);
		texture.setSmooth(isSmooth); // Применяйте сглаживание только для вращающихся объектов
		return texture;
	}

public:

	IMG player;
	IMG background;

	vector<IMG> test_texture_set;
	static constexpr uint NUM_TEST_TEXTURE_SET = 10;

	Texture()
	{

	}

	// Загрузка текстур для тестового уровня 0
	void LoadLevel_0()
	{
		player = Load("player/player1.png");
		background = Load("player/background.png");
		//player = Load("player/hh.jpg", true);
		cout << "Texture Loaded: [Level 0]\n";
		//for (int i = 0; i < NUM_TEST_TEXTURE_SET; i++) test_texture_set.push_back(Load("Map/Terrain/terrain" + to_string(i) + ".png"));
	}

	void LoadLevel_1()
	{
		cout << "Texture Loaded: [Level 1]\n";
		// Код загрузки текстур для первого уровня
	}

	void ClearMemory()
	{
		test_texture_set.clear();
	}

	~Texture(void) {
	}
};
