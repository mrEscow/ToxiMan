#include "Timer.h"
namespace Escow {
	Timer::Timer()
	{
		m_time_start = 0;
		m_time_stop = 0;
	}

	Timer::Timer(float seconds)
	{
		m_time_start = seconds * 1000;
		m_time_stop = seconds * 1000;
	}

	bool Timer::IsTick()
	{
		if (m_time_start == 0) {
			cout << "Escow::Timer = 0, give me time!" << endl;
			return false;
		}

		m_time_stop = m_time_stop - System::time;

		if (m_time_stop <= 0)
		{
			m_time_stop = m_time_start;
			return true;
		}
		else
			return false;
	}

	bool Timer::IsTick(float seconds)
	{
		if (m_time_start != seconds * 1000) {
			m_time_start = seconds * 1000;
			m_time_stop = seconds * 1000;
		}
		
		m_time_stop = m_time_stop - System::time;

		if (m_time_stop <= 0)
		{
			m_time_stop = m_time_start;
			return true;
		}
		else
			return false;
	}

	bool Timer::IsReset(float seconds)
	{
		if (m_time_start != seconds * 1000) {
			m_time_start = seconds * 1000;
			m_time_stop = seconds * 1000;
		}

		m_time_stop = m_time_stop - System::time;

		if (m_time_stop <= 0)
		{
			return true;
		}
		else
			return false;
	}

	void Timer::Reset()
	{
		m_time_stop = m_time_start;
		collbek = true;
	}

}