#include "stack.h"

void popFromStack(struct Stack *this, int **a){

	int t;
	struct Node *tmp1 ;
	tmp1 = this->top;
	if(this->top == NULL){
		//*a = NULL;
		free(*a);
		free(a);
		*a = NULL;
		printf("nothing to pop\n");
		return;
	}
	else if(this->top->next != NULL){
		
		while(tmp1->next->next != NULL)
		{
			tmp1 = tmp1->next;
		}
		t = tmp1->next->value;
		*a = &t;
		free(tmp1->next);
		tmp1->next = NULL;
	}
	else{
		*a = malloc(sizeof(int));
		t = this->top->value;
		*a = &t;
		free(this->top);
		this->top = NULL;
	}
	return;
}

void pushOntoStack(struct Stack *this, int x){

	struct Node *tmp = malloc(sizeof(struct Node));
	tmp->value = x;
	tmp->next = NULL;
	struct Node *tmp1;
	tmp1 = this->top;
	if(this->top == NULL)
	{
		this->top = tmp;
	}
	else
	{
		while(tmp1->next != NULL)
		{
			tmp1 = tmp1->next;
		}
		tmp1->next = tmp;
	}
	return;
}

void print(struct Stack *this){

	struct Node *n;
	n = this->top;
	while(n != NULL){
		printf("%d\n", n->value);
		n = n->next;
	}
	free(n);
	return;
}

void reverseList(struct Stack *this)
{
	struct Node *n1, *n2;
	if(this->top != NULL) 
	{
		if(this->top->next != NULL)
		{
			n1 = this->top;
			n2 = NULL;
			while(this->top != NULL)
			{
				this->top = this->top->next;
				n1->next = n2;
				n2 = n1;	
				n1 = this->top;			
			}
			this->top = n2;
		}
	}
}