#include<iostream>
#include "ArrayBst.h"

BinaryT::BinaryT(){
    std::cout<<"Tree created\n";
}

void BinaryT::addToIndex(int indexToAdd,Node* node)
{
    elements[indexToAdd] = node;
}

void BinaryT::add(int data)
{
    int indexToAdd = 1;
    Node* node = new Node();
    node->data = data;
    node->key = indexToAdd;

    if(isEmpty())
    {
        //Add data to first element of array
        addToIndex(indexToAdd,node);
    }else
    {
        Node* root = elements[1];
        insert(root, node, root->key);
    }

}


bool BinaryT::isEmpty()
{
    return (this->elements[1] == NULL);
}

void BinaryT::insert(Node* root, Node* node, int key)
{
    if(root == NULL)
    {
        node->key = key;
        elements[key] = node;
    }
    else if(root->data > node->data)
    {
        //add to left
        int leftKey = getLeftChildIndex(root->key);
        Node* left = elements[leftKey];
        insert(left,node,leftKey);
    }
    else
    {
        //add to right
        int rightKey = getRightChildIndex(root->key);
        Node* right = elements[rightKey];
        insert(right,node,rightKey);
    }
}

//Public
void BinaryT::traverse(Traverse trav)
{
    std::cout<<"****\n";
    if(isEmpty()) throw "Tree is empty";
    Node* root = elements[1];
    if(trav == LVR)
    {
        traverseLVR(root);
    }
    else if(trav == VLR)
    {
        traverseVLR(root);
    }
    else if(trav == LRV)
    {
        traverseLRV(root);
    }
    std::cout<<"\n****\n";
} 

//LVR
void BinaryT::traverseLVR(Node* root)
{
    if(root != NULL)
    {
        
        Node* left = elements[getLeftChildIndex(root->key)];
        traverseLVR(left);
        
        std::cout << root->key <<" ";

        Node* right = elements[getRightChildIndex(root->key)];
        traverseLVR(right);
    } 
}

//VLR
void BinaryT::traverseVLR(Node* root)
{
    if(root != NULL)
    {
        std::cout << root->data <<" ";
        
        Node* left = elements[getLeftChildIndex(root->key)];
        traverseVLR(left);
        
        Node* right = elements[getRightChildIndex(root->key)];
        traverseVLR(right);
    } 
}

//LRV
void BinaryT::traverseLRV(Node* root)
{
    if(root != NULL)
    {
        
        Node* left = elements[getLeftChildIndex(root->key)];
        traverseLRV(left);
        
        Node* right = elements[getRightChildIndex(root->key)];
        traverseLRV(right);

        std::cout << root->data <<" ";
    } 
}

//Public
int BinaryT::size()
{
    if(isEmpty()) return 0;
    Node* root = elements[1];
    return size(root); 
}

//Private:
int BinaryT::size(Node* root)
{
    if(root == NULL) return 0;
    Node* left = elements[getLeftChildIndex(root->key)];
    Node* right = elements[getRightChildIndex(root->key)];
    return size(left) + size(right) + 1; 
}


int BinaryT::getRightChildIndex(int key)
{
    return 2*key+1;
}

int BinaryT::getLeftChildIndex(int key)
{
    return 2*key;
}


//Searching 
bool BinaryT::dataExists(int data)
{
    if(isEmpty()) return false;
    Node* root = elements[1];
    return findInNode(root, data);
}

bool BinaryT::findInNode(Node* root, int data)
{
    if(root == NULL)return false;
    if(root->data == data)return true;
    if(root->data > data){
        Node* left = elements[getLeftChildIndex(root->key)];
        return findInNode(left,data);
    }else{
        Node* right = elements[getRightChildIndex(root->key)];
        return findInNode(right,data);
    }
}

int BinaryT::find(int data)
{
    if(isEmpty()) return 0;
    Node* root = elements[1];
    return findRootInNode(root, data);
}

int BinaryT::findRootInNode(Node* root,int data)
{
    if(root == NULL)return 0;
    if(root->data == data)return root->key;
    if(root->data > data){
        Node* left = elements[getLeftChildIndex(root->key)];
        return findRootInNode(left,data);
    }else{
        Node* right = elements[getRightChildIndex(root->key)];
        return findRootInNode(right,data);
    }
}

//remvoving part
void BinaryT::remove(int data)
{
    if(isEmpty()) throw "Tree is empty";
    int keyToBeRemoved = find(data);
    if(keyToBeRemoved == 0){
        std::cout<<"Data not found";
    }else{
        //recursively shift the data and remove the node :D
        Node* root = elements[keyToBeRemoved];
        shiftChildToRoot(root);   
    }

}

void BinaryT::shiftChildToRoot(Node* root)
{
    Node* left = elements[getLeftChildIndex(root->key)];
    Node* right = elements[getRightChildIndex(root->key)];
    

    if(left == NULL && right == NULL){
        //Its a leaf so just delete
        root = NULL;
    }
    else if(left != NULL && right != NULL)
    {
        //both left and right nodes preset

        // 1: get the largest of the two nodes
        Node* largest = (left->data > right->data) ? left : right; 
        root->data = largest->data;

        // 2: the largest child node to the top and do recursion
        shiftChildToRoot(largest);
    }
    else
    {
        //either of the node is present
        if(left == NULL)
        {
            //right
            root->data = right->data;
            shiftChildToRoot(right);

        }
        else
        {
            //left
            root->data = left->data;
            shiftChildToRoot(left);
        }

    }

}
