# ifndef ArrayBst.hpp
# def
# include<iostream>
using namespace std;

class ArrayBST : public BinarySearchTree
{
private: 
	int elemets[16];
public:
	
	void preorderTraversal();
	void add(int data);
	bool search (int date);
			
}
