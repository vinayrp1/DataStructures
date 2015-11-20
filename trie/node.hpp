#include <iostream>
#include <map>
#include <string>

#pragma once

using namespace std;

#define MAX_CHILDREN 26

class Node{

	private:

		char c;

		int value;	

	public:

		Node* children[MAX_CHILDREN];

		Node();

		Node(char ch);

		char getCharIndex();

		void setCharIndex(char ch);

		void setValue(int p);

		int getValue();
};