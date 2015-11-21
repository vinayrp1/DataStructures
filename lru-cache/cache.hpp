#include "node.hpp"

#pragma once

class Cache{

	private:

		int max_size;

		int curr_size;

		Node* front;

		Node* rear;

		// private functions

		bool isValAlreadyPresent(int value);

		void updateMostRecentlyUsed(int value);

		int flushLRUNode();

	public:

		Cache(int value);

		void setFNode(Node* n);

		void setRNode(Node* n);

		int getMaxCacheSize();

		int getCurrCacheSize();

		Node* getFNode();

		Node* getRNode();

		bool insertNode(int value, int** outNode);

		void displayCache();
		
};