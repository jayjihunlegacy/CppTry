#pragma once
#include <ctime>
#include <iostream>

void arrayset(int* arr, int len, int low, int high)
{
	srand(time(NULL));
	for (int i = 0; i < len; i++)
		arr[i] = rand() % (high - low+1) + low;
}