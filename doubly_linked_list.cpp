#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
struct Dnode
{
	int info;
	struct Dnode *rlink;
	struct Dnode *llink;
};
typedef struct Dnode dnode;
dnode *start = NULL;
dnode *last = NULL;

void traverse_doubly()
{
	dnode *q;
	int p; char ch;
	if (start == NULL)
	{
		printf("............The list is Empty............\n");
		return;
	}
	do
	{
		printf("\nEnter '1' for traversing the elements in the forward order:\n");
		printf("Enter '2' for traversing the elements in the reverse order:\n");
		scanf("%d",&p);
		printf("The Doubly Linked List contain: \n");
		if(p == 1)
		{
			q = start;
			while(q != NULL)
			{
				printf("%d\t",q->info);
				q = q->rlink;
			}
		}
		else if(p == 2)
		{
			q = last;
			while(q != NULL)
			{
				printf("%d\t",q->info);
				q = q->llink;
			}
		}
		else
		printf("\nYou enter wrong choice:\n");
	printf("\nDo you want to print the another order:\n");
	printf("Enter 'y' for traversing the another order of list:\n");
	printf("Enter 'n' to end traversing of list:\n");
	ch = getche();	
	}while(ch == 'y' && ch != 'n');
}

dnode * traverse_for_operations(int pos)
{
	dnode *q;
	int i=1;
	if (start == NULL)
	{
		printf("............The list is Empty............\n");
		return NULL;
	}
	else
	{
		q = start;
		while(i <= pos+1)
		{
			q = q->rlink;
			i += 1;
		}
	}
	return(q);
}

void insert(int data, dnode *p, dnode *q) 
{
	dnode *tmp;
	tmp = (dnode*)malloc(sizeof(dnode));
	tmp->info = data;
	tmp->llink = q;
	tmp->rlink = p;
	if(q==NULL && p== NULL)         // insert in the empty list
	{
		start = tmp;
		last = start;
	}
	else if(q==NULL && p!=NULL)     // insert at the beginning
	{
		p->llink = tmp;
		start = tmp;
	}
	else if(q!=NULL && p==NULL)     // insert at the end
	{
		q->rlink = tmp;
		last = tmp;
	}
	else
	{
		q->llink = tmp;      //insert between two nodes
		p->rlink = tmp;
	}
}

void remove(dnode *ptr)
{
	int data;
	if (start == NULL)
	{
		printf("............The list is Empty............\n");
		return;
	}
	if (ptr->llink==NULL && ptr->rlink==NULL)
	{
		start = NULL;
		last = NULL;
	}
	if (ptr->llink!=NULL && ptr->rlink==NULL)
	{
		ptr->llink->rlink = ptr->rlink;
		last = last->llink;
	}
	if (ptr->llink==NULL && ptr->rlink!=NULL)
	{
		ptr->rlink->llink = ptr->llink;
		start = start->rlink;
	}
	if (ptr->llink!=NULL && ptr->rlink!=NULL)
	{
		ptr->llink->rlink = ptr->rlink;
		ptr->rlink->llink = ptr->llink;
	}
	printf("The deleted element is: %d",ptr->info);
	free(ptr);
}

int main()
{
	int n, choice,pos;
	char c, ch;
	dnode *m;
	do
	{
		printf("\nEnter 'i' for inserting an element in the list:\n");
		printf("Enter 'd' for deleting an element in the list:\n");
		printf("Enter your choice for choosing the operation:\n");
		ch = getche();
		switch(ch)
		{
			case 'i': printf("\nEnter the element you want to insert:\n");
			          scanf("%d",&n);
			          printf("Enter '1' for inserting an element at beginning in the list:\n");
			          printf("Enter '2' for inserting an element at given position in the list:\n");
			          printf("Enter '3' for inserting an element at last in the list:\n");
			          scanf("%d",&choice);
			          if(choice == 1)
			          {
			          	insert(n, start, NULL);
			          	traverse_doubly();
					  }
					  else if(choice == 2)
					  {
					  	printf("Enter the position after which you want to insert the element in the list: ");
					  	scanf("%d",&pos);
						m = traverse_for_operations(pos);
					  	insert(n, m->rlink, m);
					  	traverse_doubly();
					  }
					  else if (choice == 3)
					  {
					  	insert(n, NULL , last);
					  	traverse_doubly();
					  }
					  else
					  {
					  	printf("You enter wrong choice:\n");
					  }
			          break;
			case 'd': printf("\nEnter '1' for deleting an element at beginning in the list:\n");
			          printf("Enter '2' for deleting an element at given position in the list:\n");
			          printf("Enter '3' for deleting an element at last in the list:\n");
			          scanf("%d",&choice);
			          if(choice == 1)
			          {
			          	remove(start);
			          	traverse_doubly();
					  }
					  else if(choice == 2)
					  {
					  	printf("Enter the position of the element which you want to delete in the list: ");
					  	scanf("%d",&pos);
						m = traverse_for_operations(pos);
						remove(m);
						traverse_doubly();
					  }
					  else if (choice == 3)
					  {
					  	remove(last);
					  	traverse_doubly();
					  }
					  else
					  {
					  	printf("You enter wrong choice:\n");
					  }
			          break;
			default:  printf("You enter wrong choice:\n");
		}
		printf("\nDo you want to edit the list:\n");
	    printf("Tap 'y' for YES and 'n' for NO:\n");		
		c = getche();
    }while(c == 'y' && c!= 'n');
}
