#include<iostream>
#include<cstdlib>
using namespace std;

struct node
{
	int x;
	struct node* next;
};
struct node* add(struct node* hd,int x);

void create(struct node* hd[])
{
	for(int i=0; i<10; i++)
	{
		hd[i]=NULL;
	}
}

void build(struct node* hd[],int X[],int n)
{
	int i=0;
	while(i<n)
	{
		hd[X[i]%10]=add(hd[X[i]%10],X[i]);
		i++;
	}
}

int is_element_of(int v,struct node* hd[])
{
	for(int i=0; i<10; i++)
	{
		while(hd[i]!=NULL)
		{
			if(hd[i]->x==v)
			return 1;
			hd[i]=hd[i]->next;
		}
	}
	return 0;
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

int is_empty(struct node* hd[])
{
	for(int i=0; i<10; i++)
	{
		if(hd[i]!=NULL)
		return 1;
	}
	return 0;
}

int size(struct node* hd[])
{
	int sz=0;
	struct node* tmp[10];
	for(int i=0; i<10; i++)
	tmp[i]=hd[i];
	for(int i=0; i<10; i++)
	{
		while(tmp[i]!=NULL)
		{
			tmp[i]=tmp[i]->next;
			sz++;
		}
	}
	return sz;
}

void enumerate(struct node* hd[])
{
	struct node* tmp[10];
	for(int i=0; i<10; i++)
	tmp[i]=hd[i];
	int is_empty(struct node* hd[]);
	if(!is_empty(hd))
	{
		cout<<"Empty\n";
		return;
	}
	for(int i=0; i<10; i++)
	{
		while(tmp[i]!=NULL)
		{
			cout<<tmp[i]->x<<" ";
			tmp[i]=tmp[i]->next;
		}
	}
	cout<<endl;
}

struct node* remove(struct node* hd[],int x)
{
	int c=0;
	struct node* tmp[10];
	for(int i=0; i<10; i++)
	tmp[i]=hd[i];
	
	if(tmp[x%10]!=NULL && tmp[x%10]->x==x && tmp[x%10]->next==NULL)
	tmp[x%10]=NULL;
	
	else if(tmp[x%10]!=NULL && tmp[x%10]->x==x && tmp[x%10]->next!=NULL)
	tmp[x%10]=tmp[x%10]->next;
	
	else
	{	
		while(tmp[x%10]!=NULL && tmp[x%10]->next!=NULL)
		{
			if(tmp[x%10]->next->x==x)
			{
				tmp[x%10]->next=tmp[x%10]->next->next;
				free(tmp[x%10]->next);
				c=1;
				break;
			}
			tmp[x%10]=tmp[x%10]->next;
		}
		
		if(!c)
		cout<<"Not Present\n";
	}
	return tmp[x%10];
}

void Union(struct node* hd1[],struct node* hd2[],int size_hd1,int size_hd2,struct node* unn[])
{
	struct node* tmp1[10],*tmp2[10];
	for(int i=0; i<10; i++)
	{
	tmp1[i]=hd1[i];
	tmp2[i]=hd2[i];
	}
	int X[size_hd1+size_hd2];
	int n=0,c=0,n1;
	for(int i=0; i<10; i++)
	{
		while(tmp1[i]!=NULL)
		{
			X[n++]=tmp1[i]->x;
			tmp1[i]=tmp1[i]->next;
		}
	}
	n1=n;
	for(int i=0; i<10; i++)
	{
		while(tmp2[i]!=NULL)
		{
			c=0;
			for(int j=0; j<n1; j++)
			{
				if(X[j]==tmp2[i]->x)
				{
				c=1;
				break;
				}
			}
			if(c==0)
			X[n++]=tmp2[i]->x;
			tmp2[i]=tmp2[i]->next;
		}
	}
	build(unn,X,n);
}

void Intersection(struct node* hd1[],struct node* hd2[],struct node* intsec[])
{
	int X[size(hd1)];
	int Y[size(hd1)];
	int nx=0,ny=0,c=0;
	struct node* tmp1[10],*tmp2[10];
	for(int i=0; i<10; i++)
	{
	tmp1[i]=hd1[i];
	tmp2[i]=hd2[i];
	}
	for(int i=0; i<10; i++)
	{
		while(tmp1[i]!=NULL)
		{
			Y[ny++]=tmp1[i]->x;
			tmp1[i]=tmp1[i]->next;
		}
	}
	for(int j=0; j<10; j++)
	{
		while(tmp2[j]!=NULL)
		{
			c=0;
			for(int i=0; i<ny; i++)
			{
				if(Y[i]==tmp2[j]->x)
				c=1;
			}
			if(c==1)
			X[nx++]=tmp2[j]->x;
			tmp2[j]=tmp2[j]->next;
		}
	}
	build(intsec,X,nx);
}

void difference(struct node* hd1[],struct node* hd2[],struct node* diff[])
{
	int X[size(hd1)];
	int Y[size(hd1)];
	int nx=0,ny=0,c=0;
	struct node* tmp1[10],*tmp2[10];
	for(int i=0; i<10; i++)
	{
	tmp1[i]=hd1[i];
	tmp2[i]=hd2[i];
	}
	for(int i=0; i<10; i++)
	{
		while(tmp2[i]!=NULL)
		{
			Y[ny++]=tmp2[i]->x;
			tmp2[i]=tmp2[i]->next;
		}
	}
	for(int j=0; j<10; j++)
	{
		while(tmp1[j]!=NULL)
		{
			c=0;
			for(int i=0; i<ny; i++)
			{
				if(Y[i]==tmp1[j]->x)
				c=1;
			}
			if(c==0)
			X[nx++]=tmp1[j]->x;
			tmp1[j]=tmp1[j]->next;
		}
	}
	build(diff,X,nx);
}

int subset(struct node* hd1[],struct node* hd2[])
{
	int c=0;
	struct node* tmp1[10],*tmp2[10];
	for(int i=0; i<10; i++)
	{
	tmp1[i]=hd1[i];
	tmp2[i]=hd2[i];
	}
	for(int i=0; i<10; i++)
	{
		while(tmp1[i]!=NULL)
		{
			c=0;
			for(int k=0; k<10; k++)
			tmp2[k]=hd2[k];
			for(int j=0; j<10; j++)
			{
				while(tmp2[j]!=NULL)
				{
					if(tmp1[i]->x==tmp2[j]->x)
					c=1;
					tmp2[j]=tmp2[j]->next;
				}
			}
			if(!c)
			return c;
			tmp1[i]=tmp1[i]->next;
		}
	}
	return c;
}

int main()
{
	struct node* set1[10],*set2[10],*set3[10],*set4[10],*set5[10];
	create(set1),create(set2),create(set3),create(set4),create(set5);
	int n,v,c=1;
	
	cout<<"Enter number of elements to enter in first set : ";
	cin>>n;
	int A[n];
	cout<<"Enter the elements for first set : ";
	for(int i=0; i<n; i++)
	cin>>A[i];
	build(set1,A,n);
	int size_set1=size(set1);
	cout<<"First set : ";
	enumerate(set1);
	
	cout<<"Enter number of elements to enter in second set : ";
	cin>>n;
	int B[n];
	cout<<"Enter the elements for second set : ";
	for(int i=0; i<n; i++)
	cin>>B[i];
	build(set2,B,n);
	int size_set2=size(set2);
	cout<<"Second set : ";
	enumerate(set2);
	
	Union(set1,set2,size_set1,size_set2,set3);
	cout<<"Union of set1 and set2 : ";
	enumerate(set3);
	
	Intersection(set1,set2,set4);
	cout<<"Intersection of set1 and set2 : ";
	enumerate(set4);
	
	difference(set1,set2,set5);
	cout<<"Difference of set1 and set2 : ";
	enumerate(set5);
	
	if(subset(set1,set2))
	cout<<"First set is a subset of second\n";
	else
	cout<<"First set is not a subset of second\n";
	
	c=1;
	while(c)
	{
	cout<<"Enter the element to remove from set1 : ";
	cin>>v;
	set1[v%10]=remove(set1,v);
	enumerate(set1);
	cout<<"Enter 0 to exit : ";
	cin>>c;
	}
}
