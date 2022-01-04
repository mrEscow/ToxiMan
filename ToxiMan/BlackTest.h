#pragma once
#include "System.h"

class Black
{
	Shape black;
	sf::Uint8 Alpha{255};
	Escow::Timer TimerAlha;

public:
	Black() {
		black.setSize(v2f(System::wnd.getSize().x, System::wnd.getSize().y));
		//black.setSize(v2f(500.f, 500.f));
		black.setFillColor(Color(0, 0, 0, Alpha));
		black.setOrigin(v2f(System::wnd.getSize().x / 2.f, System::wnd.getSize().y / 2.f));
		black.setPosition(System::cam.getCenter());
		my::S::wnd.draw(black);
	}

	~Black()
	{
		//std::lock_guard<std::mutex> guard(m_lock);

		while (Alpha != 0)
		{
			if (TimerAlha.IsTick(0.2f / 255.0f))
				Alpha--;
			black.setFillColor(Color(0, 0, 0, Alpha));
			cout << "Alpha: " << Alpha << endl;
			my::S::wnd.draw(black);
		}


		//sf::Uint8 Alpha= 0;
		//black.setSize(v2f(500.f, 500.f));
		//black.setFillColor(Color(0, 0, 0, Alpha));
		//float delta{ 3.92f };
		//while (Alpha < 255)
		//{
		//	TimeStop = TimeStop - System::time;
		//	if (TimeStop + delta < 10000) {
		//		Alpha++;
		//		//delta += 3.92f;
		//		//cout << Alpha << endl;
		//		//cout << TimeStop << endl;

		//	}
		//	black.setFillColor(Color(0, 0, 0, Alpha));
		//	my::S::wnd.draw(black);
		//}

	}

private:

	float TimeStop{ 10000 };

	static std::mutex m_lock;
};

std::mutex Black::m_lock;