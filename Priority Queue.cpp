/*Priority Queue if only 3 priorities are considered namely 1,2,3(low to high order)*/
#include<stdio.h>
#include<stdlib.h>
int p3=0,p2=0,p1=0;
struct node
{
	int pri;
	int data;
	struct node* add;
};
void Print();
struct node* head=NULL;

void Insert(int v,int p)
{
	struct node* newnode=head;
	struct node* temp=(struct node*)malloc(sizeof(struct node));
	int i,pos;
	if(p==3)
	{
	p3++;
	pos=p3;
	}
	else if(p==2)
	{
	p2++;
	pos=p2+p3;
	}
	else
	{
	p1++;
	pos=p3+p2+p1;
	}
	for(i=1; i<pos-1 && (*newnode).add!=NULL; i++)
	{
		newnode=(*newnode).add;
	}
	if(pos!=1)
	{
		(*temp).add=(*newnode).add;
		(*temp).data=v;
		(*temp).pri=p;
		(*newnode).add=temp;
	}
	else
	{
		(*temp).add=head;
		(*temp).data=v;
		(*temp).pri=p;
		head=temp;
	}
	Print();
}

void Print()
{
	struct node* temp=head;
	int i=0;
	while((*temp).add!=NULL)
	{
		i++;
		printf("Value : %d\tPriority : %d\n",(*temp).data,(*temp).pri);
		temp=(*temp).add;
	}
	i++;
	printf("Value : %d\tPriority : %d\n",(*temp).data,(*temp).pri);
	printf("\n");
	printf("No of nodes %d\n",i);
	
}

int main()
{
	int v,p,c;
	do
	{
		printf("Enter Value : ");
		scanf("%d",&v);
		printf("Enter Priority : ");
		scanf("%d",&p);
		Insert(v,p);
		printf("Enter 1 to Insert More Values");
		scanf("%d",&c);
	}
	while(c==1);
	printf("List Ended");
}
