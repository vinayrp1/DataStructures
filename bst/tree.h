#include "node.h"

struct Tree
{
	
	struct Node *root;

	void (*insert)(struct Node **, int);
	int (*search)(struct Node **, int);
	void (*deleteNode)(struct Node **, int);
	void (*print)(struct Node *);
	int (*closestNode)(struct Node **, int);
};