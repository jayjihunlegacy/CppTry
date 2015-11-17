#pragma once
#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;

typedef struct Point
{
	int x;
	int y;
} Point;

float distance(Point a, Point b)
{
	int dx = a.x - b.x;
	int dy = a.y - b.y;
	return sqrt(dx*dx + dy*dy);
}

float minimumDistance_Naive(Point* points, int num)
{
	float min_dist = FLT_MAX;
	for (int i = 0; i < num; i++)
	{
		for (int j = i + 1; j < num; j++)
		{
			float calc = distance(points[i], points[j]);
			if (calc < min_dist)
				min_dist = calc;
		}
	}

	return min_dist;
}

void pointtest(int num)
{
	Point* points = (Point*)malloc(sizeof(Point)*num);
	srand(time(NULL));
	for (int i = 0; i < num; i++)
	{
		int genx = rand() % 1000000;
		int geny = rand() % 1000000;
		points[i].x = genx;
		points[i].y = geny;
		//printf("Point generated #%d\t: %d, %d\n", (i + 1), genx, geny);
	}
	printf("Points all generated\n");
	float naive = minimumDistance_Naive(points, num);
	printf("#1 Naive solution : %f\n", naive);
}