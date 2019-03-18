/*
C++ program to implement Kruskal's Algorith to find the Minimum Spanning of a Undirected Connected Graph.
Concepts Used are :
			Union by rank
			Path Compression
Basic Vectors , Iterators and maps are used for efficient and simple implementation of the Algorithm.
In this Algorithm we search for the edge with minimum weight and add in the tree if its addition does not produce a cycle in the tree and
continue till we reach the number of edges equal to (n-1) , n being the number of vertex in graph.
*/


#include<iostream>
#include<cstdlib>
#include<iterator>
#include<unordered_map>
#include<vector>
#include<algorithm>
using namespace std;

struct sets
{
	int *parent,*rank;
	int n;
	sets(int n)
	{
		this->n=n;
		rank=new int[n+1];
		parent=new int[n+1];
		
		for(int i=0; i<=n; i++)
		{
			rank[i]=0;
			parent[i]=i;
		}
	}
	int find(int v)
	{
		if(v!=parent[v])
		parent[v]=find(parent[v]);
		return parent[v];
	}
	
	void merge(int u,int v)
	{
		u=find(u),v=find(v);
		if(rank[u]>rank[v])
		parent[v]=u;
		else
		parent[u]=v;
		if(rank[u]==rank[v])
		rank[v]++;
	}	
};


void Kruskal(int n,unordered_map <int,int> loc,vector <pair<int,pair<int,int>>> graph)
{
	int mst_wt=0,v=0;
	sets s(n);
	
	sort(graph.begin(),graph.end());
	
	for(auto i=graph.begin(); i!=graph.end(); i++)
	{
		if(v==n-2)
		break;
		
		int u = i->second.first; 
        int v = i->second.second; 
        
        int set_u=s.find(loc[u]);
        int set_v=s.find(loc[v]);
        
        if(set_u!=set_v)
        {
        	cout<<u<<"------"<<v<<endl;
        	mst_wt+=i->first;
        	s.merge(set_u,set_v);
        	v++;
		}
	}
	
	cout<<"\n The Weight of the MST is : "<<mst_wt<<endl;
}


int main()
{
	int v,c,n=0,v1,v2,w;
	unordered_map <int,int> loc;
	vector <pair<int,pair<int,int>>> graph;
	do
	{
		cout<<"Enter first vertex : ";
		cin>>v1;
		if(loc[v1]==0)
		loc[v1]=n++;
		else if(n<loc[v1])
		loc[v1]=n++;
		
		cout<<"Enter second vertex : ";
		cin>>v2;
		if(loc[v2]==0)
		loc[v2]=n++;
		else if(n<loc[v2] && v1!=v2)
		loc[v2]=n++;
		
		cout<<"Enter Weight : ";
		cin>>w;
		graph.push_back({w,{v1,v2}});
		cout<<"Enter 0 to exit : ";
		cin>>c;
	}
	while(c);
		
	Kruskal(n,loc,graph);
}
