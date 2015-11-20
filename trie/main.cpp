#include "trie.hpp"
#include "node.hpp"
#include <fstream>
using namespace std;

int main(void){

	std::ifstream is;
	is.open("trie.txt");
	string data[1024];
	string p;
	int itr = 0;
	while(!is.eof()){
		is >> p;
		data[itr++] = p;
	}
	Trie *t = new Trie;
	for(int i; i < itr; i++){
		t->insert(data[i], i);		
	}
	t->display();
	return 0;
}