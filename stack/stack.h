#include "node.h"

struct Stack{
	struct Node *top;
	// emulating struct methods
	void (*push)(struct Stack *, int);
	void (*pop)(struct Stack *, int **);
	void (*display)(struct Stack *);
	void (*reverse)(struct Stack *);
};