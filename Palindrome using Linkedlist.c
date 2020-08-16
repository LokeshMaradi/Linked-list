#include<stdio.h>
#include<stdlib.h>
struct list
{
	int d;
	struct list *next;
};
typedef struct list node;
node *head=NULL,*head2;
node *newnode(int x)
{
	node *temp=(node*)malloc(sizeof(node));
	temp->d=x;
	temp->next=NULL;
	return temp;
}
void insert(int x)
{
	if(head==NULL)
	head=newnode(x);
	else
	{
		node *t1=head,*t2=newnode(x);
		while(t1->next!=NULL)
		{
			t1=t1->next;
		}
		t1->next=t2;
	}
}
void insertb(int b)
{
	if(head2==NULL)
	{
		head2=newnode(b);
	}
	else
	{
		node *temp;
		temp=newnode(b);
		temp->next=head2;
		head2=temp;
	}
}
void rev()
{
	node *h=head,*h2=head2;
	while(h!=NULL)
	{
		insertb(h->d);
		h=h->next;	
	}
}
void check()
{
	int k=0;
	if(head==NULL)
	printf("This is an empty list\n");
	node *h=head,*h1=head2;
	while(h!=NULL)
	{
		if(h->d==h1->d)
		{
			h=h->next;
			h1=h1->next;
		}
		else
		k=1;
	}
	if(k==0)
	printf("It is a palidrome\n");
	else
	printf("It is not a palindrome\n");
}
void display(node *h)
{
	node *t=h;
	while(t!=NULL)
	{
		printf("%d ",t->d);
		t=t->next;
	}
	printf("\n");
}
main()
{
	insert(1);
  insert(2);
  insert(2);
  insert(1);
  display(head);
  rev();
  display(head2);
  check();
}

