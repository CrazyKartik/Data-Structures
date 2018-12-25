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
	struct node* temp1=head;
	while((*temp1).next!=NULL)
	{
	printf("%d ",(*temp1).val);
	temp1=(*temp1).next;
	}
	printf("%d\n",(*temp1).val);
}

void Delete()
{
	struct node* temp=head;
	struct node* temp1;
	int j,i;
	while(temp!=NULL)
	{
		i=temp->val;
		temp1=temp;
		while(temp1->next!=NULL)
		{
			j=temp1->next->val;
			if(j==i)
			{
				temp1->next = temp1->next->next;
			}
			else
			temp1=temp1->next;
		}
		temp=temp->next;
	}
	Print();
}
 int main()
 {
 	int v,p,i=1;
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
 	Delete();
 }

