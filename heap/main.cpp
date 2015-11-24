#include "heap.hpp"
#include <stdlib.h>

#define KEYS 10000

int main(){

	// small inputs
	static const int arr[] = {16,2,77,29,1,8};
	vector<int> test (arr, arr + sizeof(arr) / sizeof(arr[0]));
	Heap *h = new Heap(test, MIN);
	h->insertKey(3);
	h->changeKey(2, 5);
	int* top;
	if(h->extractTop(&top));
		std::cout << "extracted: " << *top << std::endl; 
	h->printHeap();

	// large inputs
	Heap *h1 = new Heap(MIN);
	for(int i = 0; i < KEYS; i++){
		h1->insertKey(rand());
	}
	std::cout << "Testing started"<<std::endl;
	// testing
	int* temp;
	int prev;
	bool res = true;
	h1->extractTop(&temp);
	prev = *temp;
	while(res){		
		if(prev > *temp)
		{
			std::cout << "VIOLATION!!" << std::endl;
			break;
		}
		prev = *temp;
		res = h1->extractTop(&temp);
	}
	return 0;
}