#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node* next;
};
struct node* head=NULL;

void Insert(int v,int p)
{
	struct node* cur=head;
	struct node* temp=(struct node*)malloc(sizeof(struct node));
	for(int i=1; i<p-1 && cur->next!=NULL; i++ )
	{
		cur=cur->next;
	}
	if(p!=1)
	{
		temp->next=cur->next;
		temp->data=v;
		cur->next=temp;
	}
	else
	{
		temp->next=head;
		temp->data=v;
		head=temp;
	}
}

void Print(int l)
{
	int A[l],i=0;
	struct node* temp=head;
	while(temp!=NULL)
	{
		A[i]=temp->data;
		temp=temp->next;
		i++;
	}
	i=l-1;
	while(i>=0)
	{
		printf("%d ",A[i]);
		i--;
	}
	printf("\n");
}

int main()
{
	int v,p,c,l=1;
	do
	{
		printf("Enter Value : ");
		scanf("%d",&v);
		printf("Enter Position");
		scanf("%d",&p);
		Insert(v,p);
		printf("List in Reverse is : ");
		Print(l);
		printf("Enter 1 to Insert More Values");
		scanf("%d",&c);
		l++;
	}
	while(c==1);
	printf("List Ended");
}
