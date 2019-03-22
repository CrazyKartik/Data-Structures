#include<iostream>
#include<cstdlib>
#include<queue>
#include<cstring>
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

void is_mother(int V[],int *A,int l,int v,int vis[])
{
	int iv=find_index(v,V,l);
	vis[iv]=1;
	
	for(int i=0; i<l; i++)
	{
		if(*(A+(l*iv)+i)==1 && vis[i]==0)
		is_mother(V,A,l,V[i],vis);
	}
}


int Topological_Sort(int V[],int *A,int l,int vis[],int v,int S[],int si)
{
	int iv=find_index(v,V,l);
	
	vis[iv]=1;
	for(int i=0; i<l; i++)
	{
		if(*(A+(l*iv)+i)==1 && vis[i]==0)
			si=Topological_Sort(V,A,l,vis,V[i],S,si);
	}
	S[si++]=v;
	return si;
}
int do_Topo_Sort(int V[],int *A,int l)
{
	int vis[l]={0},si=0,S[l]={0},e=0;
	
	for(int i=0; i<l; i++)
	{
		if(vis[i]==0)
			si=Topological_Sort(V,A,l,vis,V[i],S,si);
	}
	for(int i=si-1; i>=0; i--)
	{
		cout<<S[i]<<" ";
	}
	cout<<endl<<endl;
	
	for(int i=si-1; i>=0; i--)
	{
		for(int j=i-1; j>=0; j--)
		{
			if(*(A+(l*find_index(S[i],V,l))+find_index(S[j],V,l))==0)
			{
				e++;
			}
		}
	}
	
	memset(vis,0,sizeof(vis));
	is_mother(V,A,l,S[si-1],vis);
	int c=1;
	for(int i=0; i<l; i++)
	{
		if(vis[i]==0)
		c=0;
	}
	if(c)
	cout<<S[si-1]<<" is mother vertex\n";
	else
	cout<<"No mother vertex\n";
	
	return e;
}


int is_strongly_connected(int V[],int *A,int l,int k,int v)
{
	static int color[100]={0};
	int ans=1;
	int iv=find_index(v,V,l);
	color[iv]=1;
	
	for(int i=0; i<l; i++)
	{
		if(*(A+(l*iv)+i)==1 && color[i]==0)
		{
			color[i]=1;
			ans=is_strongly_connected(V,A,l,k+1,V[i]);
		}
	}
	for(int i=0; i<l; i++)
	{
		if(color[i]==0)
		return 0;
	}
	
	for(int i=0; i<l; i++)
	{
		if(color[i]!=1)
		return 0;
		for(int j=0; j<l; j++)
		{
			int t=*(A+(l*i)+j);
			*(A+(l*i)+j)=*(A+(l*j)+i);
			*(A+(l*j)+i)=t;
		}
	}
	
	if(k==1 && ans==1)
	{
		memset(color,0,sizeof(color));
		ans=is_strongly_connected(V,A,l,k+1,V[0]);
	}
		
	return ans;
}


int is_cyclic(int V[],int *A,int l,int ve)
{
	static int visited[100]={0};
	int c=0;
	
	int iv=find_index(ve,V,l);
	visited[iv]=1;
	for(int i=0; i<l; i++)
	{
		if(*(A+(l*iv)+i)==1 && *(A+(l*i)+iv)==1)
		return 1;
		if(*(A+(l*iv)+i)==1 && visited[i]==0)
			c=is_cyclic(V,A,l,V[i]);
		else if(*(A+(l*iv)+i)==1 && visited[i]==1)
			return 1;
	}
	visited[iv]=2;
	return c;
}
int check_cyclic(int V[],int *A,int l)
{
	int c=0;
	for(int i=0; i<l; i++)
	{
		c=is_cyclic(V,A,l,V[i]);
		if(c==1)
		break;
	}
	return c;
}


int main()
{
	int *V=(int*)malloc(sizeof(int));
	int c,i=0,v1,v2,e=0;
	
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
			e++;
			A[i1][i2]=1;
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
	
	
	int new_A[i][i]={0},arr[i],dep[i];
	
	int ne=do_Topo_Sort(V,*A,i);
	if(!check_cyclic(V,*A,i))
		cout<<"\nNumber of edges that can be added are : "<<ne<<endl;
	else
		cout<<"\nNumber of edges that can be added are : 0"<<endl;
	
	if(is_strongly_connected(V,*A,i,1,V[0]))
		cout<<"\nGiven Graph is Strongly Connected\n";
	else
		cout<<"\nGiven Graph is not Strongly Connected\n";
}
