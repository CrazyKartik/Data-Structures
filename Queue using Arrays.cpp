#include<stdio.h>
#define max 20
int que[max],front=-1,rear=-1;

void enq(int v,int i)
{
	if(i<max)
	{
		front++;
		que[front]=v;
		rear=0;
	}
	else
	{
		printf("Exceeded Max Length!!!!\n");
	}
}

void deq()
{
	if(rear!=-1 && rear<=front)
	{
		printf("Element is : ");
		printf("%d",que[rear]);
		rear++;
	}
	else
	{
		printf("Queue Empty!!\n");
	}
	printf("\n");
}

void Print()
{
	if(rear<=front)
	{
	int i=rear;
	printf("Queue is : ");
	while(i<=front)
	{
		printf("%d ",que[i]);
		i++;
	}
	}
	else
	{
		printf("Queue is Empty.....");
	}
	printf("\n");
}
int main()
{
	int i,v,size,c;
	printf("Enter Size of Queue : ");
	scanf("%d",&size);
	for(i=0; i<size; i++)
	{
		printf("Enter %d Value : ",i+1);
		scanf("%d",&v);	
		enq(v,i);
		Print();
	}	
	printf("Enter 1 to dequeue entered queue Elements : ");
	scanf("%d",&c);
	while(c==1)
	{
		deq();
		Print();
		scanf("%d",&c);
	}
}
