#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node* add;
};
struct node* head=NULL;
struct node* head1=NULL;

void Insert(int v,int p,struct node** HEAD)
{
	struct node* newnode=*HEAD;
	struct node* temp=(struct node*)malloc(sizeof(struct node));
	int i;
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
		*HEAD=temp;
	}
}

void Print(struct node** HEAD,struct node** HEAD1)
{
	printf("List is : ");
	struct node* temp=*HEAD;
	while(temp!=*HEAD1)
	{
		printf("%d ",(*temp).data);
		temp=(*temp).add;
	}
		printf("\n");
}

void Merge()
{
	int a,b;
	struct node *temp1=head1,*t;
	while(temp1->add!=NULL)
	{
		t=temp1;
		a=temp1->data;
		temp1=temp1->add;
		while(temp1!=NULL)
		{
		if(a>temp1->data)
		{
			b=a;
			a=temp1->data;
			temp1->data=b;
			temp1=t->add;
		}
		else
		temp1=temp1->add;
		}
	temp1=t;
	temp1->data=a;
	temp1=temp1->add;
	}
	head=NULL;
	Print(&head1,&head);
}
int main()
{
	int v,p,c;
	do
	{
		printf("Enter values for the first list\n");
		printf("Enter Value : ");
		scanf("%d",&v);
		printf("Enter Position");
		scanf("%d",&p);
		Insert(v,p,&head);
		Print(&head,&head1);
		printf("Enter 1 to Insert More Values");
		scanf("%d",&c);
	}
	while(c==1);
	printf("List 1 Ended\n");
	do
	{
		printf("Enter values for the second list\n");
		printf("Enter Value : ");
		scanf("%d",&v);
		printf("Enter Position");
		scanf("%d",&p);
		Insert(v,p,&head1);
		Print(&head1,&head);
		printf("Enter 1 to Insert More Values");
		scanf("%d",&c);
	}
	while(c==1);
	printf("List 2 Ended\n");
	Merge();
}
