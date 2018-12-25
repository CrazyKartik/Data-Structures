#include<stdio.h>
#include<stdlib.h>
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
	for(i=0; i<p-1 && (*newnode).add!=NULL; i++)
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
	Print();
}
void Update(int p,int v)
{
	struct node* temp=head;
	int i;
	for(i=0; i<p-1 && (*temp).add!=NULL; i++)
	{
		temp=(*temp).add;
	}
	if(p!=1)
	{
		(*temp).data=v;
	}
	else
	{
		(*temp).data=v;
	}
	Print();
}
void Print()
{
	struct node* temp=head;
	printf("List is : ");
	while((*temp).add!=NULL)
	{
		printf("%d ",(*temp).data);
		temp=(*temp).add;
	}
	printf("%d ",(*temp).data);
	printf("\n");
	
}

int main()
{
	int v,p,c,u;
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
	printf("Enter node to be updated and value : ");
	scanf("%d%d",&u,&v);
	Update(u,v);
	printf("List Ended");
}
