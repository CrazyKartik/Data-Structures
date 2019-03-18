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

void BFS(int V[],int l,int *A)
{
	int color[l]={0},pi[l],v,x=0,lvl[l]={0};
	queue <int> q;
	while(x<l)
	{
		if(color[x]==0)
		{
			q.push(V[x]);
			cout<<V[x]<<" ";
			while(q.size()!=0)
			{
				v=q.front();
				int iv=find_index(v,V,l);
				color[iv]=1;
				for(int i=0; i<l; i++)
				{
					if(*(A+(l*iv)+i)==1 && color[i]==0)
					{
						q.push(V[i]);
						lvl[i]=lvl[iv]+1;
						color[i]=1;
						pi[i]=v;
						cout<<V[i]<<" ";
					}
				}
				q.pop();
			}
		}
		x++;
	}
	cout<<endl;
}

int tree_edges[100],te=0;
void DFS(int V[],int *A,int l,int v)
{
	static int visited[100]={0},arrival[100]={0},departure[100]={0},time=0,x=0;
	queue <int> q;
	
	while(x<l)
	{
		int iv=find_index(v,V,l);
		if(visited[iv]==0)
		{
			cout<<v<<" ";
			visited[iv]=1;
			arrival[iv]=time++;
			for(int i=0; i<l; i++)
			{
				if(*(A+(l*iv)+i)==1 && visited[i]==0)
				{
					departure[iv]=time++;
					tree_edges[te++]=v;
					tree_edges[te++]=V[i];
					DFS(V,A,l,V[i]);
				}
			}
		}
		
		else if(visited[x]==0)
		{
			q.push(V[x]);
		}
		x++;
	}
	while(q.size()!=0)
	{
	v=q.front();
	q.pop();
	x=0;
	DFS(V,A,l,v);
	}
}

int path_available(int V[],int *A,int l,int v1,int v2)
{
	int color[l]={0},lvl[l]={0};
	queue <int> q;
	q.push(v1);
	
	while(q.size()!=0)
	{
		int v=q.front();
		int iv=find_index(v,V,l);
		color[iv]=1;
		for(int i=0; i<l; i++)
		{
			if(*(A+(l*iv)+i)==1 && color[i]==0)
			{
				lvl[i]=lvl[iv]+1;
				if(V[i]==v2)
					return lvl[i];
					
				q.push(V[i]);
				color[i]=1;
			}
		}
		q.pop();
	}
	return -1;
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


int mother_vertex(int V[],int *A,int l,int v,int vis[])
{
	int iv=find_index(v,V,l),c=1;
		
	vis[iv]=1;
	for(int i=0; i<l; i++)
	{
		if(*(A+(l*iv)+i)==1 && vis[i]==0)
			mother_vertex(V,A,l,V[i],vis);
	}
}
int check_mother_vertex(int V[],int *A,int l)
{
	int mv,vis[l]={0},c;
	for(int i=0; i<l; i++)
	{
		memset(vis,0,sizeof(vis));
		c=1;
		mother_vertex(V,A,l,V[i],vis);
		for(int j=0; j<l; j++)
		{
			if(vis[j]==0)
			c=0;
		}
		if(c)
		return V[i];
	}
	return -1;
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
	
	cout<<"BFS Starting from first element you entered : ";
	BFS(V,i,*A);
	
	cout<<"DFS Starting from first element you entered : ";
	DFS(V,*A,i,V[0]);
	cout<<endl;
	
	
	int lp=0;
	cout<<endl;
	do
	{
		cout<<"Enter the nodes between which you want to find the path : ";
		cin>>v1>>v2;
		
		lp=path_available(V,*A,i,v1,v2);
		if(lp+1!=0)
			cout<<"There is a path of length : "<<lp<<endl;
		else
			cout<<"No Path\n";
		
		cout<<"Enter 0 to exit : ";
		cin>>c;
	}
	while(c);
	
	
	int mv=check_mother_vertex(V,*A,i);//O(V(V+E))
	if(mv!=-1)
		cout<<"Mother vertex is : "<<mv<<endl;
	else
	cout<<"No mother vertex....\n";
	
	
	
	if(check_cyclic(V,*A,i))
	cout<<"\nGiven Graph is Cyclic\n";
	else
	cout<<"\nGiven Graph is not Cyclic\n";
	
	cout<<"\nNo of edges that can be added are : "<<(i*(i-1)/2)-e<<endl;//O(1)
}
