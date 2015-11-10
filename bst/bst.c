#include "tree.h"

extern void insertNode(struct Node **, int);
extern int searchNode(struct Node **, int);
extern void deleteNode(struct Node **, int);
extern void printTree(struct Node *);
extern int closestNode(struct Node **, int);
extern void deleteTree(struct Tree *);
extern int flag;
int main(void)
{
	struct Tree *t = malloc(sizeof(struct Tree));
	t->root = NULL;
	t->insert = insertNode;
	t->search = searchNode;
	t->deleteNode = deleteNode;
	t->closestNode = closestNode;
	t->print = printTree;
	int option, value, flag1 = 1;
	while(flag1)
	{
		printf("Enter the option: 1. Insert 2.Search 3. Print 4. Closest 5. Exit\n> ");
		scanf("%d", &option);
		switch(option)
		{
			case 1:	printf("Enter number to be inserted\n> ");
					scanf("%d", &value);
					t->insert(&(t->root), value);
					break;
			case 2: printf("Enter number to be searched\n> ");
					scanf("%d", &value);
					if(t->search(&(t->root), value))
						printf("Element found\n");
					else
						printf("Element not found\n");
					break;
			case 3: printTree(t->root);
					break;
			case 4: printf("Enter a number\n");
					scanf("%d", &value);
					flag = 1;
					printf("Closest number is %d\n", t->closestNode(&(t->root), value));
					break;
			case 5: flag1 = 0;
					break;
			default: printf("Wrong option selected\n");
		}
	}
	deleteTree(t);
	return 0;
}