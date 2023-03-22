#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
struct Cnode
{
	int info;
	struct Cnode *next;
};

typedef struct Cnode cnode;
cnode *start = NULL;

void traversal();
void insertbeg(int item);
void insertmid(int item, int pos);
void insertlast(int item);
void deletebeg(int item);
void deletemid(int item, int pos);
void deletelast(int item);

void traversal()
{
	cnode *q;
	if(start == NULL)
	{
		printf("\n............Circular List is Empty............\n");
		return;
	}
	q = start;
	printf("The Circular Linked List is:\n");
	while(q->next != start)
	{
		printf("%d\t",q->info);
		q = q->next;
	}
	printf("%d",q->info);
}

void insertbeg(int item)
{
	cnode *tmp, *q;
	tmp = (cnode*) malloc (sizeof(cnode));
	tmp->info = item;
	if(start == NULL)
	{
		start = tmp;
		tmp->next = start;
	}
	else
	{
	tmp->next = start;
	q = start;
	while(q != start)
		q = q->next;
	start = tmp;
	q->next = start;
	}
}


void insertlast(int item)
{
	cnode *q, *tmp;
	tmp = (cnode*)malloc(sizeof(cnode));
	tmp->info = item;	
	if(start == NULL)
	{
		start = tmp;
	}
	else
	{
	q = start;
	while (q->next != start)
	{
		q = q -> next;
	}
	q->next = tmp;	
	tmp->next = start;	
    }
}

void insertmid(int pos, int item)
{
	cnode *tmp, *q;
	tmp = (cnode*)malloc(sizeof(cnode));
	if(start == NULL)
	{
		printf("\n............Circular List is EMPTY............\n");
		return;
	}
	else
	{
	q = start;
	for(int i=1; i<pos; i++)
	{
		if(q->next == start)
		{
			printf("\nThere is less number of elements than %d in the Circular linked list:",pos);
			return;
		}
		q = q->next;
	}
	tmp->info = item;
	tmp->next = q->next;
	q->next = tmp;
    }
}

void deletebeg()
{
	cnode *tmp, *q;
	if (start == NULL)
    {
    printf("\n............Circular List is Empty............\n");
    return;
    }
    tmp = start;
    if(start->next == start)
    {
    	start = NULL;
	}
	else
	{
		start = start->next;
		q = start;
		while(q->next != tmp)
		{
			q = q->next;
		}
		q->next = start;
    }
    printf("\nDeleted Element is: %d.\n", tmp->info);
	free(tmp);
}
 
 void deletelast()
 {
    cnode *tmp , *locp;
	if (start == NULL)
    {
    	printf("\n............Circular List is Empty............");
		return;
    }
    if (start == start->next)
    {
    	tmp = start;
    	start = NULL;
    }
    else
    {
    	locp = start;
    	tmp = start->next;
		while(tmp->next != start)
		{
			locp = tmp;
			tmp = tmp->next;
        }
    	locp->next = start;
    }
	printf("\nDeleted Element is: %d.", tmp->info);
	free(tmp);
 }
 
 void deletemid(int pos)
 {
 	cnode *tmp, *locp;
 	if (start == NULL)
    {
    printf("\n............Circular List is Empty............");
    return;
    }
    tmp = start;
	for(int i=0; i<pos; i++)
	{
	if(tmp->next == NULL)
	{
	printf("\nThere is less number of elements than  position %d in the linked list.",pos);
	}
	locp = tmp;
	tmp = tmp->next;
	}
	locp->next = tmp->next;
	printf("\nDeleted Element is: %d.\n", tmp->info);
    free(tmp);
 }
 
int main()
{
	char c, nap;
	int choice, num, position, data;
	do
	{
	printf("\nPress 'i' for inserting an element:");
	printf("\nPress 'd' for deleting an element:");
	printf("\nEnter your choice: ");
	c = getche();
	if (c == 'i')
	{
		printf("\nPress '1' for inserting an element at beginning:");
		printf("\nPress '2' for inserting an element at given position:");
		printf("\nPress '3' for inserting an element at last:\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: printf("Enter the element you want to insert:\n"); 
			        scanf("%d",&data);
			        insertbeg(data);
			        traversal();
			        break;
			case 2: printf("Enter the element you want to insert:\n");
			        scanf("%d",&data);
			        printf("Enter the position after which you want to insert the element:\n");
			        scanf("%d",&position);
			        insertmid(position,data);
			        traversal();
			        break;
			case 3: printf("Enter the element you want to insert:\n");
			        scanf("%d",&data);
			        insertlast(data);
			        traversal();
			        break;
		   default: printf("You enter wrong choice.\n");		        
		}
	}
	else if (c == 'd')
	{
		printf("\nPress '1' for deleting an element at beginning:");
		printf("\nPress '2' for deleting an element at given position:");
		printf("\nPress '3' for deleting an element at last:\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: deletebeg();
			        traversal();
			        break;
			case 2: printf("Enter the position on which you want to delete the element:\n");
			        position = scanf("%d",&position);
			        deletemid(position);
			        traversal();
			        break;
			case 3: deletelast();
			        traversal();
			        break;
			default: printf("You enter wrong choice.\n");        
		}
	}
	else
	{
	printf("\nYou enter wrong choice.\n");
    }
    printf("\nYou want to edit your list:\n");
	printf("Tap 'y' for YES and 'n' for NO:\n");
	nap = getche();
  } while(nap == 'y' && nap != 'n');
	return 0;
}
