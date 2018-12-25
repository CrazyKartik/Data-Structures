#include<stdio.h>
#include<stdlib.h>
int counter=0;
struct node
{
	int data;
	struct node* add;
};
void Print();
struct node* head=NULL;

void Insert(int v,int p)
{
	struct node* newnode=head;
	struct node* temp=(struct node*)malloc(sizeof(struct node));
	int i;
	if(p<=counter+1)
	{
	for(i=1; i<p-1 && (*newnode).add!=NULL; i++)
	{
		newnode=(*newnode).add;
	}
	if(p!=1)
	{
		(*temp).add=(*newnode).add;
		(*temp).data=v;
		(*newnode).add=temp;
	}
	else
	{
		(*temp).add=head;
		(*temp).data=v;
		head=temp;
	}
	counter++;
	Print();
	}
	else
	{
		printf("Exceeded Location Count\n");
	}
}

void Print()
{
	struct node* temp=head;
	printf("List is : ");
	int i=0;
	while((*temp).add!=NULL)
	{
		i++;
		printf("%d ",(*temp).data);
		temp=(*temp).add;
	}
	i++;
	printf("%d ",(*temp).data);
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
		printf("Enter Position");
		scanf("%d",&p);
		Insert(v,p);
		printf("Enter 1 to Insert More Values");
		scanf("%d",&c);
	}
	while(c==1);
	printf("List Ended");
}
