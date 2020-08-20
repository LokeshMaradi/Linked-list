#include<stdio.h>
#include<stdlib.h>
struct list
{
	int d;
	struct list *next;
};
typedef struct list node;
node *head=NULL;
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
int count()
{
    int c=0;
    node *tp2=head,*tp3=head;
	do
	{
		tp2=tp2->next;
		c++;
	}
	while(tp2!=NULL);
	return c;
}
void rev(int n)
{
	int *a,i=0;node *h=head;
	a=(int *)malloc(n*sizeof(int));
	for(i=0;i<n;i++)
	{
		*(a+i)=h->d;
		h=h->next;
	}
	h=head;
	for(i=n-1;i>=0;i--)
	{
		h->d=*(a+i);
		h=h->next;
	}
	free(a);
}
void display()
{
	if(head==NULL)
	printf("\nList is empty");
	else
	{
		node *tp1;
		tp1=head;
		do
		{
			printf("%d ",tp1->d);
			tp1=tp1->next;
		}
		while(tp1!=NULL);
		printf("\n");
	}
}
main()
{
  insert(1);
  insert(2);
  insert(3);
  insert(4);
  display();
  int c;
  c=count();
  rev(c);
  display();
   	
}	
