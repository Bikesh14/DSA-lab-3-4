#include<iostream>
using namespace std;
#include "ArrayBST.h"


int main(){
	ArrayBST a;
	a.add(20);
	a.add(27);
	a.add(11);
	a.add(14);
	a.add(44);
	a.add(49);
	a.add(1);
	a.add(88);
	a.add(19);
	a.add(18);
	a.add(14);
	a.add(60);
	for(int i=0;i<MAX_SIZE;i++){
		cout<<a.elements[i]<<",";
	}
	cout<<endl;
	a.preorder(1);
	cout<<endl;
	a.search(60);
	a.search(29);
	int b;
	b=a.max();
	cout<<b<<endl;
	a.inorder(1);
	return 0;
}



