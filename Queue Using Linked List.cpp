#include<stdio.h>
#include<stdlib.h>
#define max 10
int front=-1,rear=-1;

struct node
{
int data;
struct node* next;	
};
struct node* head=NULL;

void enq(int v,int i)
{
	front=0;
	struct node* cur=head;
	struct node* temp=(struct node*)malloc(sizeof(struct node));
	for(int j=0; j<rear; j++)
	{
		cur=cur->next;
	}
	if(i<max && head==NULL)
	{
		temp->next=head;
		head=temp;
		temp->data=v;
		rear++;
	}
	else if(head!=NULL && i<max)
	{
		temp->next=cur->next;
		temp->data=v;
		cur->next=temp;
		rear++;
	}
	else
	{
		printf("Limit Exceeded!!!!\n");
	}	
}
 
void deq()
{
	struct node* temp=head;
	if(rear==-1)
	{
		printf("Queue Empty!!\n");
	}
	else
	{
		printf("Dequed Element is : ");
		printf("%d\n",temp->data);
		rear--;
		head=temp->next;
	}
}

void Print()
{	
	struct node* temp=head;
	if(temp==NULL)
	{
		return;
	}
	while(temp!=NULL)
	{
		printf("%d ",temp->data);
		temp=temp->next;
	}
	printf("\n");
}

int main()
{
	int size,i,v,c=1;
	printf("Enter Size of the Queue : ");
	scanf("%d",&size);
	for(i=0; i<size; i++)
	{
		printf("Enter %d Value : ",i+1);
		scanf("%d",&v);
		enq(v,i);
		Print();
	}
	printf("Enter 1 to deq the Queue : ");
	scanf("%d",&c);
	while(c==1)
	{
		deq();
		Print();
		printf("Enter 1 to deq the Queue : ");
		scanf("%d",&c);
		if(rear==-1)
		{
			printf("Queue Empty!!\n");
			break;
		}
	}
	printf("Ended......");
}
