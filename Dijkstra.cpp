#include<iostream>
#include<cstdlib>
#include<unordered_map>
#include<cstring>
#include<vector>
#include<stack>
#include "Heap.h"
using namespace std;


void dijkstra(int n,int s,int t,unordered_map<int,int> loc,int V[],vector <pair<int,int>> adj[])
{
	Heap h;
	stack <int> st;
	int d[n],v,pred[n];
	
	for(int i=0; i<n; i++)
	{
		d[i]=INT_MAX;
		pred[i]=INT_MIN;
	}
	d[loc[s]]=0;
	
	for(int i=0; i<n; i++)
	{
		h.Insert(V[i],d[i]);
	}
	
	
	while(!h.isempty())
	{
		v=h.top();
		h.delete_node(v);
		
		for(auto it=adj[loc[v]].begin(); it!=adj[loc[v]].end(); it++)
		{
			int m=d[loc[v]]+it->second;
			d[loc[it->first]]=(d[loc[it->first]]<m)?d[loc[it->first]]:m;
			h.setP(it->first,d[loc[it->first]]);
			
			if(d[loc[it->first]]==m)
			{
				pred[loc[it->first]]=v;
			}
		}
	}
	
	int x=pred[loc[t]];
	st.push(t);
	while(x!=INT_MIN)
	{
		st.push(x);
		x=pred[loc[x]];
	}
	
	cout<<"Path is----\n";
	while(!st.empty())
	{
		cout<<st.top();
		st.pop();
		if(!st.empty())
		cout<<" -> ";
	}
	cout<<endl;
	
	cout<<"Length of the path is : "<<d[loc[t]]<<endl;
}


int main()
{
	int n,a,s,t;
	int v,u,w,c;
	cout<<"Enter number of vertices : ";
	cin>>n;
	int V[n];
	unordered_map <int,int> loc;
	cout<<"Enetr vertices : ";
	for(int i=0; i<n; i++)
	{
		cin>>a;
		V[i]=a;
		loc[a]=i;
	}
	vector <pair<int,int>> adj[n];
	
	cout<<"\nEnter Edges and Weights--------\n\n";
	
	do
	{
		cout<<"Enter vertex 1 : ";
		cin>>u;
		cout<<"Enter vertex 2 : ";
		cin>>v;
		cout<<"Enter weight : ";
		cin>>w;
		
		adj[loc[u]].push_back(make_pair(v,w));
		
		cout<<"Enter 1 to enter more edges or 0 to exit : ";
		cin>>c;
	}
	while(c);
	
	cout<<"Enter Source : ";
	cin>>s;
	cout<<"Enter Target : ";
	cin>>t;
	
	dijkstra(n,s,t,loc,V,adj);
}
