#include <iostream>
using namespace std;
#include "ArrayBST.cpp"



int main(){
	ArrayBST a;
	a.add(1);
	a.add(9);
	a.add(21);
	a.add(7);
	a.add(46);
	a.add(33);
	a.add(21);
	a.add(28);
	cout<<"[";
	for(int i=0;i<MAX_SIZE;i++){
		cout<<a.elements[i]<<",";
	}
	cout<<"]"<<endl;
	a.preorderTraversal();
	cout<<endl;
	a.search(33);
	a.search(29);
	return 0;
}
