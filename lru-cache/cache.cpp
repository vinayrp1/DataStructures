#include "cache.hpp"

Cache :: Cache(int value){

	this->max_size = value;
}

void Cache :: setFNode(Node* n){

	this->front = n;
}

void Cache :: setRNode(Node* n){

	this->rear = n;
}

Node* Cache :: getFNode(){

	return this->front;
}

Node* Cache :: getRNode(){

	return this->rear;
}

int Cache :: getMaxCacheSize(){

	return this->max_size;
}

// returns true iff insertion leads to eviction of lru element
// and puts the value of evicted node in *outNode
bool Cache :: insertNode(int value, int** outNode){

	bool retVal = false;
	if(this->getRNode() == NULL && this->getFNode() == NULL){
	
		Node* t = new Node(value);
		setRNode(t);
		setFNode(t);	
		curr_size += 1;
	} else if(isValAlreadyPresent(value)){

		updateMostRecentlyUsed(value);	
	} else if(curr_size == max_size) {
	
		int val = flushLRUNode();
		*outNode = &val;
		Node* t = new Node(value);
		getRNode()->setRChild(t);
		t->setLChild(getRNode());
		setRNode(t);
		retVal = true;
	}
	else{
		Node* t = new Node(value);
		getRNode()->setRChild(t);
		t->setLChild(getRNode());
		setRNode(t);
		curr_size += 1;
	}
	displayCache();
	return retVal;
}

bool Cache :: isValAlreadyPresent(int value){

	Node* t = getFNode();
	if(t){
		if(t->getValue() == value)
			return true;
		while(t != getRNode()){
			t = t->getRChild();
			if(t == NULL)
				return false;
			if(t->getValue() == value)
				return true;			
		}
	}	
	return false;
}

void Cache :: updateMostRecentlyUsed(int value){

	Node* t1 = getFNode();
	Node* t2 = t1->getRChild();
	if(t2){
		if(t1->getValue() == value)
		{
			delete(t1);
			t2->setLChild(NULL);
			setFNode(t2);
			goto addToRear;
		}
		if(getRNode()->getValue() == value){
			return;
		}			
		while(t2->getValue() != value){
			t2 = t2->getRChild();
		}
		t1 = t2->getRChild();
		t1->setLChild(t2->getLChild());	
		t2->getLChild()->setRChild(t1);
		delete(t2);
	}
	addToRear: 
		Node* t = new Node(value);
		t->setLChild(getRNode());
		getRNode()->setRChild(t);
		setRNode(t);
		return;
}

int Cache :: flushLRUNode(){

	int value;
	Node* t = getFNode();
	value = t->getValue();
	t = t->getRChild();
	t->setLChild(NULL);
	setFNode(t);
	return value;
}

void Cache :: displayCache(){

	Node* t = getFNode();
	if(t){
		std::cout << t->getValue() << " ";
		while(t != getRNode())
		{			
			t = t->getRChild();
			std::cout << t->getValue() << " ";
		}
	}
}