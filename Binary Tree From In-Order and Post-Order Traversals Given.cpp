/*
To Construct a Binary Tree from In-Order and Post-Order Traversals given.
While using postorder preferrence we insert elements from the right subtree followed by left subtree.
To check for validity of the given traversals we use the same method i.e, first check the right then the left.
*/


#include<iostream>
#include<cstdlib>
using namespace std;
int nodeindex=0;
int loc(int S[],int ss,int es,int s);

int checkvalidity(int P[],int I[],int si,int ei)
{
	if(si>ei)
	return 0;
	int x=P[nodeindex--],c=0,i;
	for(i=ei; i>=si; i--)
	{
		if(x==I[i])
		{
		c=1;
		break;
	    }
	}
	if(c==0)
	{
		cout<<"No Tree Possible from the given traversals....\n";
		exit(0);
	}
	c=checkvalidity(P,I,i+1,ei);
	c=checkvalidity(P,I,si,i-1);
}

struct node
{
	int n;
	struct node* left;
    struct node* right;
};
struct node* root=NULL;

struct node* makenode(int n)
{
	struct node* tmp=(struct node*)malloc(sizeof(struct node));
	tmp->n=n;
	tmp->left=tmp->right=NULL;
	return tmp;
}

int loc(int S[],int ss,int es,int s)
{
	int i;
	for(i=ss; i<=es; i++)
	{
		if(S[i]==s)
		return i;
	}
}

struct node* maketree(struct node* rt,int I[],int si,int ei,int P[])
{
	if(si>ei)
	return NULL;
	
	int x=P[nodeindex--];
	int loc_x=loc(I,si,ei,x);
	rt=makenode(x);
	
    rt->right=maketree(rt->right,I,loc_x+1,ei,P);
    rt->left=maketree(rt->left,I,si,loc_x-1,P);
	
	return rt;
}

void postorder(struct node* rt)
{
	if(rt==NULL)
	return;
	postorder(rt->left);
	postorder(rt->right);
	cout<<rt->n<<" ";
}
void preorder(struct node* rt)
{
	if(rt==NULL)
	return;
	cout<<rt->n<<" ";
	preorder(rt->left);
	preorder(rt->right);
}

int main()
{
	int n;
	cout<<"Enter number of nodes in tree : ";
	cin>>n;
	int I[n],P[n];
	cout<<"Enter post-order traversal of the tree : ";
	for(int i=0; i<n; i++)
	cin>>P[i];
	cout<<"Enter in-order traversal of the tree : ";
	for(int i=0; i<n; i++)
	cin>>I[i];
	cout<<endl;
	nodeindex=n-1;
	checkvalidity(P,I,0,n-1);
	nodeindex=n-1;
    root=maketree(root,I,0,n-1,P);
    cout<<"Pre-Order is : ";
    preorder(root);
    cout<<endl;
    cout<<"Post-Order is : ";
    postorder(root);
}
