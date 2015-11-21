#include "cache.hpp"
#include <stdlib.h>

#define QUERIES 100000
#define CACHE_SIZE 50

int main(void){

	Cache* c = new Cache(CACHE_SIZE);
	int *out;	
	int val;
	std::cout <<  " ------- LRU CACHE ------- "<< std::endl;
	std::cout << " New element to be inserted :: Queue before insertion "
	":: Queue before insertion :: element kicked out if any" << std::endl;
	for(int i = 0; i < QUERIES; i++){
		val = rand() % 100;
		std::cout << val << " --> ";
		c->displayCache();
		std::cout << " ==> ";
		if(c->insertNode(val, &out))
			std::cout << " --> " << *out;
		std::cout << std::endl;		
	}
	return 0;
}