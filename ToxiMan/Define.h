// ▼
#pragma once
// Скрывает окно консоли при запуске программы
// #pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")

// Русификатор для GitHub
#pragma execution_character_set("utf-8")

// Подключаем набор используемых стандартных библиотек
#include <iostream>
#include <fstream>
#include <memory>
#include <cmath>
#include <list>
#include <algorithm>
#include <thread>
#include <functional>
#include <chrono>

// И конечно же библиотеки SFML
#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>
#include <SFML\Network.hpp>

// А так же библиотеку BOX2D
#include <Box2D/box2d.h>


// Определяем супер важные константы для геометрических вычислений
static constexpr auto PI = 3.141592;
static constexpr auto DEG = 57.29582;
static constexpr auto RAD = 0.017453;
static constexpr auto SCALE = 30.f; // для перевода из метров в пиксели для box2d


class System;		// Предопределяем базовый класс
typedef System B;	// Для сокращения при обращении полей и методов к базовому классу B::get()...

// Используем пространство имён для часто используемых функций стандартной библиотеки
// То же самое что и [_ using namespace std _], только для отдельных частей.
using std::cout;
using std::endl;
using std::to_string;
using std::cos;
using std::cosf;
using std::sin;
using std::sinf;
using std::atanf;
using std::make_shared;
using std::make_unique;
using std::pair;

using std::list;
using std::vector;
using std::string;
using std::unique_ptr;
using std::shared_ptr;
using std::ifstream;
using std::ofstream;
using std::thread;

// Деваем длинные название переменных и классов в более короткие
typedef unsigned int			uint;
typedef sf::Vector2i			v2i;
typedef sf::Vector2f			v2f;
typedef sf::Keyboard			Key;
typedef sf::Mouse				Button, Wheel;
typedef sf::RectangleShape		Shape;
typedef sf::CircleShape			CircleShape;
typedef sf::Texture				IMG, PNG, JPG;
typedef sf::Color				Color;
typedef sf::IntRect				IR;



