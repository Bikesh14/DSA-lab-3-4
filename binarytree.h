#ifndef binarytree_h
#define binarytree_h

 class BinarySearchTree{
	private:
	public:
		virtual void preorderTraversal()=0;
		virtual void add(int data)=0;
		virtual bool search(int data)=0;
};
#endif
