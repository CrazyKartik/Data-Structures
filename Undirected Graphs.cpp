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

int diameter(int V[],int *A,int l)
{
	int x=0,nc=0,max=0,y=0;
	queue <int> q;
	
	while(y<l)
	{
		int color[l]={0},v,lvl[l]={0};
		x=y,nc=0;
		while(x<l)
		{		
			if(color[x]==0)
			{
				if(nc==1)
					return -1;
				
				q.push(V[x]);
				while(q.size()!=0)
				{
					v=q.front();
					int iv=find_index(v,V,l);
					color[iv]=1;
					for(int i=0; i<l; i++)
					{
						if(*(A+(l)*iv+i)==1 && color[i]==0)
						{
							q.push(V[i]);
							lvl[i]=lvl[iv]+1;
							color[i]=1;
							
							if(lvl[i]>max)
							max=lvl[i];
						}
					}
					q.pop();
				}
				nc++;
			}
			x++;
		}
		y++;
	}
	return max;
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

int is_cyclic(int V[],int *A,int l)
{
	int color[l]={0},pi[l],v,x=0;
	queue <int> q;
	while(x<l)
	{
		if(color[x]==0)
		{
			q.push(V[x]);
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
						color[i]=1;
						pi[i]=v;
					}
					else if(*(A+(l*iv)+i)==1 && color[i]==1 && pi[iv]!=V[i])
					{
						return 1;
					}
				}
				q.pop();
			}
		}
		x++;
	}
	return 0;
}


int is_connected(int V[],int *A,int l,int vis[])
{
	queue <int> q;
	q.push(V[0]);
	
	for(int i=0; i<l; i++)
	{
		if(vis[i]==1)
		{
			q.pop();
			q.push(V[(i+1)%l]);
			break;
		}
		
	}
	
	
	while(q.size()!=0)
	{
		int v=q.front();
		int iv=find_index(v,V,l);
		vis[iv]=1;
		for(int i=0; i<l; i++)
		{
			if(*(A+(l*iv)+i)==1 && vis[i]==0)
			{
				q.push(V[i]);
				vis[i]=1;
			}
		}
		q.pop();
	}
	
	for(int i=0; i<l; i++)
	{
		if(vis[i]==0)
		return 0;
	}
	
	return 1;
}


int check_2_edge_connectivity(int V[],int *A,int l)
{
	int ck=0;
	for(int i=0; i<l; i++)
	{
		for(int j=0; j<l; j++)
		{
			int vis[l]={0};
			if(*((A+i*l)+j)==1)
			{
				*((A+i*l)+j)=0;
				ck=is_connected(V,A,l,vis);
				*((A+i*l)+j)=1;
				if(ck==0)
				return 0;
			}
		}
	}
	return 1;
}


int check_2_vertex_connectivity(int V[],int *A,int l)
{
	int ck=0;
	int AT[l][l];
	
	for(int i=0; i<l; i++)
	{
		for(int j=0; j<l; j++)
		{
			AT[i][j]=*((A+i*l)+j);
		}
	}
	
	for(int i=0; i<l; i++)
	{
		int vis[l]={0};
		for(int j=0; j<l; j++)
		{
			AT[i][j]=0;
			AT[j][i]=0;
		}
		vis[i]=1;
		ck=is_connected(V,*AT,l,vis);
		if(ck==0)
		return 0;
		
		for(int i=0; i<l; i++)
		{
			for(int j=0; j<l; j++)
			{
				AT[i][j]=*((A+i*l)+j);
			}
		}
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
	
	cout<<"BFS Starting from first element you entered : ";
	BFS(V,i,*A);
	
	int d=diameter(V,*A,i);
	if(d==-1)
		cout<<"\nGraph is not Connected!!\n";
	else
	{
		cout<<"\nThe diameter of the graph is : "<<diameter(V,*A,i);
	}
	cout<<endl;
	
	cout<<"\nDFS Starting from first element you entered : ";
	DFS(V,*A,i,V[0]);
	cout<<endl<<endl;
	
	
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
	
	if(is_cyclic(V,*A,i))
	cout<<"\nGiven Graph is Cyclic\n";
	else
	cout<<"\nGiven Graph is not Cyclic\n";
	
	
	if(d==-1)
	cout<<"Given Graph is not 2 edge connected\n";
	else if(check_2_edge_connectivity(V,*A,i))
	cout<<"Given Graph is 2 edge connected\n";
	else
	cout<<"Given Graph is not 2 edge connected\n";
	
	
	if(d==-1)
	cout<<"Given Graph is not 2 vertex connected\n";
	else if(check_2_vertex_connectivity(V,*A,i))
	cout<<"Given Graph is 2 vertex connected\n";
	else
	cout<<"Given Graph is not 2 vertex connected\n";
}
