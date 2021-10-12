#include "Timer.h"
namespace Escow {
	Timer::Timer(float seconds)
	{
		m_time_start = seconds * 1000;
		m_time_stop = seconds * 1000;
	}

	Timer::~Timer()
	{
	}

	bool Timer::IsOff()
	{
		cout << m_time_stop - System::time << endl;
		m_time_stop = m_time_stop - System::time;

		if (m_time_stop <= 0)
		{
			m_time_stop = m_time_start;
			return true;
		}
		else
			return false;
	}
}