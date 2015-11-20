#include "node.hpp"

Node :: Node(){

	for(int i; i < MAX_CHILDREN; i++){
		this->children[i] = NULL;
	}
}

Node :: Node(char ch){

	this->c = ch;
	for(int i; i < MAX_CHILDREN; i++){
		this->children[i] = NULL;
	}
}

char Node :: getCharIndex(){

	return this->c;
}

void Node :: setCharIndex(char ch){

	this->c = ch;
}

void Node :: setValue(int v){

	this->value = v;
}

int Node :: getValue(){

	return this->value;
}

