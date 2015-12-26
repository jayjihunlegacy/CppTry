#include "Selection.h"
#include "Sorting.h"
#include "RandGen.h"


int Middle_Partition(int* arr, int s, int e)
{
	return Partition(arr, s, e, (s + e) / 2);
}

int Randomized_Partition(int* arr, int s, int e)
{
	return Middle_Partition(arr, s, e);
}

int Randomized_Select(int* arr, int s, int e, int k)
{
	int pivPos = Randomized_Partition(arr, s, e);
	if (k == pivPos)
		return arr[k];
	else if (k < pivPos)
		return Randomized_Select(arr, s, pivPos, k);
	else
		return Randomized_Select(arr, pivPos + 1, e, k);
}



void Selection_Test()
{
	int len = 1000;
	int* array = new int[len];
	for (int i = 0; i<len; i++)
		array[i] = len - i;

	shuffle(array, len, len);

	for (int i = 0; i < len; i++)
		printf("%d ", array[i]);
	printf("\n");

	/*
	printf("===========BY Randomized_Selection========\n");
	for (int i = 0; i<len; i += 10)
		printf("%dth number is : %d\n", i + 1, Randomized_Select(array, 0, len, i));
		*/


	printf("\n\n===========BY Deterministic_Selection========\n");
	int i = 50;
	printf("%dth number is : %d\n", i + 1, Select(array, 0, len, i));
	//for (int i = 0; i < len; i+= 10)
	//	printf("%dth number is : %d\n", i + 1, Select(array, 0, len, i));
	delete array;
}

void Minimum(int* arr, int num)
{
	if (num <= 0)
		return;
	int min = arr[0];
	for (int i = 1; i < num; i++)
		if (arr[i] < min)
			min = arr[i];

	printf("Minimum is : %d\n", min);
}

void Maximum(int* arr, int num)
{
	if (num <= 0)
		return;
	int max = arr[0];
	for (int i = 1; i < num; i++)
		if (arr[i] > max)
			max = arr[i];

	printf("Maximum is : %d\n", max);
}

void Minimum_and_Maximum(int* arr, int num)
{
	if (num < 2)
		return;
	int min = arr[0];
	int max = arr[1];
	if (min > max)
		swap(min, max);


	//last One element is not considered.
	for (int i = 1; i < num / 2; i++)
	{
		int v1 = arr[i * 2];
		int v2 = arr[i * 2 + 1];
		if (v1 > v2)
			swap(v1, v2);
		if (v1 < min)
			min = v1;
		if (v2 > max)
			max = v2;
	}

	//consider One element 
	if(num%2 != 0)
	{
		if (min > arr[num - 1])
			min = arr[num - 1];
		else if (max < arr[num - 1])
			max = arr[num - 1];			
	}
	printf("Minimum : %d, Maximum : %d\n", min, max);
}

void Min_Max_Test()
{
	int n = 102;
	int* arr = new int[n];
	for (int i = 0; i < n; i++)
		arr[i] = i;
	shuffle(arr, n, 100);
	
	Minimum(arr, n);
	Maximum(arr, n);
	Minimum_and_Maximum(arr, n);
}


int comp_int(const void* a, const void* b)
{
	return *(int*)a < *(int*)b ? -1 : 1;
}

int Select(int* arr, int s, int e, int k)
{
	int length = e - s;
	if (length < 30)
	{
		qsort(&arr[s], length, sizeof(int), comp_int);
		return arr[k];
	}

	int medianLength = (length + 4) / 5;
	int* medians = new int[medianLength];

	for (int i = 0; i < medianLength-1; i++)
	{
		int start = s + 5 * i;
		int end = s + 5 * (i + 1);
		int newk = (end + start) / 2;
		medians[i] = Select(arr, start, end, newk);
	}
	int laststart = s + 5 * (medianLength - 1);
	medians[medianLength - 1] = Select(arr, laststart, e, (laststart + e) / 2);

	int medianOfmedian = Select(arr, 0, medianLength, medianLength / 2);
	printf("Median of median : %d\n", medianOfmedian);


	return 0;
}