#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
struct node
{
	int info;
	struct node *next;
};

typedef struct node Node;
Node *start = NULL;

void traversal();
void insertbeg(int item);
void insertmid(int item, int pos);
void insertlast(int item);
void deletebeg(int item);
void deletemid(int item, int pos);
void deletelast(int item);

void traversal()
{
	Node *q;
	if(start == NULL)
	{
		printf("\nList is Empty:\n");
		return;
	}
	q = start;
	printf("\nTHE LIST IS:\n");
	while(q != NULL)
	{
		printf("%d\t",q->info);
		q = q->next;
	}
	printf("\n");
}

void insertbeg(int item)
{
	Node *tmp;
	tmp = (Node*) malloc (sizeof(Node));
	tmp->info = item;
	tmp->next = start;
    start = tmp;
}

void insertlast(int item)
{
	Node *q, *tmp;
	tmp = (Node*)malloc(sizeof(Node));
	if(start == NULL)
	{
		start = tmp;
	}
	else
	{
	q = start;
	while (q->next != NULL)
	{
		q = q -> next;
	}
	tmp->info = item;
	tmp->next = NULL;
	q->next = tmp;
    }
}

void insertmid(int pos, int item)
{
	Node *tmp, *q;
	tmp = (Node*)malloc(sizeof(Node));
	if(start == NULL)
	{
		printf("\nList is EMPTY:\n");
		return;
	}
	else
	{
	q = start;
	for(int i=1; i<pos; i++)
	{
		if(q == NULL)
		{
			printf("\nThere is less number of elements than %d in the linked list:",pos);
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
	Node *tmp;
	if (start == NULL)
    {
    printf("\nList is Empty.\n");
    return;
    }
    else
    {
	tmp = start;
    start = start->next;
    printf("\nDeleted Element is: %d.", tmp->info);
    free(tmp);
    }
}
 
 void deletelast()
 {
    Node *tmp , *locp;
	if (start == NULL)
    {
    printf("\nList is Empty.");
    return;
    }
    tmp = start;
    while(tmp->next != NULL)
    {
    locp = tmp;
    tmp = tmp->next;
    }
    if (tmp == start)
	start = NULL;
    else
	locp->next = NULL;
    printf("\nDeleted Element is: %d.", tmp->info);
    free(tmp);
 }
 
 void deletemid(int pos)
 {
 	Node *tmp, *locp;
 	if (start == NULL)
    {
    printf("\nList is Empty.");
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
	printf("\nDeleted Element is: %d.", tmp->info);
    free(tmp);
 }
 
int main()
{
	char c, nap;
	int choice, num, position, data;
	do
	{
	printf("\nPress 'i' for inserting an element:\n");
	printf("\nPress 'd' for deleting an element:\n");
	printf("\nEnter your choice:");
	c = getche();
	if (c == 'i')
	{
		printf("\nPress '1' for inserting an element at begining:\n");
		printf("\nPress '2' for inserting an element at middle:\n");
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
		printf("\nPress '1' for deleting an element at begining:\n");
		printf("\nPress '2' for deleting an element at middle:\n");
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
    printf("You want to edit youe list:\n");
	printf("Tap 'y' for YES and 'n' for NO:\n");
	nap = getche();
  } while(nap == 'y' && nap != 'n');
	return 0;
}
