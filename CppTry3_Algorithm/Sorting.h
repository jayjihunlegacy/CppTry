#pragma once
#include <stdio.h>
#include <string>
#include <stdlib.h>
/*
1. insertion sort
2. bubble sort
3. heap sort
4. quick sort
5. merge sort
*/
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
	int l, r;
	l = r = 0;

	int* left, *right, *dest;
	left = leftTemp;
	right = &arr[mid];
	dest = &arr[s];
	for (int count = 0; count < e - s; count++)
	{
		//check out of range for Left

		//check out of range for Right

		//if okay, compare
		*(dest++) = *left < *right ? *(right++) : *(left++);
	}

}