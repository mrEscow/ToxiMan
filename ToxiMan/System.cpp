// ▼
#pragma once
#include "System.h"


// Выносим статические поля в глобальную область видимости

sf::RenderWindow		System::wnd;		// Окно
ResourcesManager		System::resources;	// Набор текстур, шрифтов, звуков и музыки (audio.sound.my_sound | audio.music.my_music)
sf::Event				System::event;		// Для обработчика событий while(wnd.pollEvent(event)) { Conditions... }
sf::View				System::cam;		// Камера вида
int						System::scr_w;		// Ширина рабочего стола
int						System::scr_h;		// Высота рабочего стола
v2f						System::cam_p;		// Позиция камеры
v2f						System::cur_p;		// Позиция курсора в глобальной системе координат
v2f						System::cur_p_wnd;	// Позиция курсора в оконной системе координат (Для обработки UI)
float					System::time;		// Прошедшее время каждого тика 
sf::Clock				System::clock;

int						System::frameLimit; // Кадры в секунду





System::System(string init)
{
	if (init == "init")
	{
		// Инициализируем поля базового класса
		scr_h = sf::VideoMode::getDesktopMode().height;
		scr_w = sf::VideoMode::getDesktopMode().width;
		wnd.create(sf::VideoMode(scr_w, scr_h), "RPG Lesson", sf::Style::Default, sf::ContextSettings(0, 0, 8));
		cam.reset(sf::FloatRect(0, 0, scr_w, scr_h));
		cam.setCenter(0, 0);
		cam_p = cam.getCenter();
		cur_p = v2f(0, 0);
		cur_p_wnd = v2f(0, 0);
		wnd.setView(cam);
		wnd.setMouseCursorVisible(true);
		frameLimit = 120;
		wnd.setFramerateLimit(frameLimit);
		srand(::time(0));
		clock.restart();

	}
}

System::System(void) { }

void System::SystemUpdate()
{
	time = float(clock.getElapsedTime().asMicroseconds()) / 1000.f, clock.restart();
	cur_p = wnd.mapPixelToCoords(sf::Mouse::getPosition(wnd));
	cur_p_wnd = v2f(sf::Mouse::getPosition(wnd));
	cam_p = cam.getCenter();
}

void System::CloseEvent()
{
	if (event.type == sf::Event::Closed || (event.type == sf::Event::KeyPressed && event.key.code == Key::Escape)) wnd.close();
	//if  (event.type == sf::Event::KeyPressed && event.key.code == Key::Escape) wnd.close();
}

const sf::FloatRect System::GetCamVisible()
{
	return sf::FloatRect(
		cam.getCenter().x - (cam.getSize().x / 2),	// X Левой части обзора
		cam.getCenter().y - (cam.getSize().y / 2),	// Y Верхней части обзора
		cam.getSize().x,							// X Размер камеры
		cam.getSize().y);							// Y Размер камеры
}

const bool System::IsContains(Shape& shape, const v2f& pos)
{
	return shape.getGlobalBounds().contains(pos);
}

const Shape System::CreateShape(v2f pos, v2f siz, IMG& png)
{
	Shape shp;
	shp.setOrigin(siz / 2.f);
	shp.setSize(siz);
	shp.setPosition(pos);
	shp.setTexture(&png);
	return shp;
}

const Shape System::CreateShape(v2f pos, v2f siz)
{
	//Geometry* geometry = Geometry::GetInstance();
	Shape shp;
	shp.setOrigin(siz / 2.f);
	shp.setSize(siz);
	shp.setPosition(pos);
	return shp;
}

const Shape System::CreateShape(v2f pos, v2f siz, Color color)
{
	Shape shp;
	shp.setSize(siz);
	shp.setOrigin(siz / 2.f);
	shp.setFillColor(color);
	shp.setPosition(pos);
	return shp;
}

const Shape System::CreateShape(v2f pos, v2f siz, float out_siz, Color color, Color out_color)
{
	Shape shp;
	shp.setSize(siz);
	shp.setOrigin(siz / 2.f);
	shp.setFillColor(color);
	shp.setPosition(pos);
	shp.setOutlineThickness(out_siz);
	shp.setOutlineColor(out_color);
	return shp;
}

