#include<stdio.h>
#define max 10
int q[max],front=-1,rear=-1;

void enq(int v,int i)
{
	if(i<max)
	{
	rear++,front=0;
	q[rear]=v;		
	}
	else
	{
	printf("No Space...\n");
	}
}

void deq()
{
	if(front!=-1 && rear!=-1 && front<=rear)
	{
		printf("%d ",q[front]);
		front++;
		printf("\n");
		printf("Remaining Queue is : ");
	}
	else
	{
		printf("Emptied...\n");
	}
}

void Print()
{
	int i=front;
	while(i<=rear)
	{
		printf("%d ",q[i]);
		i++;
	}
	printf("\n");
}

void Reverse()
{
	int t,i=front,j=rear;
	while(i<=j)
	{
		t=q[i];
		q[i]=q[j];
		q[j]=t;
		i++;
		j--;
	}
}

int main()
{
	int size,i,v,c;
	printf("Enter size of Queue : ");
	scanf("%d",&size);
	for(i=0; i<size; i++)
	{
		printf("Enter %d Value : ",i+1);
		scanf("%d",&v);
		enq(v,i);
		Print();
	}
	printf("Enter 1 to deque elements : ");
	scanf("%d",&c);
	while(c==1)
	{
		deq();
		Print();
		printf("Enter 1 to deque elements : ");
		scanf("%d",&c);
	}
	Reverse();
	Print();
	printf("Ended....");
}
