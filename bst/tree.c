#include "tree.h"

int diff, ckey;
int flag = 1;

struct Node* getNewNodePtr(int x)
{
	struct Node *n = malloc(sizeof(struct Node));
	n->value = x;
	n->lChild = NULL;
	n->rChild = NULL;
	return n;
}

void insertNode(struct Node **this, int x)
{

	if(*this == NULL)
		*this = getNewNodePtr(x);
	else if(x <= (*this)->value)
		insertNode(&(*this)->lChild, x);
	else
		insertNode(&(*this)->rChild, x);
	return;
}

int searchNode(struct Node **this, int x)
{
	if(*this)
	{
		if(((*this)->value) == x)
		{
			return 1;
		}
		else if(searchNode(&((*this)->lChild), x) + searchNode(&((*this)->rChild), x))
				return 1;
	}		
	return 0;
}

void deleteNode(struct Node **this)
{
	if(*this)
	{
		deleteNode(&(*this)->lChild);
		deleteNode(&(*this)->lChild);
	}
	free(*this);
	*this = NULL;
	return;
}

void printTree(struct Node *r)
{
	if(r != NULL)
		printf("%d\n", r->value);
	else
		return;
	if(r->lChild != NULL)
		printTree(r->lChild);
	if(r->rChild != NULL)
		printTree(r->rChild);
}

void deleteTree(struct Tree *this)
{
	if(this)
		deleteNode(&(this->root));
}

int closestNode(struct Node **this, int x)
{
	int key;
	if(*this)
	{
		key = (*this)->value;
		if((abs(key - x) < diff) || flag == 1)
		{
			diff = abs(key - x);
			ckey = key;
			flag = 0;
		}
		printf("%d %d\n", diff, key);
		closestNode(&((*this)->lChild), x);
		closestNode(&((*this)->rChild), x);
	}	
	return ckey;
}