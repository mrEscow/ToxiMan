#pragma once
#include "System.h"
namespace Escow {
	class Timer
	{
		float m_time_start;
		float m_time_stop;
	public:
		Timer(float seconds);
		bool IsTick();

	};
}


