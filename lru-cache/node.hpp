#include <iostream>

#pragma once

using namespace std;

class Node{

	private:

		int value;	

		Node* lChild;

		Node* rChild;

	public:

		Node();

		Node(int value);

		int getValue();

		Node* getLChild();

		Node* getRChild();

		void setValue(int value);

		void setLChild(Node* n);

		void setRChild(Node* n);

};