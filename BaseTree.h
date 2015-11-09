#ifndef BASE_TREE
#define BASE_TREE

<Template T>
class Node{
protected:
	T data;
	Node* left, right;
public:
};

<Template T>
class Tree{
protected:
	Node* Root;
	unsigned int size;
public:
};

#endif