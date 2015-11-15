#pragma once
#include <stdio.h>

int minimum(int* arr, int length)
{
	int result = arr[0];
	for (int i = 1; i < length; i++)
		if (result > arr[i])
			result = arr[i];
	return result;
}