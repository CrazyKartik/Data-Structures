/*
This requires us to modify the head each time we sort the list to have the new arranged list or modified list to sort it again and again.
We have to keep in mind specially when the temp(traversing variable here) is becoming NULL as at NULL its data will be garbage and it will 
throw us to some core dump error.
Some places where we keep decrementing or incrementing left or right counters we miss the point that after it is at last or at beginning 
it will be stuck there(loop<counter) so its value does not change and we get into infinite loop. 
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
struct node* head=NULL;

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

struct node* quicksort(struct node* hd,int strt,int end)
{
	int f=strt,l=end,piv,tmp,piv_loc=end;
	struct node* temp=hd,*t1=hd,*t2=hd;
	
	for(int i=1; i<f; i++)
	t1=t1->next;
	for(int i=1; i<l; i++)
	t2=t2->next;
	
	if(f<l)
	{
		for(int i=1; i<l; i++)
		temp=temp->next;
		piv=temp->data;
		
		while(f<l)
		{
			while(t1->data<piv && f<=end)
			{
				f++;
				t1=hd;
				for(int i=1; i<f; i++)
	            t1=t1->next;
			}
			while(l>=strt && t2->data>=piv)
			{
				l--;
				t2=hd;
				for(int i=1; i<l; i++)
	            t2=t2->next;
			}
			if(f<l)
			{
				tmp=t1->data;
				t1->data=t2->data;
				t2->data=tmp;
			}
		}
		
		struct node* t3=hd;
		for(int i=1; i<piv_loc; i++)
		t3=t3->next;
		t3->data=t1->data;
		t1->data=piv;
		head=quicksort(hd,strt,f-1);
		head=quicksort(hd,f+1,end);
	}
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
    head=quicksort(head,1,counter);
    Print();
}
