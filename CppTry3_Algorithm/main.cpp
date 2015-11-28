#include <iostream>
#include <stdio.h>
#include <chrono>
#include <ctime>

using namespace std;

#include "Sorting.h"


int main()
{
	for (int i = 100000; i < INT_MAX; i*=1.05)
		sortingTest(i);
}