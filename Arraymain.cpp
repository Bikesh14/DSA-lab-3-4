#include<iostream>
#include "ArrayBst.h"
int main(){
    BinaryT a;

    //Adding the data

    a.add(10);
    a.add(0);
    a.add(12);
    a.add(14);
    a.add(2);
    a.add(7);

    std::cout<<"\nSize is "<<a.size()<<" \n";
    std::cout<<"Pre order traversal"<<std::endl;
    a.traverse(VLR);
    std::cout<<std::endl;
    
    std::cout<<"In order traversal"<<std::endl;
    a.traverse(LVR);
    std::cout<<std::endl;
    
    std::cout<<"Post order traversal"<<std::endl;
    a.traverse(LRV);
    std::cout<<std::endl;
 
    std::cout<<"Does 2 exists ?"<<std::endl;
    if(a.dataExists(2)){
        std::cout<<"Yes\n";
    }else{
        std::cout<<"Nope\n";
    }
    std::cout<<std::endl;

    std::cout<<"Remove 0"<<std::endl;
    a.remove(0);
    std::cout<<std::endl;

    std::cout<<"In order traversal again"<<std::endl;
    a.traverse(LVR);
    std::cout<<"\nAll done";

    return 0;
}
