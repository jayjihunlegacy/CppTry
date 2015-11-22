#pragma once
#include <stdlib.h>

int max(int a, int b)
{
	return a > b ? a : b;
}

int min(int a, int b)
{
	return a > b ? b : a;
}


int cut_rod_recur(int* costs, int n, int cleng)
{
	//printf("cut_rod_recur called : %d\n", n);
	if (n == 0)
		return 0;

	int result = -1;
	int min2 = min(n, cleng);
	for (int i = 1; i <= min2; i++)
		result = max(result, costs[i] + cut_rod_recur(costs,n-i,cleng));
	return result;
}

int cut_rod_mem_sub(int*costs, int n, int cleng, int *best)
{
	if (best[n] >= 0)
		return best[n];
	if (n == 0)
		return best[n] = 0;
	int result = -1;
	int min2 = min(n, cleng);
	for (int i = 1; i <= min2; i++)
		result = max(result, costs[i] + cut_rod_mem_sub(costs, n - i, cleng,best));
	return best[n] = result;
}

int cut_rod_mem(int* costs, int n, int cleng)
{
	int * best = (int*)malloc((n + 1)*sizeof(int));
	for (int i = 0; i <= n; i++)
		best[i] = -1;
	return cut_rod_mem_sub(costs, n, cleng, best);

}
int cut_rod_bottom(int* costs, int n, int cleng)
{
	if (n == 0)
		return 0;
	int * best = (int*)malloc((n + 1)*sizeof(int));
	best[0] = 0;
	
	for (int i = 1; i <= n; i++)
	{
		int result = -1;
		int min2 = min(cleng, i);
		for (int j = 1; j <= min2; j++)
			result = max(result, costs[j] + best[i - j]);
		best[i] = result;
	}
	return best[n];
}
void cut_rod_test(int n, int key)
{
	int cleng = 10;
	int * costs = (int*)malloc((cleng + 1)*sizeof(int));
	costs[1] = 1;
	costs[2] = 5;
	costs[3] = 8;
	costs[4] = 9;
	costs[5] = 10;
	costs[6] = 17;
	costs[7] = 17;
	costs[8] = 20;
	costs[9] = 24;
	costs[10] = 30;

	printf("Ans : ");
	if(key == 1)
		printf("%d\n", cut_rod_mem(costs, n, 10));
	else if(key ==2)
		printf("%d\n", cut_rod_recur(costs, n, 10));
	else
		printf("%d\n", cut_rod_bottom(costs, n, 10));
}

void matrix_chain_test(int n)
{


}