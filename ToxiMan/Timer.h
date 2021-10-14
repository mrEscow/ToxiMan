#pragma once
#include "System.h"
namespace Escow {
	class Timer
	{
		float m_time_start;
		float m_time_stop;
	public:
		Timer();
		Timer(float seconds);
		bool IsTick();
		bool IsTick(float seconds);

	};
}


