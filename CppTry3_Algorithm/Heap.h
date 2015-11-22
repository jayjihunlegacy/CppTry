#pragma once
#include <iostream>
#include <stdio.h>

using namespace std;

class Heap
{
public:
	Heap(int s =100);
	~Heap();
	
	void insert(int);
	int deleteMin();

	void max_heapify(int);
	void build_max_heap();
	void print();
private:
	int leftchild(int);
	int rightchild(int);
	int parent(int);

	int* arr;
	int num;
	int size;
};

void heaptest();

