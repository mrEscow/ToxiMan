// ▼
#pragma once
#include "ResourcesManager.h"


// ППЦ КАКОЙ КРУТОЙ КЛАСС
class System
{
public:
	
	static sf::RenderWindow wnd;		// Окно
	static ResourcesManager	resources;	// Набор текстур, шрифтов, звуков и музыки (audio.sound.my_sound | audio.music.my_music)
	static sf::Event event;				// События SFML
	static sf::View cam;				// Камера вида
	static int scr_w;					// Ширина рабочего стола
	static int scr_h;					// Высота рабочего стола
	static v2f cam_p;					// Позиция камеры
	static v2f cur_p;					// Позиция курсора в глобальной системе координат
	static v2f cur_p_wnd;				// Позиция курсора в оконной системе координат (Для обработки UI)
	static float time;					// Прошедшее время каждого тика

	static float fps;					// Кадры в секунду
	static float speedGame;				// Скорость игры 
	static float zoom;					// Зум
	static v2f cur_for_UI;				// Позиция курсора в глобальной системе координат (Для обработки UI)

	// Конструктор инициализатор
	// Вызывается только один раз на старте программы
	System(string init);
	System(void);

	// Обновление полей базового класса
	static void SystemUpdate();

	// Обработчик событий закрытия окна
	static void CloseEvent();

	// Возвращает область видимости камеры
	static const sf::FloatRect GetCamVisible();

	// Возвращает нахождение pos в фигуре shape
	// Аналог ф-ии shape.getGlobalBounds.contains(pos);
	static const bool IsContains(Shape& shape, const v2f& pos);


	// Если фигура находиться внутри вида камеры 
	static const bool IsShapeInCamera(Shape& shape);

	// Вспомогательный метод-конструктор для объектов Shape
	// Пример использования - Shape shape = CreateShape(v2f(0,0), v2f(10,10), texture.my_loaded_image);
	static const Shape CreateShape(v2f pos, v2f siz, IMG& png);

	// Вспомогательный метод-конструктор для объектов Shape
	// Пример использования - Shape shape = CreateShape(v2f(0,0), v2f(10,10));
	static const Shape CreateShape(v2f pos, v2f siz);

	// Вспомогательный метод-конструктор для объектов Shape
	// Пример использования - Shape shape = CreateShape(v2f(0,0), v2f(10,10), Color::Yellow);
	static const Shape CreateShape(v2f pos, v2f siz, Color color);

	// Вспомогательный метод-конструктор для объектов Shape
	// Пример использования - Shape shape = CreateShape(v2f(0,0), v2f(10,10), -3, Color::Red, Color::Yellow);
	static const Shape CreateShape(v2f pos, v2f siz, float out_siz, Color color = Color::White, Color out_color = Color::White);

	// Вспомогательный метод-конструктор для объектов CircleShape
	// Пример использования CircleShape circleshape = (v2f(0,0), 10, 30, -3, Color::Red, Color::Yellow);
	static const CircleShape CreateCircleShape(v2f pos, float radius, std::size_t pointCount, float out_siz, Color color, Color out_color);

	// Вспомогательный метод-конструктор для объектов sf::Text
	// Пример использования sf::Text text = CreateText(v2f(0,0), 16, "Какой-то текст", font.my_loaded_font, Color::Magenta);
	static const sf::Text CreateText(v2f pos, uint siz, sf::String str, sf::Font& font, Color col);

	// Двигает шейп в указанном направлении
	static void MoveToAngle(Shape& shape, float angle, float speed);

	// Перемещает позицию текста в его центр
	// Используйте после присвоения my_text.setString("какой-то текст");
	static void CenteringText(sf::Text& text);

	// Возвращает результат нажатия на кнопку клавиатуры
	// Пример использования if(IsKeyPressed(Key::F1)) { Condition... }
	static bool IsKeyPressed(const sf::Keyboard::Key& code);

	// Возвращает результат отжатия нажатой кнопки клавиатуры
	// Пример использования if(IsKeyReleased(Key::F1)) { Condition... }
	static bool IsKeyReleased(const sf::Keyboard::Key& code);

	// Возвращает результат нажатия нажатой кнопки мышки
	// Пример использования if(IsMousePressed(sf::Mouse::Left)) { Condition... }
	static bool IsMousePressed(const sf::Mouse::Button& code);

	// Возвращает результат отжатия нажатой кнопки мышки
	// Пример использования if(IsMouseReleased(sf::Mouse::Left)) { Condition... }
	static bool IsMouseReleased(const sf::Mouse::Button& code);

	// Возвращает результат прокрутки колесика мышки
	static bool IsMouseWheelUp(const sf::Mouse::Wheel code);


	// Возвращает позицию относительно pos на расстояние dist в направлении angle
	static const v2f GetNormalizedPosition(const v2f& pos, float dist, float angle);

	// Возвращает позицию относительно центра фигуры shape на расстояние dist в направлении angle
	static const v2f GetNormalizedPosition(Shape& shape, float dist, float angle);

	// Возвращает результат соприкосновения двух окружностей
	// Принимает обычные sf::RectangleShape, используется для фигур 
	// с круглыми текстурами и прозрачностью вокруг
	// Но ничто не мешает перегрузить метод для sf::CircleShape
	static const bool GetCollisionCircle(Shape& c1, Shape& c2);

	// Возвращает результат соприкосновения двух прямоугольников
	// Принимает обычные sf::RectangleShape
	static const bool GetCollisionRect(Shape& s1, Shape& s2);

	// Возвращает расстояние между двумя точками v2f
	static const float GetDistance(const v2f& p1, const v2f& p2);

	// Возвращает расстояние между двумя объектами Shape
	static const float GetDistance(Shape& s1, Shape& s2);

	// Возвращает расстояние между Shape и v2f
	static const float GetDistance(Shape& s1, const  v2f& pos);

	// Возвращает направление в градусах отночительно точки p1 к точке p2
	static const float GetAngle(const v2f& p1, const v2f& p2);

	// Возвращает направление в градусах относительно фигуры shp к точке p
	static const float GetAngle(Shape& shp, const v2f& p);

	// Возвращает направление в градусах относительно фигуры shp1 к фигуре shp2
	static const float GetAngle(Shape& shp1, Shape& shp2);

	// Возвращает позицию фигуры в оконных координатах (для обработки в шейдоре)
	static const v2f GetPosForShader(Shape& shp);

private:

	static sf::Clock clock;
};
