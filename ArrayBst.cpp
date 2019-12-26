# include<iostream>
using namespace std;

#include"ArrayBst.hpp"

ArrayBst:: ArrayBst(){
	this -> elements[0]=0;
}

void ArrayBst:: add(int data)
{
	if(this-> elements[0] ==0){
		this-> elemens[1]=data;
		
	}
	else{
		
		for(int i=1; i<=MAX_SIZE;){
		
		if(data < this->elements[i]){
			//insert to the left
			i=2*i;
		}
		else{
		
			i=2*i+1;
		}
			if(this->elements[2*i]== 0){
				this->elements[i]=data;
				break;
			}
		}
	}
	
}


