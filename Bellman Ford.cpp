#include<iostream>
#include<cstdlib>
#include<unordered_map>
#include<cstring>
#include<vector>
#include<stack>
using namespace std;


void bellman(int n,int s,int t,unordered_map<int,int> loc,int V[],vector <pair<int,int>> adj[])
{
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
		for(int j=0; j<n; j++)
		{
			v=V[j];
			for(int k=0; k<n; k++)
			{
				if(k!=j)
				{
					for(auto it=adj[k].begin(); it!=adj[k].end(); it++)
					{
						int m;
						if(it->first==v)
						{
							if(d[k]!=INT_MAX && d[j]>d[k]+it->second)
							{
							d[j]=d[k]+it->second;
							pred[j]=V[k];
							}
						}
					}
				}
			}
		}
	}
	
	for(int j=0; j<n; j++)
	{
		v=V[j];
		for(int k=0; k<n; k++)
		{
			if(k!=j)
			{
				for(auto it=adj[k].begin(); it!=adj[k].end(); it++)
				{
					if(it->first==v)
					{
						if(d[k]!=INT_MAX && d[j]>d[k]+it->second)
						{
						cout<<"\nContains Negative Cycle!!!!\n\n";
						return;
						}
					}
				}
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
		cout<<st.top()<<" ";
		st.pop();
		if(!st.empty())
		cout<<"-> ";
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
	
	bellman(n,s,t,loc,V,adj);
}
