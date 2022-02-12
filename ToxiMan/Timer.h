#pragma once
#include "System.h"
namespace Escow {
	class Timer
	{
		float m_time_start;
		float m_time_stop;

		bool collbek{ 0 };
	public:
		Timer();
		Timer(float seconds);
		bool IsTick();
		bool IsTick(float seconds);
		bool IsReset(float seconds);
		void Reset();

	};
}


