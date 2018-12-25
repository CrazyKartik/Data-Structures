#include<stdio.h>
#include<stdlib.h>
int l=0;

struct node
{
	int data;
	struct node* next;
};
struct node* head=NULL;
struct node* cur;

void Print();
void push(int v,int n)
{
	cur=head;
	struct node* temp=(struct node*)malloc(sizeof(struct node));
	if(l<n)
	{
	if(head==NULL)
	{
		temp->next=head;
		temp->data=v;
		head=temp;
	}
	else
	{
		while(cur->next!=NULL)
		{	
		cur=cur->next;
		}
		temp->next=cur->next;
		temp->data=v;
		cur->next=temp;
	}
	l++;
	Print();
	}
	else
	printf("\nStack Overflow!!\n");
}

void pop()
{
	if(l>0)
	{
	int i=1;
	struct node* temp=head;
	while(i<l)
	{
		temp=temp->next;
		i++;
	}
	printf("%d\n",temp->data);
	i=1;
	temp=head;
	while(i<l-1)
	{
		temp=temp->next;
		i++;
	}
	temp->next=NULL;
	l--;
	}
	else
	printf("\nStack Underflow!!\n");
}

void Print()
{
	struct node* temp=head;
	printf("Stack is : ");
	if(l>0)
	{
	while(temp!=NULL)
	{
		printf("%d ",temp->data);
		temp=temp->next;
	}
	}
	else
	printf("\nEmpty Stack..");
	printf("\n");
}

int main()
{
	int v,n,c=1;
	printf("Enter Size of Stack : ");
	scanf("%d",&n);
	while(c==1)
	{
		printf("Enter Value : ");
		scanf("%d",&v);
		push(v,n);
		printf("Enter 1 to add more values : ");
		scanf("%d",&c);
	}
	
	printf("Enter 1 to pop elements : ");
	scanf("%d",&c);
	while(c==1)
	{
		pop();
		printf("Enter 1 to pop more : ");
		scanf("%d",&c);
	}
	printf("Remaining ");
	Print();
	printf("Stack Ended....");
}
