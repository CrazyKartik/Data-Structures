#include<stdio.h>
#include<stdlib.h>

struct node
{
int val;
struct node* next;
};

struct node* head=NULL;

void put(int v,int p)
{
	struct node* temp=(struct node*)malloc(sizeof(struct node));
	struct node* cur=head	;
	for(int i=0; i<p-1 && (*cur).next!=NULL; i++)
	{
	cur=(*cur).next;
	}
	if(p==1)
	{
	(*temp).next=head;
	(*temp).val=v;
	head=temp;
	}
	else
	{
	(*temp).next=(*cur).next;
	(*temp).val=v;
	(*cur).next=temp;
	}
}
void Print()
{
	struct node* temp=head;
	while((*temp).next!=NULL)
	{
	printf("%d ",(*temp).val);
	temp=(*temp).next;
	}
	printf("%d\n",(*temp).val);
}

void Delete(int del)
{
	struct node* temp=head;
	int i=1;
	if(del==1)
	{
		head=temp->next;
		Print();
	}
	else
	{
	while(i<del-1 && temp!=NULL)
	{
		temp=(*temp).next;
		i++;
	}
	temp->next = temp->next->next;
	Print();
	}
}
 int main()
 {
 	int v,p,i=1,del;
 	while(i==1)
 	{
 	printf("Enter Value and Position ");
 	scanf("%d%d",&v,&p);
 	put(v,p);
 	printf("List -- ");
 	Print();
 	printf("More Values? Enter 1 to enter more or any other to exit");
 	scanf("%d",&i);
 	}
 	printf("Enter Node to be Deleted ");
 	scanf("%d",&del);
 	Delete(del);
 }

