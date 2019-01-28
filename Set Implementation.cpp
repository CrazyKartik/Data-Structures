#include<iostream>
#include<cstdlib>
#define MAX 10000
using namespace std;

struct node
{
	int x;
	struct node* next;
};
struct node* add(struct node* hd,int x);

struct node* create()
{
	struct node* head=NULL;
	return head;
}

struct node* build(struct node* hd,int X[],int n)
{
	int i=0;
	while(i<n)
	{
		hd=add(hd,X[i]);
		i++;
	}
	return hd;
}

int is_element_of(int v,struct node* hd)
{
	while(hd!=NULL)
	{
		if(hd->x==v)
		{
			return 1;
		}
		hd=hd->next;
	}
	return 0;
}

int is_empty(struct node* hd)
{
	if(hd==NULL)
		return 1;
	return 0;
}

int size(struct node* hd)
{
	int sz=0;
	while(hd!=NULL)
	{
		hd=hd->next;
		sz++;
	}
	return sz;
}

void enumerate(struct node* hd)
{
	int is_empty(struct node* hd);
	if(is_empty(hd))
	{
		cout<<"Empty\n";
		return;
	}
	while(hd!=NULL)
	{
		cout<<hd->x<<" ";
		hd=hd->next;
	}
	cout<<endl;
}

struct node* add(struct node* hd,int x)
{
	int c=0;
	struct node* tmp=hd;
	struct node* data=(struct node*)malloc(sizeof(struct node));
	while(tmp!=NULL)
	{
		if(tmp->x==x)
		c=1;
		tmp=tmp->next;
	}
	tmp=hd;
	if(c==1)
	cout<<"Already Present\n";
	else if(tmp==NULL)
	{
		data->x=x;
		data->next=NULL;
		tmp=data;
		hd=tmp;
	}
	else
	{
		while(tmp->next!=NULL)
			tmp=tmp->next;
		data->x=x;
		data->next=NULL;
		tmp->next=data;
	}
	return hd;
}

struct node* remove(struct node* hd,int x)
{
	int c=0;
	struct node* tmp=hd;
	struct node* cur=hd;
	if(tmp!=NULL && tmp->x==x)
	hd=tmp->next;
	else
	{
		while(tmp!=NULL && tmp->next!=NULL)
		{
			if(tmp->next->x==x)
			{
				tmp->next=tmp->next->next;
				c=1;
				break;
			}
			tmp=tmp->next;
		}
		
		if(!c)
		cout<<"Not Present\n";
	}
	return hd;
}

struct node* Union(struct node* hd1,struct node* hd2,int size_hd1,int size_hd2)
{
	int X[size_hd1+size_hd2];
	int n=0,c=0,n1;
	struct node* tmp1=hd1,*tmp2=hd2;
	struct node* unn=create();
	while(tmp1!=NULL)
	{
		X[n++]=tmp1->x;
		tmp1=tmp1->next;
	}
	n1=n;
	while(tmp2!=NULL)
	{
		c=0;
		for(int i=0; i<n1; i++)
		{
			if(X[i]==tmp2->x)
			{
			c=1;
			break;
			}
		}
		if(c==0)
		X[n++]=tmp2->x;
		tmp2=tmp2->next;
	}
	unn=build(unn,X,n);
	return unn;
}

struct node* Intersection(struct node* hd1,struct node* hd2)
{
	int X[size(hd1)];
	int Y[size(hd1)];
	int nx=0,ny=0,c=0;
	struct node* tmp1=hd1,*tmp2=hd2;
	struct node* intsec=NULL;
	while(tmp1!=NULL)
	{
		Y[ny++]=tmp1->x;
		tmp1=tmp1->next;
	}
	while(tmp2!=NULL)
	{
		c=0;
		for(int i=0; i<ny; i++)
		{
			if(Y[i]==tmp2->x)
			c=1;
		}
		if(c==1)
		X[nx++]=tmp2->x;
		tmp2=tmp2->next;
	}
	intsec=build(intsec,X,nx);
	return intsec;
}

struct node* difference(struct node* hd1,struct node* hd2)
{
	int X[size(hd1)];
	int Y[size(hd1)];
	int nx=0,ny=0,c=0;
	struct node* tmp1=hd1,*tmp2=hd2;
	struct node* diff=NULL;
	while(tmp2!=NULL)
	{
		Y[ny++]=tmp2->x;
		tmp2=tmp2->next;
	}
	while(tmp1!=NULL)
	{
		c=0;
		for(int i=0; i<ny; i++)
		{
			if(Y[i]==tmp1->x)
			c=1;
		}
		if(c==0)
		X[nx++]=tmp1->x;
		tmp1=tmp1->next;
	}
	diff=build(diff,X,nx);
	return diff;
}

int subset(struct node* hd1,struct node* hd2)
{
	int c=0;
	struct node* tmp=hd2;
	while(hd1!=NULL)
	{
		c=0;
		hd2=tmp;
		while(hd2!=NULL)
		{
			if(hd1->x==hd2->x)
			c=1;
			hd2=hd2->next;
		}
		if(!c)
		return c;
		hd1=hd1->next;
	}
	return c;
}

int main()
{
	int is_empty(struct node* hd);
	struct node* head[MAX];
	int n,v,c;
	head[0]=create();
	
	cout<<"Enter the number of elements to insert first set : ";
	cin>>n;
	int X[n];
	cout<<"Enter the elements to insert in first set : ";
	for(int i=0; i<n; i++)
	cin>>X[i];
	head[0]=build(head[0],X,n);
	int shd0=size(head[0]);
	cout<<"First set : ";
	enumerate(head[0]);
	
	cout<<"Enter the number of elements to insert in second set : ";
	cin>>n;
	cout<<"Enter the elements to insert in second set : ";
	for(int i=0; i<n; i++)
	cin>>X[i];
	head[1]=build(head[1],X,n);
	int shd1=size(head[1]);
	cout<<"Second set : ";
	enumerate(head[1]);

	head[2]=Union(head[0],head[1],shd0,shd1);
	cout<<"Union of set1 and set2 : ";
	enumerate(head[2]);
	
	head[3]=Intersection(head[0],head[1]);
	cout<<"Intersection of set1 and set2 : ";
	enumerate(head[3]);
	
	head[4]=difference(head[0],head[1]);
	cout<<"Difference of set1 and set2 : ";
	enumerate(head[4]);
	
	if(subset(head[0],head[1]))
	cout<<"First is a subset of second\n";
	else
	cout<<"First is not the subset of second\n";
	
	c=1;
	while(c)
	{
		cout<<"Enter the element to remove from first set : ";
		cin>>v;
		head[0]=remove(head[0],v);
		enumerate(head[0]);
		cout<<"Enter 0 to exit : ";
		cin>>c;
	}
}
