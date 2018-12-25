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

 int main()
 {
 	int v,p,i=1;
 	while(i==1)
 	{
 	printf("Enter Value and Position");
 	scanf("%d%d",&v,&p);
 	put(v,p);
 	printf("List -- ");
 	Print();
 	printf("More Values? Enter 1 to enter more or any other to exit");
 	scanf("%d",&i);
 	}
 	struct node* temp=head;
 	while((*temp).next!=NULL)
 	{
 		if(((*temp).val)%2==0)
 		{
 		printf("EVEN ");
 		}
 		else
 		printf("ODD ");
 		temp=(*temp).next;
 	}
 	if(((*temp).val)%2==0)
 		{
 		printf("EVEN ");
 		}
 		else
 		printf("ODD ");
 }

