#include<stdio.h>
#include<stdlib.h>
struct list
{
	int d;
	struct list *n;
};
typedef struct list node;
node *head=NULL;
node *newnode(int x)
{
	node *temp=(node *)malloc(sizeof(node));
	temp->d=x;
	temp->n=NULL;
	return temp;
}
void push(int x)
{
	if(head==NULL)
	head=newnode(x);
	else
	{
		node *t1=head,*t2=newnode(x);
		while(t1->n!=NULL)
		{
			t1=t1->n;
		}
		t1->n=t2;
	}
}
void dele()
{
	if(head==NULL)
	{
		printf("List is empty\n");
    }
    else
    {
    	node *t=head;
    	head=t->n;
    	printf("\n%d is popped\n",t->d);
    	free(t);
	}
}
void display()
{
	node *t=head;
	while(t!=NULL)
	{
		printf("%d ",t->d);
		t=t->n;
	}
	printf("\n");
}
main()
{
 int d,n;
 while(1)
 {
 	printf("Enter the choice for performing Queue operations:\n1.Push\n2.Dequeue\n3.Display\n4.Stop and exit\n");
 	scanf("%d",&d);
 	switch(d)
 	{
 		case 1:printf("Enter the element:");
 		       scanf("%d",&n);
 		       push(n);
 		       break;
 		case 2:dele();
 		       break;
 		case 3:display();
 		 	   break;
 		case 4:exit(1);
 		default:printf("Invalid option\n");
	 }
 }
	
}
