#include "node.hpp"

Node :: Node(int value){

	this->value = value;
}

int Node :: getValue(){

	return this->value;
}

Node* Node :: getLChild(){

	return this->lChild;
}

Node* Node :: getRChild(){

	return this->rChild;
}

void Node :: setValue(int value){

	this->value = value;
}

void Node :: setLChild(Node* n){

	this->lChild = n;
}

void Node :: setRChild(Node* n){

	this->rChild = n;
}
