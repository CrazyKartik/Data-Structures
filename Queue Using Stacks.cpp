#include<stdio.h>
#define max 10
int f1=-1,r1=-1,f2=-1,r2=-1,s1[max],s2[max];

void push1(int v,int c,int size)
{
	if(c<size)
	{
		s1[r1]=v;
		f1--;
		r1--;
	}	
	else
	printf("Stack Overflow!!\n");
}
int pop1()
{
	int o=s1[f1+1];
	f1++;
	return o;
}

void push2(int v)
{
	s2[r2]=v;
	r2--;
	f2--;
}
void pop2()
{
	printf("%d\n",s2[f2+1]);
	f2++;
}

void Print(int i,int size)
{
	int c;
	if(i==1)
	{
		printf("Stack is : ");
		c=f1+1;
		while(c<size)
		{
			printf("%d ",s1[c]);
			c++;
		}
	}
	else
	{
		printf("Queue is : ");
		c=f2+1;
		while(c<size)
		{
			printf("%d ",s2[c]);
			c++;
		}
	}
	printf("\n");
}

int main()
{
	int size,i,v,c=0;
	printf("Enter size of the stack : ");
	scanf("%d",&size);
	r1=size-1,f1=size-1,r2=size-1,f2=size-1;
	for(i=size; i>0; i--)
	{
		printf("Enter %d Value : ",c+1);
		scanf("%d",&v);
		push1(v,c,size);
		Print(1,size);
		c++;
	}
	i=0;
	while(i<size)
	{
		int x=pop1();
		push2(x);
		i++;	
	}
	Print(2,size);
	printf("Enter 1 to deque the queue elements : ");
	scanf("%d",&c);
	while(c==1)
	{
		pop2();
		Print(2,size);
		printf("Enter 1 to deque the queue elements : ");
		scanf("%d",&c);		
	}
	printf("Remaining ");
	Print(2,size);
	printf("Ended....");
}

