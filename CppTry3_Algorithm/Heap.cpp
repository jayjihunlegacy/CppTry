#include "Heap.h"
#include <ctime>
void heaptest()
{
	Heap a;
	srand(time(NULL));
	for (int i = 0;i < 50; i++)
	{
		a.insert(rand() % 50);
		a.print();
	}
}


Heap::Heap(int s)
{
	arr = (int*)malloc(sizeof(int)*(s+1));
	num = 1;
	size = s;
}

Heap::~Heap()
{
	free(arr);
}

void Heap::insert(int var)
{
	if (size <= num)
		return;
	int pt = num;
	arr[num++] = var;
	while (1)
	{
		if (pt == 1)
			break;
		if (arr[pt] < arr[parent(pt)])
		{
			swap(arr[pt], arr[parent(pt)]);
			pt = parent(pt);
		}
		else
			break;
	}
}

void Heap::print()
{
	for (int i = 1; i < num; i++)
		printf("%d ", arr[i]);
	printf("\n");
}



int Heap::leftchild(int a)
{
	return 2 * a;
}

int Heap::rightchild(int a)
{
	return 2 * a + 1;
}

int Heap::parent(int a)
{
	return a / 2;
}
