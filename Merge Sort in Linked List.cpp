/*
This requires us to make a new linked list every time for each left and right part of the linked list and modify the last 
head of the main linked list and modify the list itself so as to store the sorted values.
We have to keep in mind specially when the temp(traversing variable here) is becoming NULL as at NULL its data will be garbage and it will 
throw us to some core dump error.
*/


#include<iostream>
#include<cstdlib>
using namespace std;
int counter=0;

struct node
{
	int data;
	struct node* next;
};
struct node* head=NULL,*temp_head=NULL;

struct node* Insert(struct node* hd,int v)
{
	struct node* newnode=hd;
	struct node* temp=(struct node*)malloc(sizeof(struct node));
	
	for(int i=1; i<counter && newnode->next!=NULL; i++)
	{
		newnode=newnode->next;
	}
	
	if((counter+1)!=1)
	{
		temp->next=newnode->next;
		temp->data=v;
		newnode->next=temp;
	}
	else
	{
		temp->next=hd;
		temp->data=v;
		hd=temp;
	}
	counter++;
	return hd;
}

void Print()
{
	struct node* temp=head;
	cout<<"List is : ";
	while(temp!=NULL)
	{
		cout<<temp->data<<" ";
		temp=temp->next;
	}
	cout<<endl;
}

struct node* MergeSort(struct node* hd,int strt_left,int end_left,int strt_right,int end_right)
{
	counter=0;
	struct node* temp=hd,*t1,*t2;
	int j=strt_left,st_lf=strt_left,k=strt_right;
    temp_head=NULL;
    
	for(int x=1; x<j && temp->next!=NULL; x++)
	temp=temp->next;
	j=temp->data;
	t1=temp;
	temp=hd;
	
	for(int x=1; x<k && temp->next!=NULL; x++)
	temp=temp->next;
	k=temp->data;
	t2=temp;
	
	while(strt_left<=end_left && strt_right<=end_right && t2!=NULL && t1!=NULL)
	{
		if(j<=k)
		{
			strt_left++;
			temp_head=Insert(temp_head,j);
			t1=t1->next;
			if(t1==NULL)
			break;
			j=t1->data;
		}
		else
		{
			strt_right++;
			temp_head=Insert(temp_head,k);
			t2=t2->next;
			if(t2==NULL)
			break;
			k=t2->data;
		}
	}
	
	if(strt_left<=end_left)
	{
		while(strt_left<=end_left)
		{
		    strt_left++;
			j=t1->data;
		    temp_head=Insert(temp_head,j);
		    t1=t1->next;
	    }
	}
	if(strt_right<=end_right)
	{
		while(strt_right<=end_right)
		{
			strt_right++;
			k=t2->data;
			temp_head=Insert(temp_head,k);
			t2=t2->next;
		}
	}
	
	temp=temp_head;
	struct node* temp1=hd;
	for(j=1; j<st_lf; j++)
	temp1=temp1->next;
	while(temp!=NULL)
	{
		temp1->data=temp->data;
		temp1=temp1->next;
		temp=temp->next;
	}
	return hd;
}

struct node* split(struct node* hd,int strt,int end)
{
	if(strt>=end)
	return hd;
	
	hd=split(hd,strt,(strt+end)/2);
	hd=split(hd,(strt+end)/2+1,end);
	hd=MergeSort(hd,strt,(strt+end)/2,(strt+end)/2+1,end);
	return hd;
}

int main()
{
	int v,c;
	cout<<"Enter values in the linked list : ";
	do
	{
		cout<<"Enter Value : ";
		cin>>v;
		head=Insert(head,v);
		Print();
		cout<<"Enter 1 to enter more values or 0 to exit : ";
		cin>>c;
	}
    while(c);
    head=split(head,1,counter);
    Print();
}
