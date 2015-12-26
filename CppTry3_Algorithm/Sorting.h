#pragma once
#include <stdio.h>
#include <string>
#include <stdlib.h>
#include "Timer.h"
#include "RandGen.h"
/*
1. insertion sort
2. bubble sort
3. heap sort
4. quick sort
5. merge sort
*/
void swap(int &a, int&b)
{
	int tmp = a;
	a = b;
	b = tmp;
}


//1. insertion sort
void insertionSort(int* arr, int length)
{
	for(int i = 1; i < length; i++)
	{
		int tmp = arr[i];
		int j=0;
		for (j = i; j > 0 && arr[j-1] > tmp; j--)
			arr[j] = arr[j - 1];
		arr[j] = tmp;
	}
}

//2. bubble sort
void bubbleSort(int* arr, int length)
{
	printf("I don't know!!\n");
}

//3. merge sort
void mergeSort(int* arr, int s, int e)
{
	if (e == s + 1)
		return;

	int mid = (s + e) / 2;

	//sort each halves.
	mergeSort(arr, s, mid);
	mergeSort(arr, mid, e);

	//copy left half to temp.
	int* leftTemp = (int*)malloc(sizeof(int)*(mid - s));
	memcpy(leftTemp, &arr[s], (mid - s) * sizeof(int));
	
	//probe and merge.

	int* left, *right, *dest;
	left = leftTemp;
	right = &arr[mid];
	dest = &arr[s];
	for (int count = 0; count < e - s; count++)
	{
		//check out of range for Left
		if (left - leftTemp >= mid - s)
			*(dest++) = *(right++);
		//check out of range for Right
		else if (right - &arr[mid] >= e - mid)
			*(dest++) = *(left++);

		//if okay, compare
		else
			*(dest++) = *left < *right ? *(left++) : *(right++);
	}
	free(leftTemp);
}

int Partition(int* arr, int s, int e, int p)
{
	if (e == s + 1)
		return s;
	int pValue = arr[p];
	swap(arr[p], arr[e - 1]);

	int left = s - 1;
	int right = e - 1;
	while (1)
	{
		while (arr[++left] < pValue);
		while (arr[--right] > pValue);
		if (left < right)
			swap(arr[left], arr[right]);
		else
			break;
	}

	swap(arr[left], arr[e - 1]);
	return left;
}

//4. quick sort
void quickSort(int* arr, int s, int e)
{
	if (e <= s + 1)
		return;

	int p = (s + e) / 2;
	p = Partition(arr, s, e, p);
	quickSort(arr, s, p);
	quickSort(arr, p+1, e);
}

//5. count sort
void countSort(int* &arr, int length, int k)
{
	int *count = (int*)malloc(sizeof(int)*(k + 1));
	int *result = (int*)malloc(sizeof(int)*length);
	memset(count, 0, sizeof(int)*(k+1));
	for (int i = 0; i < length; i++)
		count[arr[i]]++;
	for (int i = 1; i <= k; i++)
		count[i] = count[i] + count[i - 1];
	for (int i = length - 1; i >= 0; i--)
		result[--count[arr[i]]] = arr[i];
	memcpy(arr, result, sizeof(int)*length);
	free(count);
	free(result);
}

//6. radix sort
void radixSort(int* arr, int length)
{
	int maxnum = INT_MIN;
	for (int i = 0; i < length; i++)
		maxnum = maxnum < arr[i] ? arr[i] : maxnum;
	int maxd = 0;
	for (maxd = 0; maxnum != 0;maxd++)
		maxnum /= 10;

	for (int d = 1; d <= maxd; d++)
	{

	}
}

bool isCorrect(int* a1, int* a2, int length)
{
	for (int i = 0; i < length; i++)
		if (a1[i] != a2[i])
			return false;
	return true;
}

inline int cmp(const void* a1, const void* a2)
{
	int a, b;
	a = *(int*)a1;
	b = *(int*)a2;
	return a > b ? 1 : -1;
}

void sortingTest(int T)
{
	srand(time(NULL));
	int boundary = 50000;
	//generate sample array and an answer sheet.
	int * orig = (int*)malloc(T*sizeof(int));
	int * answer = (int*)malloc(T*sizeof(int));
	arrayset(orig, T, 0, boundary);
	memcpy(answer, orig, T*sizeof(int));
	
	int* arr = (int*)malloc(T*sizeof(int));

	//prepare for time measurement
	Timer timer;
	bool correct = false;

	printf("n : %d\n",T);

	
	printf("Answer: started ..",T);
	timer.start();
	//do insertion Sort.	
	quickSort(answer, 0, T);
	//qsort(answer, T, sizeof(int), cmp);
	//end of insertion sort.
	timer.end();
	printf(" Time: %5.3fs\n", timer.get());
	



	//======================Start testing=======================

	//1. insertion sort
	memcpy(arr, orig, T*sizeof(int));
	if (T <= 120000)
	{
		printf("1. Insertion \t: started ..");
		timer.start();
		//do insertion Sort.
		insertionSort(arr, T);
		//end of insertion sort.
		timer.end();
		correct = isCorrect(arr, answer, T);
		printf(" Ans : %s, Time: %5.3fs\n", correct ? "true" : "false", timer.get());
	}

	//2. merge sort
	memcpy(arr, orig, T*sizeof(int));
	printf("2. Merge \t: started ..");
	timer.start();
	//do insertion Sort.
	mergeSort(arr, 0, T);
	//end of insertion sort.
	timer.end();
	correct = isCorrect(arr, answer, T);
	printf(" Ans : %s, Time: %5.3fs\n", correct ? "true" : "false", timer.get());

	//4. count sort
	memcpy(arr, orig, T*sizeof(int));
	printf("4. Count \t: started ..");
	timer.start();
	//do sort.
	countSort(arr, T, boundary);
	//end of sort.
	timer.end();
	correct = isCorrect(arr, answer, T);
	printf(" Ans : %s, Tier: %5.3fs\n", correct ? "true" : "false", timer.get());

	//5. radix sort
	memcpy(arr, orig, T*sizeof(int));
	printf("5. Radix \t: started ..");
	timer.start();
	//do sort.
	radixSort(arr, T);
	//end of sort.
	timer.end();
	correct = isCorrect(arr, answer, T);
	printf(" Ans : %s, Tier: %5.3fs\n", correct ? "true" : "false", timer.get());

	//6. Heap sort


	free(orig);
	free(answer);
	free(arr);
}