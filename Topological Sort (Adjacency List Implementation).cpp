#include<iostream>
#include<cstdlib>
using namespace std;

struct node
{
	int ver;
	struct node *next;	
};


int find_index(struct node** A,int v,int l)
{
	for(int i=0; i<l; i++)
	{
		if((*(A+i))->ver==v)
		return i;
	}
	return -1;
}


struct node* Insert(struct node* hd,int v)
{
	struct node* cur=hd;
	struct node* temp=(struct node*)malloc(sizeof(struct node));
	
	temp->ver=v;
	temp->next=NULL;
	
	if(hd==NULL)
	{
		hd=temp;
	}
	else
	{
		while(cur->next!=NULL)
		{
			cur=cur->next;
		}
		cur->next=temp;
	}
	return hd;
}


int Topological_Sort(struct node **A,int l,int vis[],int v,int S[],int si)
{
	int iv=find_index(A,v,l);
	
	vis[iv]=1;
	struct node* temp=*(A+iv);
	for(int i=0; i<l; i++)
	{
		 temp=*(A+iv);
		while(temp!=NULL)
		{
			if(temp->ver==(*(A+i))->ver && vis[i]==0)
				si=Topological_Sort(A,l,vis,(*(A+i))->ver,S,si);
			temp=temp->next;
		}
	}
	S[si++]=v;
	return si;
}
int do_Topo_Sort(struct node **A,int l)
{
	int vis[l]={0},si=0,S[l]={0},e=0;
	
	for(int i=0; i<l; i++)
	{
		if(vis[i]==0)
			si=Topological_Sort(A,l,vis,(*(A+i))->ver,S,si);
	}
	
	for(int i=si-1; i>=0; i--)
	{
		cout<<S[i]<<" ";
	}
	cout<<endl<<endl;
}



int main()
{
	int v,c,n=0;
	struct node **A=(struct node**)malloc(sizeof(struct node*));
	do
	{
		A=(struct node**)realloc(A,(n+1)*sizeof(struct node*));
		cout<<"Enter vertex : ";
		cin>>v;
		*(A+n)=Insert(NULL,v);
		cout<<"Enter 0 to exit : ";
		cin>>c;
		n=n+1;
	}
	while(c);
	
	for(int i=0; i<n; i++)
	{
		cout<<(*(A+i))->ver<<" ";
	}
	cout<<endl;
	
	
	int v1,v2,iv1,iv2;
	do
	{
		cout<<"Enter vertex v1 of edge : ";
		cin>>v1;
		cout<<"Enter vertex v2 of edge : ";
		cin>>v2;
		
		iv2=find_index(*&A,v2,n);
		iv1=find_index(*&A,v1,n);
		if(iv2==-1 || iv1==-1)
		{
			cout<<"\nEnter valid vertices...\n\n";
		}
		else
		*(A+iv1)=Insert(*(A+iv1),v2);
		
		cout<<"Enter 0 to exit : ";
		cin>>c;
	}
	while(c);
	
	
	cout<<"\nConnections......\n";
	for(int i=0; i<n; i++)
	{
		struct node* temp=*(A+i);
		while(temp!=NULL)
		{
			cout<<temp->ver<<" ";
			temp=temp->next;
		}
		cout<<endl;
	}
	
	
	cout<<"\nTopologically Sorted Graph is----\n";
	do_Topo_Sort(*&A,n);	
}
