#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct Stack
{
	int item;
	struct Stack *next;
};
typedef struct Stack stack;
stack *top;
bool isempty()
{
	return (top == NULL);
}
void traverse()
{
	if (isempty())
	{
	printf("\n..........LIST is UNDERFLOW..........");
	return;
	}
	stack *t = top;
	printf("\nThe elements present in the stack:\n");
	while(t != NULL)
	{
		printf("%d\t",t->item);
		t = t->next; 
	}
}
void push(int data)
{
	stack *tmp;
	tmp = (stack*)malloc(sizeof(stack));
	tmp->item = data;
	tmp->next = top;
	top = tmp;
}
int pop()
{
	int data;
	stack *tmp;
	if (isempty())
	{
	printf("\n...............LIST is UNDERFLOW...............");
	return -1;
	}
	tmp = top;
	data = top->item;
	top = top->next;
	free(tmp);
	return(data);
}
int main()
{
	top = NULL;
	char c,choice;
	int num;
	do
	{
	printf("\nDo you want to edit the stack?");
	printf("\nPress 'y' for YES and 'n' for NO:\n");
	c = getche();
	printf("\nDo you want to push or pop an element:");
	printf("\nPress 'i' for pushing an element:");
	printf("\nPress 'd' for poping an element:\n");
	choice = getche();
	switch(choice)
	{
		case 'i': printf("\nEnter the element you want to push:\n");
	              scanf("%d",&num);
	              push(num);
	              traverse();
	              break;
	    case 'd': printf("\nThe pop element is %d.\n",pop());
	              traverse();
		          break; 
		default: printf("\nYou enter invalid choice.\n");		           
	}
	}while(c != 'n'); 
	return 0;
}
