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


int cmpX(const void* a, const void*b)
{
	Point *p1 = (Point*)a;
	Point *p2 = (Point*)b;
	return p1->x > p2->x ? 1 : -1;
}

int cmpY(const void* a, const void*b)
{
	Point *p1 = (Point*)a;
	Point *p2 = (Point*)b;
	return p1->y > p2->y ? 1 : -1;
}

float distance(Point a, Point b)
{
	int dx = a.x - b.x;
	int dy = a.y - b.y;
	return sqrt(dx*dx + dy*dy);
}

float md_DnQ(Point* points, int s, int e)
{
	if (e == s + 2)
		return(distance(points[s], points[s + 1]));
	if (e == s + 1)
		return FLT_MAX;

	int mid = (e+s) / 2;
	float d1 = md_DnQ(points, s, mid);
	float d2 = md_DnQ(points, mid, e);
	float d = d1 > d2 ? d2 : d1;
	float centX = (points[mid].x + points[mid - 1].x) / 2;

	Point** ldmz, rdmz;
	int ldmz_num, rdmz_num;
	//now gather near DMZ.
	for (int i = mid - 1; i >= s; i++)
	{
		if()
	}

}

float mimimumDistance_DnQ(Point* points, int num)
{
	qsort(points, num, sizeof(Point), cmpX);
	return md_DnQ(points, 0, num);
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