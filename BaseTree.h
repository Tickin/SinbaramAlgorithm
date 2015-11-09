#ifndef _BASE_TREE
#define _BASE_TREE

#define LEFT 0
#define RIGHT 1
#define NULL 0

template <typename T>
class Node{
protected:
	T data;
	Node* left;
	Node* right;
public:
	Node<T>(T);
	T get();
	Node* getChildNode(bool);
	void setChildNode(bool, Node*);
};

template <typename T>
class Tree{
protected:
	Node<T>* root;
	unsigned int size;
public:
	Tree();
	void add(T);
};

/***************
inputData : Data of new node;
***************/

template <typename T>
Node<T>::Node(T inputData){
	data = inputData;
	left = NULL;
	right = NULL;
}

/***************
Input data to parameter
***************/

/***************
Void Parameter
***************/

template <typename T>
T Node<T>::get(){
	return data;
}

/***************
Get data of the node
***************/

/***************
direction: 0 is left, 1 is right (define as LEFT, RIGHT)
***************/

template <typename T>
Node<T>* Node<T>::getChildNode(bool direction){
	if (direction == LEFT)
		return left;
	else
		return right;

}

/***************
Get child node address depending on direction
***************/

/***************
direction: 0 is left, 1 is right (define as LEFT, RIGHT)
newNode: The node what want to insert
***************/

template <typename T>
void Node<T>::setChildNode(bool direction, Node<T>* newNode){
	if (direction == LEFT)
		left = newNode;
	else
		right = newNode;
}

/***************
Insert new node to child node of current node
***************/

/***************
Insert new node to child node of current node
***************/

template <typename T>
Tree<T>::Tree<T>(){
	root = NULL;
	size = 0;
}

/***************
Insert new node to child node of current node
***************/

/***************
inputData : Data want to insert to tree
***************/

template <typename T>
void Tree<T>::add(T inputData){
	Node<T>* newNode = new Node<T>(inputData);
	Node<T>* current = root;
	if (current == NULL){
		root = newNode;
		return;
	}

	while (1){
		if (newNode->get() < current->get()){
			if (current->getChildNode(LEFT) != NULL){
				current = current->getChildNode(LEFT);
			}
			else{
				current->setChildNode(LEFT, newNode);
				break;
			}
		}
		else{
			if (current->getChildNode(RIGHT) != NULL){
				current = current->getChildNode(RIGHT);
			}
			else{
				current->setChildNode(RIGHT, newNode);
				break;
			}
		}
	}

	size++;
}

/***************
Create new node from input data and insert to tree
***************/

#endif