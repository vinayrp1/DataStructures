#include "node.hpp"
#include "string"
#pragma once

class Trie{

	private:	

		Node* root;		

		int length;

		void printer(Node* p, string s);

	public:

		Trie();

		void insert(string s, int a);

		int getValue(string s);

		bool isPresent(string s);

		void display();
};