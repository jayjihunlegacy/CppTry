#include <stdio.h>
class avlNode
{
public:
	avlNode(int el=-1, int he=0, avlNode* left=NULL, avlNode* right=NULL);
	~avlNode();
private:
	int element;
	int height;
	avlNode *left;
	avlNode *right;
};

avl