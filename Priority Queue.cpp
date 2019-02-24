#include<iostream>
#include<cstdlib>
using namespace std;

struct node
{
	int data;
	int priority;
	struct node* next;	
};
struct node* head=NULL;

void Insert(int v,int p)
{
	struct node* temp=(struct node*)malloc(sizeof(struct node));
	struct node* cur=head,*cur2;
	if(cur==NULL || p<cur->priority)
	{
		temp->data=v;
		temp->priority=p;
		temp->next=cur;
		head=temp;
	}
	else
	{
		while(cur!=NULL && p>=cur->priority)
		{
			cur2=cur;
			cur=cur->next;
		}
		temp->data=v;
		temp->priority=p;
		temp->next=cur;
		cur2->next=temp;
	}
}

void Delete(int v,int p)
{
	struct node* cur=head;
	if(head->data==v && head->priority==p)
	head=head->next;
	else
	{
		while(cur->next!=NULL && cur->next->data!=v && cur->next->priority!=p)
		{
			cur=cur->next;
		}
		if(cur->next!=NULL && cur->next->data==v && cur->next->priority==p)
		{
			cur->next=cur->next->next;
		}
		else
		{
			cout<<"No such node....\n";
		}
	}
}

void pop()
{
	if(head==NULL)
	cout<<"Empty Queue.....\n";
	else
	{
		cout<<head->data<<endl;
		head=head->next;	
	}
}

void Print()
{
	struct node* cur=head;
	while(cur!=NULL)
	{
		cout<<cur->data<<" ";
		cur=cur->next;
	}
	cout<<endl;
}

int main()
{
	int p,v,c=1;
	while(c)
	{
		cout<<"Enter Value : ";
		cin>>v;
		cout<<"Enter Priority : ";
		cin>>p;
		Insert(v,p);
		Print();
		cout<<"Enetr 0 to exit or 1 to add more : ";
		cin>>c;
	}
	c=1;
	while(c)
	{
		cout<<"Enter Value : ";
		cin>>v;
		cout<<"Enter Priority : ";
		cin>>p;
		Delete(v,p);
		Print();
		cout<<"Enetr 0 to exit or 1 to delete more : ";
		cin>>c;
	}
	c=1;
	while(c)
	{
		pop();
		Print();
		cout<<"Enetr 0 to exit or 1 to pop more : ";
		cin>>c;
	}
}
