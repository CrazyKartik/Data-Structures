/*
This program implements the functions to insert values in a binary search tree , check 2 bst if they are totally same , 
structurally Identical or not.
Also helps check binary tree given is binary tree or a binary search tree.
A function to print tree structurally---
	Example---
		Tree in inorder 2 3 4 5 6 7 8 will be printed as(5 be a root)
						8
					7
						6
				5
						4
					3
						2


Function to check if there is a path in tree, values along which results in the given sum
Funnction to print all the available paths to the leaf in the tree
Function to mirror the tree i.e, exchange all the left and right pointers
Function to calculate the number of bst possible with given number of different values
(Can be optimized using DP but given solution is using basic recursion)
*/


#include<iostream>
#include<cstdlib>
using namespace std;
int sz=0;

struct node
{
	int data;
	struct node* left;
	struct node* right;
};

struct node* newnode(int v)
{
		struct node* rt=(struct node*)malloc(sizeof(struct node));
		rt->data=v;
		rt->left=NULL;
		rt->right=NULL;
		return rt;
}

struct node* Insert(struct node* rt,int v)
{
	if(rt==NULL)
	{
		rt=newnode(v);
		sz++;
		return rt;
	}
	else if(rt->data>v)
	rt->left=Insert(rt->left,v);
	else
	rt->right=Insert(rt->right,v);
	return rt;
}

void Inorder(struct node* rt)
{
	if(rt==NULL)
	return;
	Inorder(rt->left);
	cout<<rt->data<<" ";
	Inorder(rt->right);
}

bool check(struct node* rt1,struct node* rt2)
{
	static bool b=true;
	if(rt1==NULL && rt2==NULL)
	return true;
	else if(rt1==NULL || rt2==NULL)
	return false;
	b=b&check(rt1->left,rt2->left);
	if(rt1->data==rt2->data)
	b=b&true;
	else
	return false;
	b=b&check(rt1->right,rt2->right);
	return b;
}

bool check_structure(struct node* rt1,struct node* rt2)
{
	static bool bl=true;
	if(rt1==NULL && rt2==NULL)
	return true;
	else if(rt1==NULL || rt2==NULL)
	return false;
	bl=bl&check_structure(rt1->left,rt2->left);
	bl=bl&check_structure(rt1->right,rt2->right);
	return bl;
}

void tree_mirror(struct node** rt)
{
	struct node* temp;
	if((*rt)==NULL)
	return;
	temp=(*rt)->left;
	(*rt)->left=(*rt)->right;
	(*rt)->right=temp;
	tree_mirror(&(*rt)->left);
	tree_mirror(&(*rt)->right);
}

void print_path(struct node* rt,int A[],int l)
{
	if(rt==NULL)
	return;
	
	if(rt->left==NULL && rt->right==NULL)
	{
		for(int i=0; i<l; i++)
		{
			cout<<A[i]<<" -> ";
		}
		cout<<rt->data<<endl;
		return;
	}
	A[l]=rt->data;
	print_path(rt->left,A,l+1);
	print_path(rt->right,A,l+1);
}


int Calculate(int n, int X[])
{
	         
	if (n==1 || n==0) 
	return 1;
	
	int Possible = 0;
    for (int i=1; i<=n; i++) 
	{
		X[i-1]=Calculate(i-1, X);  	                 
		X[n-i]=Calculate(n-i, X);  
		Possible += X[i-1]*X[n-i];  
	}
	return Possible;
}


void print_structurally(struct node* rt,int c)
{
	if(rt==NULL)
	return;
	print_structurally(rt->right,c+1);
	for(int i=0; i<c; i++)
	cout<<"     ";
	cout<<rt->data<<endl;
	print_structurally(rt->left,c+1);
}

bool search_path(int sum,struct node* rt)
{
	static bool c=0;
	if(rt==NULL)
	{
	if(sum==0)
		c=true;
	return c;
	}
	c=search_path(sum-rt->data,rt->left);
	c=search_path(sum-rt->data,rt->right);
	return c;
}

bool check_bst(struct node* rt,int v,int t)
{
	static bool c=true;
	if(rt==NULL)
	return true;
	if(t==0)
	{
		if(v>rt->data)
		c=c&true;
		else
		return false;
	}
	else
	{
		if(v<rt->data)
		c=c&true;
		else
		return false;
	}
	c=c&check_bst(rt->left,rt->data,0);
	c=c&check_bst(rt->right,rt->data,1);
	return c;
}

int main()
{
	struct node* root1=NULL;
	struct node* root2=NULL;
	int c,v,s;
	do
	{
		cout<<"Enter value to insert in tree 1 : ";
		cin>>v;
		root1=Insert(root1,v);
		cout<<"Tree 1 is : \n";
		Inorder(root1);
		cout<<endl;
		cout<<"Enter 0 to exit : ";
		cin>>c;
	}
	while(c);

	do
	{
		cout<<"Enter value to insert in tree 2 : ";
		cin>>v;
		root2=Insert(root2,v);
		cout<<"Tree 2 is : \n";
		Inorder(root2);
		cout<<endl;
		cout<<"Enter 0 to exit : ";
		cin>>c;
	}
	while(c);
	if(check(root1,root2))
	cout<<"Both are same\n";
	else
	cout<<"Not same\n";
	if(check_structure(root1,root2))
	cout<<"Both are structurally identical\n";
	else
	cout<<"Not structurally identical\n";
	
	cout<<endl<<endl;
	print_structurally(root1,0);
	cout<<endl<<endl;
	
	int A[sz]={0};
	cout<<"Paths---\n";
	print_path(root1,A,0);
	
	cout<<"Enter sum to search path : ";
	cin>>s;
	if(search_path(s,root1))
	cout<<endl<<"Path available for the given sum\n";
	else
	cout<<endl<<"No path available for the given sum\n";
		
	tree_mirror(&root1);
	cout<<"Mirror Tree : \n";
	Inorder(root1);
	cout<<endl<<endl;
	
	struct node* bin_tree1=(struct node*)malloc(sizeof(struct node));
	bin_tree1=newnode(1);
	bin_tree1->left=newnode(2);
	bin_tree1->left->left=newnode(3);
	bin_tree1->right=newnode(4);
	bin_tree1->right->left=newnode(5);
	cout<<"Binary Tree 1 : \n";
	Inorder(bin_tree1);
	cout<<endl;
	if(check_bst(bin_tree1->left,bin_tree1->data,0))
	cout<<"Binary\n";
	else
	cout<<"Not Binary\n";
	
	struct node* bin_tree2=(struct node*)malloc(sizeof(struct node));
	bin_tree2=newnode(5);
	bin_tree2->left=newnode(3);
	bin_tree2->left->left=newnode(2);
	bin_tree2->right=newnode(7);
	bin_tree2->right->left=newnode(6);
	cout<<"\nBinary Tree 2 : \n";
	Inorder(bin_tree2);
	cout<<endl;
	if(check_bst(bin_tree2->left,bin_tree2->data,0))
	cout<<"Binary\n";
	else
	cout<<"Not Binary\n";
	
	int n;
	cout<<"\nEnter the number of different nodes in the tree : ";
	cin>>n;
	int X[n+1]={0};
	cout<<Calculate(n,X);
}
