/*
Program to do Insertion in Red-Black Trees(Another Self Balancing Data Structure)
Deletion can also be implemented but it is highly time consuming and cubersome process
*/

#include<iostream>
#include<cstdlib>
using namespace std;


struct node
{
	int data;
	int color;
	struct node* left;
	struct node* right;
	struct node* parent;
};
struct node* root=NULL;


struct node* left_rotate(struct node* rt1,struct node* rt2)
{
	if(rt2->parent!=NULL)
	{
		if(rt2->parent->left==rt2)
		rt2->parent->left=rt1;
		else
		rt2->parent->right=rt1;
	}
	
	rt1->parent=rt2->parent;
	rt2->parent=rt1;
	rt1->color=0;
	rt2->color=1;
	rt2->right=rt1->left;
	rt1->left=rt2;
	
	return rt1;
}

struct node* right_rotate(struct node* rt1,struct node* rt2)
{
	if(rt2->parent!=NULL)
	{
		if(rt2->parent->left==rt2)
		rt2->parent->left=rt1;
		else
		rt2->parent->right=rt1;
	}
	
	rt1->parent=rt2->parent;
	rt2->parent=rt1;
	rt1->color=0;
	rt2->color=1;
	rt2->left=rt1->right;
	rt1->right=rt2;
	
	return rt1;
}


struct node* Insert(struct node* rt,int v,struct node* prnt)
{
	static int dr=0;
	if(rt==NULL)
	{
		rt=(struct node*)malloc(sizeof(struct node));
		rt->left=rt->right=NULL;
		rt->parent=prnt;
		rt->data=v;
		if(prnt==NULL)
		rt->color=0;
		else
		rt->color=1;
		
		if(prnt!=NULL && prnt->color==1)
		dr=0;
		else
		dr=1;
		
		return rt;
	}
	
	if(rt->data>v)
	rt->left=Insert(rt->left,v,rt);
	else if(rt->data<v)
	rt->right=Insert(rt->right,v,rt);
	
	if(!dr)
	{
		if(rt->color==0 && rt->right->color==1 && (rt->left==NULL || rt->left->color==0))
		{
			rt=left_rotate(rt->right,rt);
			dr=1;
		}
		else if(rt->color==0 && rt->left->color==1 && (rt->right==NULL || rt->right->color==0))
		{
			rt=right_rotate(rt->left,rt);
			dr=1;
		}
		else if(rt->color==0 && rt->right!=NULL && rt->right->color==1 && rt->left!=NULL && rt->left->color==1)
		{
			rt->color=1;
			rt->left->color=0;
			rt->right->color=0;
			dr=0;
		}
		
		if(rt->parent==NULL)
		rt->color=0;
	}
	
	return rt;
}

void preorder(struct node* rt)
{
	if(rt==NULL)
	return;
	
	cout<<rt->data<<" "<<rt->color<<endl;
	preorder(rt->left);
	preorder(rt->right);
}

int main()
{
	int v,c;
	do
	{
		cout<<"Enter value : ";
		cin>>v;
		root=Insert(root,v,root);
		cout<<"\nTree is : \n";
		preorder(root);
		cout<<endl;
		cout<<"Enter 0 to exit : ";
		cin>>c;
	}
	while(c);
	
	cout<<"Tree is : ";
	preorder(root);
}
