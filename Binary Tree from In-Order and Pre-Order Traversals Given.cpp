/*
Constructing the Binary Tree from the In-Order and Pre-Order Traversals given.
When using preorder preferrence we start insertion from the left then to the right.
To check for the validity of the traversals we use the same method i.e, start checking by left elements then right.
*/


#include<iostream>
#include<cstdlib>
using namespace std;
int nodeindex;
int loc(int S[],int ss,int es,int s);

int checkvalidity(int P[],int I[],int si,int ei)
{
	if(si>ei)
	return 0;
	int x=P[nodeindex++],c=0,i;
	for(i=si; i<=ei; i++)
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
	c=checkvalidity(P,I,si,i-1);
	c=checkvalidity(P,I,i+1,ei);
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
	
	int x=P[nodeindex++];
	int loc_x=loc(I,si,ei,x);
	rt=makenode(x);
	
	rt->left=maketree(rt->left,I,si,loc_x-1,P);
    rt->right=maketree(rt->right,I,loc_x+1,ei,P);

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
	cout<<"Enter pre-order traversal of the tree : ";
	for(int i=0; i<n; i++)
	cin>>P[i];
	cout<<"Enter in-order traversal of the tree : ";
	for(int i=0; i<n; i++)
	cin>>I[i];
	nodeindex=0;
	cout<<endl;
	checkvalidity(P,I,0,n-1);
	nodeindex=0;
    root=maketree(root,I,0,n-1,P);
    cout<<"Post-Order is : ";
    postorder(root);
    cout<<endl;
    cout<<"Pre-Order is : ";
    preorder(root);
}
