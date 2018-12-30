/*
Constructing the Binary Tree from the Pre-Order and Post-Order Traversals when we know that each node have exactly 2 children.
To construct the tree from using postorder preferrence we insert to the right first then to the left.
To check for the validity we first check if the last of postorder and the first of preorder match then check for the subparts.
*/


#include<iostream>
#include<cstdlib>
using namespace std;
int nodeindex;
int loc(int S[],int ss,int es,int s);

int checkvalidity(int Pre[],int Post[],int startpre,int endpre)
{
    if(startpre>endpre)
	return 0;
	
	int x=Post[nodeindex--],c=0,y=Post[nodeindex];
	int loc_x=loc(Pre,startpre,endpre,x),loc_y=loc(Pre,startpre,endpre,y);
	for(int i=startpre; i<=endpre; i++)
	{
		if(x==Pre[i])
		{
		c=1;
		break;
	    }
	}
	if(c==0)
	{
		cout<<"No Tree can be constructed from the given Traversals......\n";
		exit(0);
	}
	c=checkvalidity(Pre,Post,loc_x+1,endpre);
	c=checkvalidity(Pre,Post,loc_x+1,loc_y-1);
}

struct node
{
	int x;
	struct node* left;
	struct node* right;
};
struct node* root=NULL;

struct node* makenode(int v)
{
	struct node* temp=(struct node*)malloc(sizeof(struct node));
	temp->x=v;
	temp->left=temp->right=NULL;
	return temp;
}

int loc(int S[],int ss,int es,int s)
{
	for(int i=ss; i<=es; i++)
	{
		if(s==S[i])
		return i;
	}
}

struct node* maketree(struct node* rt,int Pre[],int Post[],int startpre,int endpre)
{
	if(startpre>endpre)
	return NULL;
	
	int x=Post[nodeindex--],y=Post[nodeindex];
	int loc_x=loc(Pre,startpre,endpre,x),loc_y=loc(Pre,startpre,endpre,y);
	rt=makenode(x);
	
	rt->right=maketree(rt->right,Pre,Post,loc_x+1,endpre);
	rt->left=maketree(rt->left,Pre,Post,loc_x+1,loc_y-1);
	
	return rt;
}

void inorder(struct node* rt)
{
	if(rt==NULL)
	return;
	inorder(rt->left);
	cout<<rt->x<<" ";
	inorder(rt->right);
}
void preorder(struct node* rt)
{
	if(rt==NULL)
	return;
	cout<<rt->x<<" ";
	preorder(rt->left);
	preorder(rt->right);
}

int main()
{
	int n;
	cout<<"Enter the number of nodes in the tree : ";
	cin>>n;
	int Pre[n],Post[n];
	cout<<"Enter the Pre-Order Traversal of the tree : ";
	for(int i=0; i<n; i++)
	cin>>Pre[i];
	cout<<"Enter the Post-Order Traversal of the tree : ";
	for(int i=0; i<n; i++)
	cin>>Post[i];
	cout<<endl;
	if(Pre[0]!=Post[n-1])
	{
		cout<<"No Tree can be constructed from the given traversals......\n";
		exit(0);
	}
	nodeindex=n-1;
	checkvalidity(Pre,Post,0,n-1);
	nodeindex=n-1;
	root=maketree(root,Pre,Post,0,n-1);
	cout<<"In-Order Traversal : ";
	inorder(root);
	cout<<endl;
	cout<<"Pre-Order Traversal : ";
	preorder(root);
}
