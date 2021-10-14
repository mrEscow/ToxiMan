#pragma once
#include "System.h"

class LifeBar
{
public:
	sf::Image image;
	sf::Texture t;
	sf::Sprite s;
	int max;
	sf::RectangleShape bar;

	LifeBar()
	{
		image.loadFromFile("Resources/images/PlayerBars/life.png");		
		image.createMaskFromColor(Color(50, 96, 166));
		t.loadFromImage(image);

		s.setTexture(t);
		s.setTextureRect(sf::IntRect(783, 2, 15, 84));

		s.setColor(Color::Red);

		bar.setFillColor(Color(0, 0, 0));//������ ������������� ������������� ������ � ���������� ������ ���������� ��������
		//bar.setFillColor(Color::Blue);
		max = 100;

		s.setRotation(90.f);
		bar.setRotation(90.f);

		s.setScale(5.f, 5.f);
		bar.setScale(5.f, 5.f);
	}

	void update(int k)// k-������� ��������

	{
		if (k > 0)
			if (k < max)
				bar.setSize(v2f(8, (max - k) * 70 / max));//���� �� ������������ � ��� ���� ������ ���������, �� ������������� ����� �������� (����� ������) ��� ������� ��������������
	}

	void draw()
	{
		v2f center = System::wnd.getView().getCenter();
		v2f size = System::wnd.getView().getSize();

		s.setPosition(center.x - size.x / 2 + 100 * 5, center.y - size.y / 2 + 10);//������� �� ������
		bar.setPosition(center.x - size.x / 2 + 95 * 5, center.y - size.y / 2 + 35);

		System::wnd.draw(s);//������� ������ ������� ��������
		System::wnd.draw(bar);//������ �� ��� ������ �������������, �� ��� �� ��������� �
	}
};

