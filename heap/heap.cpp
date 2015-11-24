#include "heap.hpp"
#include <cmath>

#define LEFT_CHILD(x) 2 * x
#define RIGHT_CHILD(x) 2 * x + 1
#define PARENT(x) floor(x / 2)
// defines the Heap property i.e. MIN or MAX Heap
#define CONDITION(x, y, z) z == MIN? (x < y) : (x > y)

Heap :: Heap(std::vector<int>& list, Property p){

	this->list = list;
	_property = p;
	heapify();
}

Heap :: Heap(int key, Property p){

	list.insert(list.begin() + list.size(), key);
	_property = p;
}

Heap :: Heap(Property p){

	_property = p;
}

void Heap :: heapify(){

	levels = closest2powExp(list.size());
	// bottom up approach
	for(int i = levels - 1; i >= 0; i--){
		swapper(i - 1);
	}
}

void Heap :: swapper(int curr_level){

	// swap not required for leaves
	if(curr_level == levels)
		return;
	// all nodes at curr_level will try to maintain
	// heap property with their child nodes at 
	// curr + 1
	int size = list.size();
	int level_min = pow(2, curr_level) - 1;
	int level_max = pow(2, curr_level + 1) - 1;
	for(int i = level_min; i < level_max; i++){
		if((i + 1) <= size){
			if(LEFT_CHILD(i) < size){
				if(CONDITION(list[LEFT_CHILD(i)], list[i], _property))
					swap(LEFT_CHILD(i), i);
			}
			if(RIGHT_CHILD(i) < size){
				if(CONDITION(list[RIGHT_CHILD(i)], list[i], _property))
					swap(RIGHT_CHILD(i), i);
			}
		}
	}
	swapper(curr_level + 1);
}

void Heap :: swap(int c, int p){

	list[c] = list[c] + list[p];
	list[p] = list[c] - list[p];
	list[c] = list[c] - list[p];
}

int Heap :: closest2powExp(int size){

	int e = 0;
	while(pow(2, e++) - 1 < size);
	return e - 1;
}

void Heap :: changeKey(int key, int val){

	for(int i = 0; i < list.size(); i++){
		if(list[i] == key)
			list[i] += val;
	}
	heapify();
}

void Heap :: insertKey(int key){

	// insert as last leaf and allow it to bubble up
	list.insert(list.begin() + list.size(), key);
	levels = closest2powExp(list.size());
	int index = list.size() - 1;
	int parent;
	while(index){
		parent = PARENT(index);
		if(CONDITION(list[index], list[parent], _property))
			swap(index, parent);
		// if the condition fails, no point in checking ahead since 
		// the rest of the structure follows the property
		else
			break;
		index = parent;
	}
}

int Heap :: findTop(){

	return list[0];
}

bool Heap :: extractTop(int **val){

	if(list.size() == 0)
		return false;
	int value = list[0];
	*val = &value;
	// swap root with the last leaf and heapify
	swap(0, list.size() - 1);
	list.erase(list.begin() + list.size() - 1);
	heapify();
	return true;

}

void Heap :: printHeap(){

	vector<int>::iterator i;
	for (vector<int>::iterator 	i = list.begin();
                           		i != list.end();
                           		++i)
	{
    	std :: cout << *i << endl;
	}
}