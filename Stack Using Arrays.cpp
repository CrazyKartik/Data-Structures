#include<stdio.h>
#include<stdlib.h>
int n,p=0;
int A[100];
void Print();
void push(int v)
{
	if(p<n && p<100)
	{
		A[p]=v;
		p++;
		Print();
	}
	else
	printf("Stack Overflow....");
}

void Pop()
{
	if(p<=n && p>0)
	{
		printf("%d\n",A[p-1]);
		p--;
	}
	else
	printf("Stack Underflow....\n");
}

void Print()
{
	printf("Stack is....");
	for(int i=0; i<p; i++)
	{
		printf("%d ",A[i]);
	}
	printf("\n");
}

int main()
{
	int v,i,c;
	printf("Enter Size of Stack : ");
	scanf("%d",&n);
	for(i=0; i<n; i++)
	{
	printf("Enter the %d element : ",i+1);
	scanf("%d",&v);
	push(v);
	}
	printf("Enter 1 to pop elements : ");
	scanf("%d",&c);
	while(c==1)
	{
	 Pop();
	 printf("Enter 1 to pop elements : ");
	 scanf("%d",&c);
	}
	printf("Remaining ");
	Print();
	printf("Stack Ended : ");
}
