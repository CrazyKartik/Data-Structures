#include<iostream>
#include<cstdlib>
#include<cstring>
#include<queue>
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


int check_Bipartite(int V[],int *A,int l)
{
	int color[l]={0},v,x=0,col=0;
	queue <int> q;
	while(x<l)
	{
		if(color[x]==0)
		{
			q.push(V[x]);
			while(q.size()!=0)
			{
				col=col%2+1;
				v=q.front();
				int iv=find_index(v,V,l);
				
				if(color[iv]==0 || color[iv]==col)
				{
					color[iv]=col;
					col=col%2+1;
				}
				
				for(int i=0; i<l; i++)
				{
					if(*(A+(l*iv)+i)==1 && (color[i]==0 || color[i]==col%2+1))
					{
						q.push(V[i]);
					
						if(color[i]==0 || color[i]==col)
							color[i]=col;
						else if(color[i]==color[iv])
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
	int *V=(int*)malloc(sizeof(int));
	int c,i=0,v1,v2;
	
	do
	{
		V=(int*)realloc(V,(i+1)*sizeof(int));
		cout<<"Enter vertex : ";
		scanf("%d",(V+i));
		i++;
		cout<<"Enter 0 to exit : ";
		cin>>c;
	}
	while(c);
	cout<<endl;
	for(int j=0; j<i; j++)
	cout<<*(V+j)<<" ";
	cout<<endl<<endl;
	
	int A[i][i];
	memset(A,0, sizeof(A));
	
	do
	{
		cout<<"Enter vertex v1 of edge : ";
		cin>>v1;
		cout<<"Enter vertex v2 of edge : ";
		cin>>v2;
		int i1=find_index(v1,V,i);
		int i2=find_index(v2,V,i);
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
	for(int i1=0; i1<i; i1++)
	{
		for(int i2=0; i2<i; i2++)
		{
			cout<<A[i1][i2]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
	
	cout<<check_Bipartite(V,*A,i);
}
