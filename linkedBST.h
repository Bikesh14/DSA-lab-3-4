#ifndef LINKEDBST_h
#define LINKEDBST_h
#include "binarytree.h"

class node{
	int data;
	node *left;
	node *right;
};

class LinkedBST:public BinarySearchTree
{
Private:
	node *root;
public:
	LinkedBST;
	~LinkedBST();
void preordertraversal();
bool searchBST(int data);
void addBST(int data);
void deleteBST(int data);

};
#endif
