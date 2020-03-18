#include<iostream>
using namespace std;
#include "ArrayBST.h"


int main(){
	ArrayBST a;
	a.add(15);
	a.add(10);
	a.add(11);
	a.add(14);
	a.add(13);
	a.add(4);
	a.add(1);
	a.add(5);
	a.add(16);
	a.add(18);
	a.add(17);
	a.add(20);
	for(int i=0;i<MAX_SIZE;i++){
		cout<<a.elements[i]<<",";
	}
	cout<<endl;
	a.preorder(1);
	cout<<endl;
	a.search(33);
	a.search(29);
	int b;
	b=a.max();
	cout<<b<<endl;
	a.inorder(1);
	return 0;
}

