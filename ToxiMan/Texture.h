// ▼
#pragma once
#include "Define.h"

class Texture
{
private:

	IMG Load(const string file, bool isSmooth = false, bool isRepeated = false) {

		IMG texture;
		texture.loadFromFile("resources/images/" + file);
		
		texture.setSmooth(isSmooth); // Применяйте сглаживание только для вращающихся объектов

		texture.setRepeated(isRepeated); // если нужна прокрутка
		
		return texture;
	}

public:

	IMG player;
	IMG skaermbillede;

	IMG arhitectMouse;

	IMG background;

	IMG backOne;
	IMG backTwo;
	IMG backTree;

	IMG bg5_a;
	IMG bg5_b;
	IMG bg5_c;
	IMG bg5_d;
	IMG bg5_e;

	IMG bg5_g;

	PNG menu_background;
	PNG menu_button;
	PNG menu_checkbox_ON;
	PNG menu_checkbox_OFF;
	PNG menu_skrol_1;
	PNG menu_skrol_2;

	// Map Editor
	PNG menu_Enemy;
	PNG menu_Player;
	PNG menu_Platforms;
	PNG menu_SizeMap;
	PNG menu_StaticCube;


	vector<IMG> test_texture_set;
	static constexpr uint NUM_TEST_TEXTURE_SET = 10;

	Texture()
	{

	}

	// Загрузка для мeню
	void LoadMenu()
	{
		menu_background = Load("Menu/back_ground.png");
		menu_button = Load("Menu/Button_1.png");
		menu_checkbox_ON = Load("Menu/checkboxON.png");
		menu_checkbox_OFF = Load("Menu/checkboxOFF.png");
		menu_skrol_1;
		menu_skrol_2;
	}

	// Загрузка для MapEditor
	void LoadMapEditor()
	{
		menu_Enemy = Load("MapEditor/Enemy.png");
		menu_Player = Load("MapEditor/Player.png");
		menu_SizeMap = Load("MapEditor/Size_Map.png");
		menu_StaticCube = Load("MapEditor/Static_Cube.png");
		menu_Platforms = Load("MapEditor/Platforms.png");
	}

	// Загрузка для архитектора
	void LoadForArhitect() {
		
		sf::Image image;
		image.loadFromFile("resources/images/arhitect/mouse.png");
		
		image.createMaskFromColor(Color::White);

		arhitectMouse.loadFromImage(image);

	}
	// Загрузка текстур для тестового уровня 0
	void LoadLevel_0()
	{
		player = Load("player/player1.png");

		skaermbillede = Load("Guns/skaermbillede.png");

		//background = Load("background/background.png", false, true);

		backOne = Load("background/backOne.png", false, true);
		backTwo = Load("background/backTwo.png");
		backTree = Load("background/backTree.png");

		bg5_a = Load("background/BG5/bg5_a.png", true);
		bg5_b = Load("background/BG5/bg5_b.png", true);
		bg5_c = Load("background/BG5/bg5_c.png", true);
		bg5_d = Load("background/BG5/bg5_d.png", true);
		bg5_e = Load("background/BG5/bg5_e.png", true);

		bg5_g = Load("background/BG5/bg5_g.png", true, true);;
	
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
