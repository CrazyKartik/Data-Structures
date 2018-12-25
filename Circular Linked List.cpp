#include<stdio.h>
#include<stdlib.h>
int last=1;
struct node
{
	int data;
	struct node* next;
};
struct node* head=NULL;
void Insert(int v,int p)
{
	struct node* counter=head;
	struct node* temp=(struct node*)malloc(sizeof(struct node));
	int i;
	for(i=1; i<p-1 && counter->next!=head; i++)
	{
		counter=counter->next;
	}
	if(head==NULL)
	{
		head=temp;
		temp->next=head;
		temp->data=v;
	}
	else if(p==last)
	{
		temp->next=head;
		temp->data=v;
		counter->next=temp;
	}
	else if(p<last && p!=1)
	{
		temp->data=v;
		temp->next=counter->next;
		counter->next=temp;
	}
	else if(p==1)
	{
		head=temp;
		temp->next=counter;
		temp->data=v;
		temp=counter;
		while(temp->next!=counter)
		{
			temp=temp->next;
		}
		temp->next=head;
	}
	last++;
}
void Print()
{
	struct node* temp=head;
	printf("List is...\n");
	while(temp->next!=head)
	{
		printf("%d ",temp->data);
		temp=temp->next;
	}
	printf("%d\n",temp->data);
}

void Delete(int n)
{
	struct node *temp=head,*counter=head;
	int i;
	if(n<last)
	{
	for(i=1; i<n-1; i++)
	{
		temp=temp->next;
	}
	if(n==1)
	{
		head=temp->next;
		while(temp->next!=counter)
		{
			temp=temp->next;
		}
		temp->next=head;
	}
	else
	{
		temp->next=temp->next->next;
	}
	if(last>2)
	{
	Print();
	}
	else
	printf("Empty List....\n");
	}
	else
	printf("No node....");
}
int main()
{
	int v,p,c=1,n;
	while(c==1)
	{
		printf("Enter Value and Position : ");
		scanf("%d%d",&v,&p);
		Insert(v,p);
		Print();
		printf("Enter 1 to Insert More Values : ");
		scanf("%d",&c);
	}
	printf("List Ended....");
	printf("Enter Node to be Deleted : ");
	scanf("%d",&n);
	Delete(n);
}
