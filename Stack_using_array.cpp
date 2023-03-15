#include<stdio.h>
#include<conio.h>
#define stacksize 10

struct Stack
{
	int top;
	int item[stacksize];
}; 
typedef struct Stack stack;
stack s;


bool isempty( )
{
  return (s.top == -1);
}

void traverse()
{
	if (isempty())
	{
	printf("\n..........LIST is UNDERFLOW..........");
	return;
	}
	int d = s.top;
	printf("\nThe elements present in the stack:\n");
	while(d != -1)
	{
		printf("%d\t",s.item[d]);
		d = d-1; 
	}
}
void push(int data)
{
  if (s.top == stacksize - 1)
  {
    printf("\n..........LIST is OVERFLOW..........");
    return;
  }
  s.top += 1;
  s.item[s.top] = data;
}

int pop()
{
  int data;
  if (isempty())
  {
    printf("\n..........LIST is UNDERFLOW..........");
    return -1;
  }
  data = s.item[s.top];
  s.top -= 1;
  return(data);
}

int main()
{
	s.top = -1;
	char c,choice;
	int num;
	do
	{
	printf("\nDo you want to edit the stack?");
	printf("\nPress 'y' for YES and 'n' for NO\n");
	c = getche();
	printf("\nDo you want to push or pop an element");
	printf("\nPress 'i' for pushing an element");
	printf("\nPress 'd' for poping an element\n");
	choice = getche();
	switch(choice)
	{
		case 'i': printf("\nEnter the element you want to push\n");
	              scanf("%d",&num);
	              push(num);
	              traverse();
	              break;
	    case 'd': printf("\nThe pop element is %d",pop());
	              traverse();
		          break; 
		default: printf("\nYou enter invalid choice");		           
	}
    }while(c != 'n'); 
	return 0;
}
