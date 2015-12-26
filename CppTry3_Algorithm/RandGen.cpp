#include "RandGen.h"

void arrayset(int* arr, int len, int low, int high)
{
	srand(time(NULL));
	for (int i = 0; i < len; i++)
		arr[i] = rand() % (high - low + 1) + low;
}

void shuffle(int* arr, int len, int num)
{
	srand(time(NULL));
	for (int i = 0; i < num; i++)
	{
		int in1 = rand() % len;
		int in2 = rand() % len;
		_swap(arr[in1], arr[in2]);
	}
}

void _swap(int& a, int& b)
{
	int t = a;
	a = b;
	b = t;
}