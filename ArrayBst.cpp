#include<iostream>
using namespace std;
#include "ArrayBst.h"
ArrayBST::ArrayBST(){
	for(int i=0;i<MAX_SIZE;i++){
		this->elements[i]=0;
	}	
}
ArrayBST::~ArrayBST(){}
void ArrayBST::add(int data){
	if(this->elements[1]==0){
		elements[1]=data;
	}
	else{
		for(int i=1;i<MAX_SIZE;){
			if(data<this->elements[i]){
				i=2*i;
				cout<<"Left side :\t"<<i<<endl;
			}
			else{
				i=2*i+1;
				cout<<"Right side :\t"<<i<<endl;
			}
			if(this->elements[i]==0){
				this->elements[i]=data;
				cout<<"Inserted on "<<i<<endl;
				break;
			}
		}
	}
}
bool ArrayBST::search(int data){
	for(int i=1;i<MAX_SIZE;){
		if(this->elements[i]==data){
			cout<<"Required number "<<data<<" is found in index "<<i<<" of the tree\n";
			return true;
		}
		else if (data<this->elements[i]){
				i=2*i;
			}
		else{
				i=2*i+1;
			}
	}
	cout<<"Required number "<<data<<"  is not found in the tree\n";
	return false;
}
void ArrayBST::preorder(int x){
	int l=2*x;
	int r=2*x+1;
	
	cout<<(this->elements[x])<<" ";
	if(this->elements[l]!=0)
	{
		preorder( l);
	}
	
	if(this->elements[r]!=0)
	{
		preorder( r);
	}
	
}		
	
int ArrayBST::max()
{
	for(int i=1;i<MAX_SIZE;)
	{
		if(this->elements[2*i+1]!=0)
		{
			i=2*i+1;
		}
		else
		{
			return elements[i];
		}
		
	}
	
}
	
int ArrayBST::min()
{
	
}
void ArrayBST::remove(int data)
{
}
void ArrayBST::inorder(int x)
{
	
	int l=2*x;
	int r=2*x+1;
	if(this->elements[l]!=0)
	{
		inorder( l);
	}
	cout<<(this->elements[x])<<" ";
	
	if(this->elements[r]!=0)
	{
		inorder( r);
	}
	
		
}


