#include <vector>
#include <iostream>
#pragma once

using namespace std;

enum Property{

	MIN,

	MAX	
};

class Heap{

	private:

		std::vector<int> list;

		int levels;

		Property _property;

		// private functions

		void heapify();		

		int closest2powExp(int size);

		void swapper(int level);

		void swap(int c, int p);

	public:			

		Heap(std::vector<int>& list, Property p);

		Heap(int key, Property p);

		Heap(Property p);

		void insertKey(int key);

		void changeKey(int key, int val);

		int findTop();

		bool extractTop(int** val);

		void printHeap();

};