#include<iostream>
#include<cstdlib>
#include<cstring>
#include "Q.h"
using namespace std;

int find_index(int v,int V[],int l)
{
	for(int i=0; i<l; i++)
	{
		if(V[i]==v)
		return i;
	}
	return -1;
}

int is_in(int a,int A[],int l)
{
	for(int i=0; i<l; i++)
	{
		if(A[i]==a)
		return 1;
	}
	return 0;
}

int is_bipartite(int V[],int U[],int W[],int *A,int ls1,int ls2)
{
	int color[ls1+ls2]={0},v,x=0,c=0,k1,k2;
	queue <int> q;
	while(x<ls1+ls2)
	{
		if(color[x]==0)
		{
			q.push(V[x]);
			while(q.size()!=0)
			{
				v=q.front();
				int iv=find_index(v,V,ls1+ls2);
				color[iv]=1;
				for(int i=0; i<ls1+ls2; i++)
				{
					if(*(A+i+i*(ls1+ls2))==1)
					return 0;
					if(*(A+(ls1+ls2)*iv+i)==1 && color[i]==0)
					{
						q.push(V[i]);
						color[i]=1;
						if(is_in(v,U,ls1) && is_in(V[i],U,ls1))
						return 0;
						if(is_in(v,W,ls2) && is_in(V[i],W,ls2))
						return 0;
					}
				}
				q.pop();
			}
		}
		x++;
	}
	return 1;
}

int main()
{
	int *U=(int*)malloc(sizeof(int));
	int *W=(int *)malloc(sizeof(int));
	int c,i=0,j=0,v1,v2;
	
	cout<<"Enter first set of elements.....\n";
	do
	{
		U=(int*)realloc(U,(i+1)*sizeof(int));
		cout<<"Enter vertex : ";
		scanf("%d",(U+i));
		i++;
		cout<<"Enter 0 to exit : ";
		cin>>c;
	}
	while(c);
	cout<<endl;
	
	
	cout<<"Enter second set of elements.....\n";
	do
	{
		W=(int*)realloc(W,(j+1)*sizeof(int));
		cout<<"Enter vertex : ";
		scanf("%d",(W+j));
		j++;
		cout<<"Enter 0 to exit : ";
		cin>>c;
	}
	while(c);
	cout<<endl;
	
	cout<<"First set is....\n";
	for(int k=0; k<i; k++)
	cout<<*(U+k)<<" ";
	cout<<endl<<endl;
	cout<<"Second set is....\n";
	for(int k=0; k<i; k++)
	cout<<*(W+k)<<" ";
	cout<<endl<<endl;
	
	
	int V[i+j],z;
	for(z=0; z<i; z++)
	V[z]=U[z];
	for(int y=0; y<j; y++)
	V[z++]=W[y];
	for(int k=0; k<i+j; k++)
	cout<<V[k]<<" ";
	cout<<endl<<endl;
	
	int A[i+j][i+j];
	memset(A,0, sizeof(A));
	
	
	do
	{
		cout<<"Enter vertex v1 of edge : ";
		cin>>v1;
		cout<<"Enter vertex v2 of edge : ";
		cin>>v2;
		int i1=find_index(v1,V,i+j);
		int i2=find_index(v2,V,j+i);
		if(i1==-1 || i2==-1)
			cout<<"Enter valid vertices!!!!\n\n";
		else
		{
			A[i1][i2]=1;
			A[i2][i1]=1;
		}
		cout<<"Enter 0 to exit : ";
		cin>>c;
	}
	while(c);
	
	cout<<endl;
	for(int i1=0; i1<i+j; i1++)
	{
		for(int i2=0; i2<i+j; i2++)
		{
			cout<<A[i1][i2]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
	
	
	if(is_bipartite(V,U,W,*A,i,j))
	cout<<"Is Bipartite...\n\n";
	else
	cout<<"Is Not Bipartite...\n\n";
}