const CircleShape System::CreateCircleShape(v2f pos, float radius ,std::size_t pointCount ,  float out_siz, Color color, Color out_color)
{
	CircleShape circle;

	circle.setRadius(radius);
	circle.setOrigin(radius, radius);
	circle.setPointCount(pointCount);
	circle.setFillColor(color);
	circle.setOutlineColor(out_color);
	circle.setOutlineThickness(out_siz);
	circle.setPosition(pos);



	return circle;
}

const sf::Text System::CreateText(v2f pos, uint siz, sf::String str, sf::Font& font, Color col)
{
	sf::Text text;
	text.setFont(font);
	text.setCharacterSize(siz);
	text.setFillColor(col);
	text.setString(str);
	//text.setOrigin(text.getGlobalBounds().width / 2, text.getGlobalBounds().height / 2);
	text.setPosition(pos.x, pos.y - siz / 3);
	return text;
}

void System::CenteringText(sf::Text& text)
{
	text.setOrigin(text.getGlobalBounds().width / 2.f, text.getGlobalBounds().height / 1.5f);
}

void System::MoveToAngle(Shape& shape, float angle, float speed)
{
	const float& A = angle * RAD;
	shape.move(v2f(cos(A), sin(A)) * (speed * time));
}

bool System::IsKeyPressed(const sf::Keyboard::Key& code)
{
	if (event.type == sf::Event::KeyPressed)
		if (event.key.code == code) return true;
	return false;
}

bool System::IsKeyReleased(const sf::Keyboard::Key& code)
{
	if (event.type == sf::Event::KeyReleased)
		if (event.key.code == code) return true;
	return false;
}

bool System::IsMousePressed(const sf::Mouse::Button& code)
{
	if (event.type == sf::Event::MouseButtonPressed)
		if (event.key.code == code) return true;
	return false;
}

bool System::IsMouseReleased(const sf::Mouse::Button& code)
{
	if (event.type == sf::Event::MouseButtonReleased)
		if (event.key.code == code) return true;
	return false;
}

bool System::IsMouseWheelUp(const sf::Mouse::Wheel code)
{
	if (event.mouseWheel.x == code) return true;
	return false;
}

const v2f System::GetNormalizedPosition(const v2f& pos, float dist, float angle)
{
	const float& A = angle * RAD;
	return pos + v2f(cosf(A), sinf(A)) * dist;
}

const v2f System::GetNormalizedPosition(Shape& shape, float dist, float angle)
{
	const float& A = angle * RAD;
	return shape.getPosition() + v2f(cosf(A), sinf(A)) * dist;
}

const bool System::GetCollisionCircle(Shape& c1, Shape& c2)
{
	const float r1 = c1.getSize().x / 2.f;
	const float r2 = c2.getSize().x / 2.f;
	const v2f& p1 = c1.getPosition();
	const v2f& p2 = c2.getPosition();
	return GetDistance(p1, p2) > float(r1 + r2) ? false : true;
}

const bool System::GetCollisionRect(Shape& s1, Shape& s2)
{
	return s1.getGlobalBounds().intersects(sf::FloatRect(
		s2.getPosition().x - (s2.getSize().x / 2.f),
		s2.getPosition().y - (s2.getSize().y / 2.f),
		s2.getSize().x,
		s2.getSize().y));
}

const float System::GetDistance(const v2f& p1, const v2f& p2)
{
	return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

const float System::GetDistance(Shape& s1, Shape& s2) {
	const v2f& p1 = s1.getPosition();
	const v2f& p2 = s2.getPosition();
	return GetDistance(p1, p2);
}

const float System::GetDistance(Shape& s1, const  v2f& pos)
{
	const v2f& p1 = s1.getPosition();
	return GetDistance(p1, pos);
}

const float System::GetAngle(const v2f& p1, const v2f& p2)
{
	return atan2f(p2.y - p1.y, p2.x - p1.x) * DEG;
}

const float System::GetAngle(Shape& shp, const v2f& p)
{
	return atan2f(p.y - shp.getPosition().y, p.x - shp.getPosition().x) * DEG;
}

const float System::GetAngle(Shape& shp1, Shape& shp2)
{
	const v2f& p1 = shp1.getPosition();
	const v2f& p2 = shp2.getPosition();
	return atan2f(p2.y - p1.y, p2.x - p1.x) * DEG;
}