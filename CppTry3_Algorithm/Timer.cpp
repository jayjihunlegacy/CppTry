#include "Timer.h"
void Timer::start()
{
	startt = std::chrono::system_clock::now();
}

void Timer::end()
{
	endt = std::chrono::system_clock::now();
	elapse_seconds = endt - startt;
}

double Timer::get()
{
	return elapse_seconds.count();
}