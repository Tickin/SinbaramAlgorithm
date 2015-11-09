#ifndef BASE_TREE
#define BASE_TREE

template <typename T>
class Node{
protected:
	T data;
	Node* left, right;
public:
};

template <typename T>
class Tree{
protected:
	Node<T>* Root;
	unsigned int size;
public:
};

//Function Generate Here

#endif