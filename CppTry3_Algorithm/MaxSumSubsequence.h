#pragma once
#include <ctime>



int maxSum_BruteForce(int* arr, int length)
{
	int maxsum = 0;
	for (int i = 0; i < length; i++)
	{
		for (int j = i; j < length; j++)
		{
			int thissum = 0;
			for (int k = i; k <= j; k++)
				thissum += arr[k];
			if (thissum > maxsum)
				maxsum = thissum;
		}
	}
	return maxsum;
}

int maxSum_Better(int* arr, int length)
{
	int maxsum = 0;
	for (int i = 0; i < length; i++)
	{
		int thissum = 0;
		for (int j = i; j < length; j++)
		{
			thissum += arr[j];
			if (thissum > maxsum)
				maxsum = thissum;
		}
	}
	return maxsum;
}

int maxSum_DivideConquer(int* arr, int s, int e)
{
	
	//printf("Divide Conquer called. Left : %d, right : %d\n", s, e);
	if (e == s + 1)
		return arr[s] > 0 ? arr[s] : 0;
	if(s==e+2)
	{
		int p1 = maxSum_DivideConquer(arr, s, s+1);
		int p2 = maxSum_DivideConquer(arr, s+1, s+2);
		return p1 > p2 ? p1 : p2;
	}
	
	int middle = (e + s) / 2;//first : [s, middle), second : [middle,e)

	int p1, p2, p3;
	p1 = maxSum_DivideConquer(arr, s, middle);
	p2 = maxSum_DivideConquer(arr, middle, e);

	p3 = 0;
	int leftmax = 0;
	int rightmax = 0;
	//probe left half
	int leftsum = 0;
	for (int i = middle - 1; i >= s; i--)
	{
		leftsum += arr[i];
		if (leftsum > leftmax)
			leftmax = leftsum;
	}
	//probe right half
	int rightsum = 0;
	for (int i = middle; i < e; i++)
	{
		rightsum += arr[i];
		if (rightsum > rightmax)
			rightmax = rightsum;
	}
	p3 = leftmax + rightmax;

	int t = (p1 > p2 ? p1 : p2);
	return t > p3 ? t : p3;
}

int maxSum_Linear(int * arr, int length)
{
	int maxsum, thissum;
	maxsum = thissum = 0;
	for (int i = 0; i < length; i++)
	{
		thissum += arr[i];
		if (thissum > maxsum)
			maxsum = thissum;
		if (thissum < 0)
			thissum = 0;
	}
	return maxsum;
}

void maxSum_Test(int T)
{
	srand(time(NULL));
	int * arr = new int[T];

	for (int i = 0; i < T; i++)
	{
		int val = rand() % 1000;
		val = val % 3 == 0 ? -val : val;
		arr[i] = val;
		//printf("%d ", arr[i] = val);
	}

	printf("\n");


	//printf("Calc using bruteFroce : ");
	//std::cout.flush();
	//printf("%d\n", maxSum_BruteForce(arr, T));
	printf("Calc using better : ");
	std::cout.flush();
	//printf("%d\n", maxSum_Better(arr, T));
	printf("Calc using even better : ");
	std::cout.flush();
	printf("%d\n", maxSum_DivideConquer(arr, 0,T));
	printf("Calc using the best : ");
	std::cout.flush();
	printf("%d\n", maxSum_Linear(arr, T));


	delete[]arr;
}