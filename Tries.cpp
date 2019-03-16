/*
Trie to contain words containing only upper case english alphabets.
Insertion and Deletion
*/


#include<iostream>
#include<cstdlib>
#include<cstring>
using namespace std;

struct node
{
	int word;
	char c;
	struct node* child[26];
};

struct node* root=NULL;


int index=-1;
struct node* Insert(struct node* rt,string S,int l)
{
	while(index<l)
	{
		if(rt==NULL)
		{
			rt=(struct node*)malloc(sizeof(struct node));
			rt->c=S[index];
			memset(rt->child,NULL,sizeof(rt->child));
			rt->word=0;
		}
		rt->child[(int(S[index+1]))%65]=Insert(rt->child[(int(S[++index]))%65],S,l);
	}
	if(rt!=NULL)
		if(rt->c==S[index-1])
		rt->word=1;
	return rt;
}

int del_index;
struct node* delete_node(struct node* rt,string W,int len)
{
	int c=1;
	
	while(del_index<len)
	{
		if(rt->child[(int(W[del_index]))%65]==NULL)
		{
			cout<<"No such word!!!\n\n";
			del_index=len;
			return rt;
		}
		rt->child[(int(W[del_index]))%65]=delete_node(rt->child[(int(W[del_index++]))%65],W,len);
	}
	if(rt->word==0 && rt->c==W[len-1])
	{
		cout<<"No Such Word!!!\n\n";
		return rt;
	}
	for(int i=0; i<26; i++)
	{
		if(rt->child[i]!=NULL)
		c=0;
	}
	if(c && rt->c==W[len-1])
	return NULL;
	else if(del_index==len && rt->c==W[len-1])
	rt->word=0;
	
	return rt;
}

void print_trie(struct node* rt,int l,char A[])
{
	if(rt==NULL)
		return;
	A[l++]=rt->c;
	if(rt->word==1)
	{
		for(int i=0; i<l; i++)
			cout<<A[i];
		cout<<endl;
	}
	for(int i=0; i<26; i++)
	{
		print_trie(rt->child[i],l,A);
	}
}

int main()
{
	string s;
	int c;
	root=(struct node*)malloc(sizeof(struct node));
	root->c=' ';
	root->word=0;
	memset(root->child,NULL,sizeof(root->child));
	do
	{
		char A[1000];
		cout<<"Enter word to Insert : ";
		cin>>s;
		root=Insert(root,s,s.length());
		index=-1;
		
		cout<<endl;
		print_trie(root,0,A);
		cout<<endl;
		
		cout<<"Enter 0 to exit : ";
		cin>>c;
	}
	while(c);
	
	do
	{
		char A[1000];
		del_index=0;
		cout<<"Enter word to delete : ";
		cin>>s;
		root=delete_node(root,s,s.length());
		print_trie(root,0,A);
		cout<<"Enter 0 to exit : ";
		cin>>c;
	}
	while(c);
}
