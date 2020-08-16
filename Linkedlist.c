#include<stdio.h>
#include<stdlib.h>
struct list
{
	int d;
	struct list *next;
};
typedef struct list node;
node *head=NULL,*tail=NULL;
node *newnode(int x)
{
	node *temp=(node*)malloc(sizeof(node));
	temp->d=x;
	temp->next=NULL;
	return temp;
}
void insertb(int b)
{
	if(head==NULL)
	{
		head=tail=newnode(b);
	}
	else
	{
		node *temp;
		temp=newnode(b);
		temp->next=head;
		head=temp;
	}
}
void deleteb()
{
	if(head==NULL)
	printf("\nList is empty");
	else
	{
	
		node *tp=head;
		head=tp->next;
		free(tp);
		
        if(head==NULL)
		tail=NULL;	
	}
}
void deleteend()
{
    if(head==NULL)
	printf("\nList is empty");
	else{
		 if(head==tail)
		 {
		 	free(head);
		 	head=tail=NULL;
		 }
	
	else
	{
		node *h=head;
		while(h->next->next!=NULL)
		{
			h=h->next;
		}
		node *temp=h->next;
		h->next=temp->next;
		free(temp);
		tail=h;
	}
}
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
	}
}
node* searchnode(int z)
{
	for(node *temp=head;temp!=NULL;temp=temp->next)
	{
		if(temp->d==z)
		return temp;
	}
	return NULL;
}
void insertafter(int z,int n)
{
	node *current=searchnode(n);
	if(current==NULL)
	return;
	else
	{
		node *temp=newnode(z);
		temp->next=current->next;
		current->next=temp;
	}
}
void delmid(int x)
{
	node *current=searchnode(x);
	if(current==NULL||current->next==NULL)
	{
		printf("cant\n");return;
	}
	else
	{
		node *tp=current->next;
		current->next=tp->next;
		printf("\n%d is deleted\n",tp->d);
		free(tp);
	}
}
void getmid()
{        int c=0;
        node *tp2=head,*tp3=head;
	 	do
		{
			tp2=tp2->next;
			c++;
		}
		while(tp2!=NULL);
		c=c/2;int d=0;
		do
		{
			tp3=tp3->next;
			d++;
		}
		while(d!=c-1);
		printf("\n%d is middle element\n",tp3->d);
}

main()
{
	insertb(10);
	insertb(20);
	insertb(30);
	insertb(40);
	insertafter(35,30);
	display();
	getmid();
	deleteb();
	display();
	deleteend();
	display();
	delmid(35);
	display();
}
