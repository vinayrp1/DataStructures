#include "node.hpp"
#include "trie.hpp"

Trie :: Trie(){

	Node* r = new Node('\0');	
	this->root = r;
	this->length = 0;
}

void Trie :: insert(string s, int a){

	Node* t = new Node;	
	t = this->root;
	int itr = 0;
	int index = 0;
	while(s[itr] != '\0'){
		if (s[itr] > 'Z')
			index = s[itr] - 'a';
		else
			index = s[itr] - 'A';
		if(!t->children[index]){
			Node *tmp = new Node;
			tmp->setCharIndex(s[itr]);
			t->children[index] = tmp;
		}
		t = t->children[index];
		itr++;
	}
	t->setValue(a);	
}

int Trie :: getValue(string s){

	return 0;
}

bool Trie :: isPresent(string s){

	Node* t = new Node;
	t = this->root;
	int itr = 0;
	int index = 0;
	while(s[itr] != '\0'){
		if (s[itr] > 'Z')
			index = s[itr] - 'a';
		else
			index = s[itr] - 'A';	
		t = t->children[index];
		if(t == NULL)
			return false;
		itr++;
	}
	if(t->getValue())
		return true;
	return false;
}

void Trie :: display(){

	Node* t = new Node;
	t = this->root;
	string tillNow = string(1, t->getCharIndex());		// char -> string
	printer(t, tillNow);	
}

void Trie :: printer(Node* p, string tillNow){

	int index = 0;
	string tN = tillNow;
	if(tN.size())
		tN = tN + p->getCharIndex();
	else
		tN = p->getCharIndex();
	Node* t = new Node;
	if(p->getValue())
		std::cout << tN << std::endl;
	for(int index = 0; index < MAX_CHILDREN; index++){	
		t = p->children[index];
		if(t){			
			printer(t, tN);
		}
	}	
}