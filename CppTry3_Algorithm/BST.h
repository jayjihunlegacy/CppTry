#pragma once
#include <stdio.h>

void BST_Test();

class Node
{
public:
	Node(int val, int h=0);

	int value;
	int height;
	Node* left, *right;
};

Node* INSERT(Node*, int, int h = 0);
Node* FIND(Node*, int);

void PRINT_INORDER(Node*);

class BST
{
public:

	BST();
	void insert(int);
	void print();
	Node* find(int);
	Node* iter_find(int);

	Node* root;
};

BST* treeBuilder(int val);
void treeInserter(BST*, int, int);