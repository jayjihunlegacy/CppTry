#include "BST.h"
#include "RandGen.h"
#include "Timer.h"
void BST_Test()
{
	int max = 20000000;
	int repeat = 10;
	BST* tree = treeBuilder(max);
	printf("Construction Completed\n");
	Timer timer;
	timer.start();
	for (int i = 1; i <= max; i++)
	{
		for (int j = 0; j < repeat; j++)
		{
			Node* a = tree->find(i);
			a->value = i;
		}
	}
	timer.end();
	double recur_time = timer.get();
	printf("Recur Finished\n");
	timer.start();
	for (int i = 1; i <= max; i++)
	{
		for (int j = 0; j < repeat; j++)
		{
			Node* b = tree->iter_find(i);
			b->value = i;
		}
	}
	timer.end();
	double iter_time = timer.get();

	printf("Recursive : %3.3f, Iterative : %3.3f\n", recur_time, iter_time);
}

BST::BST()
{
	root = NULL;
}

void BST::insert(int val)
{
	root = INSERT(root, val);
}

void BST::print()
{
	PRINT_INORDER(root);
}

Node* BST::find(int val)
{
	return FIND(root, val);
}

Node* BST::iter_find(int val)
{
	Node* probe = root;
	while (probe && probe->value != val)
	{
		if (val < probe->value)
			probe = probe->left;
		else
			probe = probe->right;
	}
	return probe;
}

Node::Node(int val, int h)
{
	value = val;
	height = h;
	left = right = NULL;
}

Node* INSERT(Node* tar, int val, int h)
{
	if (!tar)
		return new Node(val,h);
	if (tar->value > val)
		tar->left = INSERT(tar->left, val, h+1);
	else if (tar->value < val)
		tar->right = INSERT(tar->right, val,h+1);
	return tar;
}

Node* FIND(Node* tar, int val)
{
	if (!tar)
		return NULL;
	if (tar->value > val)
		return FIND(tar->left, val);
	else if (tar->value < val)
		return FIND(tar->right, val);
	else
		return tar;
}

void PRINT_INORDER(Node* tar)
{
	if (!tar)
		return;
	PRINT_INORDER(tar->left);
	for (int i = 0; i < tar->height; i++)
		printf("=");
	printf("%d\n", tar->value);
	PRINT_INORDER(tar->right);
}

BST* treeBuilder(int val)
{
	BST* tree = new BST();
	treeInserter(tree, 1, val + 1);
	return tree;
}

void treeInserter(BST* tree, int s, int e)
{
	if (e <= s)
		return;
	else if (e == s + 1)
	{
		tree->insert(s);
		return;
	}
	int mid = (s + e) / 2;
	tree->insert(mid);
	treeInserter(tree, s, mid);
	treeInserter(tree, mid + 1, e);
}