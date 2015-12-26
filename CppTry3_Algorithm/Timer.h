#pragma once
#include <chrono>
#include <stdlib.h>

class Timer
{
public:
	void start();
	void end();
	double get();
private:
	std::chrono::time_point<std::chrono::system_clock> startt, endt;
	std::chrono::duration<double> elapse_seconds;
};

