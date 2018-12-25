#include<stdio.h>
#include<stdlib.h>
int last=1;
struct node
{
	struct node* prev;
	int data;
	struct node* next;
};
struct node* head=NULL;
void Insert(int v,int p)
{
	struct node* cur=head;
	struct node* temp=(struct node*)malloc(sizeof(struct node));
	int i;
	for(i=0; i<p-2 && cur->next!=NULL; i++)
	{
		cur=cur->next;
	}
	if(head==NULL)
	{
		temp->next=head;
		temp->prev=head;
		temp->data=v;
		head=temp;
	}
	else if(p==last)
	{
		temp->prev=cur;
		temp->next=cur->next;
		temp->data=v;
		cur->next=temp;
	}
	else if(p==1)
	{
		temp->next=cur;
		cur->prev=temp;
		temp->prev=NULL;
		temp->data=v;
		head=temp;
	}
	else
	{
		temp->prev=cur->next->prev;
		cur->next->prev=temp;
		temp->next=cur->next;
		temp->data=v;
		cur->next=temp;
	}
	last++;
}

void Print()
{
	struct node* temp=head;
	while(temp!=NULL)
	{
		printf("%d ",temp->data);
		temp=temp->next;
	}
	printf("\n");
}
void PRev()
{
	struct node* temp=head;
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	while(temp!=NULL)
	{
		printf("%d ",temp->data);
		temp=temp->prev;
	}	
}

int main()
{
	int v,p,i=1;
	while(i==1)
	{
		printf("Enter value and position");
		scanf("%d%d",&v,&p);
		Insert(v,p);
		printf("List is : ");
		Print();
		printf("Do you need more values enter 1 to add more");
		scanf("%d",&i);
	}
	printf("List in reverse is : ");
	PRev(); 
}
