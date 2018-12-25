/* Code for Binary Search Tree with all operations including Insertion , finding successor and precessor of the given element ,
deleting the given node from the tree , and all traversals.    
Sucessor and Precessor operations are implemented using searchforvalue and searchforaddress sub operations to ease 
the task for finding the element each time we need. */

#include<iostream>
#include<cstdlib>
using namespace std;

struct node
{
	struct node* prnt;
	struct node* left;
	struct node* right;
	int x;
};
struct node* root=NULL;
struct node* temp=NULL;
int xtemp;

struct node* deletenode(struct node* rt,int d)
{
	struct node* tmp=rt;
	if(rt==NULL)
	return rt;
	else if(d<rt->x)
	rt->left=deletenode(rt->left,d);
	else if(d>rt->x)
	rt->right=deletenode(rt->right,d);
	else
	{
		if(tmp->left!=NULL)
		{
			tmp=tmp->left;
			while(tmp->right!=NULL)
			{
				tmp=tmp->right;
			}
			if(tmp!=rt->left)
			tmp->prnt->right=tmp->left;
			if(tmp->left!=NULL)
			tmp->left->prnt=tmp->prnt;
			//sometimes program stuck due to incorrect statement like pointing from null to other locations and appears like infinite loop
		}
		else if(tmp->right!=NULL)
		{
			tmp=tmp->right;
			while(tmp->left!=NULL)
			{
				tmp=tmp->left;
			}
			if(tmp!=rt->right)
			tmp->prnt->left=tmp->right;
			if(tmp->right!=NULL)
			tmp->right->prnt=tmp->prnt;
		}
		else
		return NULL;
		if(tmp!=rt->left)
		tmp->left=rt->left;
		if(tmp!=rt->right)
		tmp->right=rt->right;
		tmp->prnt=rt->prnt;
	}
	return tmp;
}

struct node* Insert(struct node* rt,int v,struct node* rt1)
{
	if(rt==NULL)
	{
		rt=(struct node*)malloc(sizeof(struct node));
		rt->prnt=rt1;
		rt->x=v;
		rt->left=rt->right=NULL;
		return rt;
	}
	if(rt->x>v)
	{
		rt->left=Insert(rt->left,v,rt);
	}
	else
	{
		rt->right=Insert(rt->right,v,rt);
	}
	return rt;
}

void preorder(struct node* rt)
{
    if(rt==NULL)
	{
	return;
	}
	cout<<rt->x<<" ";
	preorder(rt->left);
	preorder(rt->right);	
}

void postorder(struct node* rt)
{
	if(rt==NULL)
	{
	return;
	}
	preorder(rt->left);
	preorder(rt->right);
	cout<<rt->x<<" ";
}

void inorder(struct node* rt)
{
	if(rt==NULL)
	{
	return;
	}
	preorder(rt->left);
	cout<<rt->x<<" ";
	preorder(rt->right);
}

void searchforvalue(struct node* rt,int n)
{
	if(rt==NULL)
	{
	return;
	}
	if(rt->x==n)
	xtemp=1;
	searchforvalue(rt->left,n);
	searchforvalue(rt->right,n);
}
void searchforaddress(struct node* rt,int n)
{
	if(rt==NULL)
	{
	return;
	}
	if(rt->x==n)
	temp=rt;
	searchforaddress(rt->left,n);
	searchforaddress(rt->right,n);
	return;
}

void successor(struct node* rt,int n)
{
	searchforaddress(rt,n);
	struct node* nadd=temp;
	struct node* tmp=temp;
	searchforvalue(rt,n);
	if(xtemp)
	{
		if(nadd->right==NULL)
		{
			if(nadd==rt)
			{
				cout<<"No successor......\n";
				return;
			}
			xtemp=0;
			while(!xtemp && tmp!=rt)
			{
				tmp=tmp->prnt;
				searchforvalue(tmp->left,n);
			}
			if(tmp==rt && tmp->x<n)
			{
				cout<<"No successor......\n";
				return;
			}
		}
		else
		{
			tmp=tmp->right;
			while(tmp->left!=NULL)
			tmp=tmp->left;
		}
		cout<<"Successor is : "<<tmp->x<<endl;
		return;
	}
	else
	cout<<"No such Node....\n";
}

void precessor(struct node* rt,int n)
{
	searchforaddress(rt,n);
	struct node* nadd=temp;
	struct node* tmp=temp;
	searchforvalue(rt,n);
	if(xtemp)
	{
		if(nadd->left==NULL)
		{
			if(nadd==rt)
			{
				cout<<"No precessor......\n";
				return;
			}
			xtemp=0;
			while(!xtemp && tmp!=rt)
			{
				tmp=tmp->prnt;
				searchforvalue(tmp->right,n);
			}
			if(tmp==rt && tmp->x>n)
			{
				cout<<"No precessor......\n";
				return;
			}
		}
		else
		{
			tmp=tmp->left;
			while(tmp->right!=NULL)
			tmp=tmp->right;
		}
		cout<<"Precessor is : "<<tmp->x<<endl;
		return;
	}
	else
	cout<<"No such Node....\n";
}

int main()
{
	int i,v,d,n;
	do
	{
		cout<<"Enter Value to Insert in the tree : ";
		cin>>v;
		root=Insert(root,v,root);
		cout<<"Tree is : ";
		preorder(root);
		cout<<"\nEnter 0 to exit or any to enter more values : ";
		cin>>i;
	}
	while(i);
	cout<<"pre-order : ";
	preorder(root);
	cout<<"\npost-order : ";
	postorder(root);
	cout<<"\nin-order : ";
	inorder(root);
	do
	{
		cout<<"\nEnter node to delete : ";
		cin>>d;
		root=deletenode(root,d);
		cout<<"Remaining Tree is : ";
		preorder(root);
		cout<<"\nEnter 0 to exit : ";
		cin>>i;
	}
	while(i);
	do
	{
		cout<<"Enter element to find the successor of : ";
		cin>>n;
	    successor(root,n);
	    xtemp=0,temp=NULL;
		cout<<"Enter 0 to exit : ";
		cin>>i;	
	}
	while(i);
	do
	{
		cout<<"Enter element to find the precessor of : ";
		cin>>n;
	    precessor(root,n);
	    xtemp=0,temp=NULL;
		cout<<"Enter 0 to exit : ";
		cin>>i;
	}
	while(i);
}
