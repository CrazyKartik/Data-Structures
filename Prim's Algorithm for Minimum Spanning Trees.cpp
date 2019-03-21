/*
Given Code can be easily optimized using priority_queue(heap) data structure.
But the optimized code would be more complex to understand.
Using heap, time complexity can be reduced to (nlogm)
*/

#include<iostream>
#include<unordered_map>
#include<cstring>
using namespace std;


void primMST(int *graph,int V,unordered_map <int,int> loc,int Ver[]) 
{ 
    int parent[V],par_ind[V]={0};
    int key[V],MST=0;  
    bool S[V];  
  
    for (int i = 0; i < V; i++) 
        key[i] = INT_MAX, S[i] = false; 

    key[0] = 0;
    parent[0] = -1;
    int pi=0;
  	
    for (int count=0; count<V-1; count++) 
    { 
        int u,min=INT_MAX;
        
        for (int v=0; v<V; v++) 
	    	if (S[v]==false && key[v]<min) 
	        	min = key[v],u=v;
        
		S[u] = true; 

        for (int v = 0; v < V; v++) 
	        if (*(graph+v+u*V) && S[v] == false && *(graph+v+u*V)<key[v]) 
	            parent[v]=Ver[u],key[v]=*(graph+v+u*V),par_ind[v]=u;
    } 
    
	for(int i=1; i<V; i++)
    {
		MST+=*(graph+par_ind[i]+V*i);
	}
    cout<<MST<<endl;
    
    for (int i=1; i<V; i++) 
    	cout<<parent[i]<<"------"<<Ver[i]<<endl; 
} 
   
int main() 
{ 
	int V,v1,v2,w,c,v;
	cout<<"Enter number of edges : ";
	cin>>V;
	int Vertex[V],graph[V][V];
	memset(graph,0,sizeof(graph));
	unordered_map <int,int> loc;
	cout<<"Enter vertices : ";
	for(int i=0; i<V; i++)
	{
		cin>>v;
		Vertex[i]=v;
		loc[v]=i;
	}
	
	do
	{
		cout<<"Enter vertex 1 : ";
		cin>>v1;
		cout<<"Enter vertex 2 : ";
		cin>>v2;
		cout<<"Enter Weight : ";
		cin>>w;
		graph[loc[v1]][loc[v2]]=w;
		graph[loc[v2]][loc[v1]]=w;
		cout<<"Enter 0 to exit : ";
		cin>>c;
	}
	while(c);
	
    primMST(*graph,V,loc,Vertex); 
} 
