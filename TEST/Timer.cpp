#include "Timer.h"

Timer::Timer()
{
}

Timer::~Timer()
{
}

void Timer::Update()
{
	end = GetTickCount();
	if (start != 0)
	{
		elapsed = end - start;
	}
}

void Timer::startTimer()
{
	start = GetTickCount();
}

void Timer::reset()
{
	start = 0.0f;
}
