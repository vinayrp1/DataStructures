#include "stack.h"

extern void popFromStack(struct Stack *, int **);
extern void pushOntoStack(struct Stack *, int);
extern void print(struct Stack *);
extern void reverseList(struct Stack *);

int main(void){

	int option, suboption;
	struct Stack *s = malloc(sizeof(struct Stack));
	s->top = NULL;
	s->push = pushOntoStack;
	s->pop = popFromStack;
	s->display = print;
	s->reverse = reverseList;
	int flag = 1;
	while(flag){
		
		printf("Enter options for stack operation 1. Push 2. Pop 3. Print 4. Reverse 5. Exit\n");
		scanf("%d", &option);
		int *a;
		switch(option){

			case 1: 	printf("Enter the number to be pushed\n");						
						scanf("%d", &suboption);
						s->push(s, suboption);
						break;

			case 2:		s->pop(s, &a);
						if(a != NULL)
							printf("Here you go: %d\n", *a);
						break;

			case 3: 	s->display(s);
						break;

			case 4: 	s->reverse(s);
						break;

			case 5:   	flag = 0;
						printf("Bye\n");
						break;			

			default:    printf("Bad option\n");
		}	
	}
	free(s);
	return 0;
}
