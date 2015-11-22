#pragma once
#include <stdio.h>
#include <string>
#include <stdlib.h>
#include <chrono>
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

int partition(int* arr, int s, int e, int p)
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
	p = partition(arr, s, e, p);
	quickSort(arr, s, p);
	quickSort(arr, p+1, e);
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

	//generate sample array and an answer sheet.
	int * orig = (int*)malloc(T*sizeof(int));
	int * answer = (int*)malloc(T*sizeof(int));
	for (int i = 0; i < T; i++)
		orig[i] = rand() % 50000;
	memcpy(answer, orig, T*sizeof(int));
	
	int* arr = (int*)malloc(T*sizeof(int));

	//prepare for time measurement
	std::chrono::time_point<std::chrono::system_clock> start, end;
	std::chrono::duration<double> elapsed_seconds;
	bool correct = false;

	start = std::chrono::system_clock::now();
	printf("1. AnswerSheet : started ..");
	//do insertion Sort.
	qsort(answer, T, sizeof(int), cmp);
	//end of insertion sort.
	end = std::chrono::system_clock::now();
	elapsed_seconds = end - start;
	printf(" Time: %fs\n", elapsed_seconds.count());




	//======================Start testing=======================

	//1. insertion sort
	memcpy(arr, orig, T*sizeof(int));
	start = std::chrono::system_clock::now();
	printf("1. Insertion sort : started ..");
	//do insertion Sort.
	insertionSort(arr, T);
	//end of insertion sort.
	end = std::chrono::system_clock::now();
	elapsed_seconds = end - start;
	correct = isCorrect(arr, answer, T);
	printf(" Ans : %s, Time: %fs\n", correct ?"true":"false", elapsed_seconds.count());

	//2. merge sort
	memcpy(arr, orig, T*sizeof(int));
	start = std::chrono::system_clock::now();
	printf("2. Merge sort : started ..");
	//do insertion Sort.
	mergeSort(arr, 0, T);
	//end of insertion sort.
	end = std::chrono::system_clock::now();
	elapsed_seconds = end - start;
	correct = isCorrect(arr, answer, T);
	printf(" Ans : %s, Time: %fs\n", correct ? "true" : "false", elapsed_seconds.count());

	//3. quick sort
	memcpy(arr, orig, T*sizeof(int));
	start = std::chrono::system_clock::now();
	printf("3. Quick sort : started ..");
	//do insertion Sort.
	quickSort(arr, 0, T);
	//end of insertion sort.
	end = std::chrono::system_clock::now();
	elapsed_seconds = end - start;
	correct = isCorrect(arr, answer, T);
	printf(" Ans : %s, Time: %fs\n", correct ? "true" : "false", elapsed_seconds.count());


}