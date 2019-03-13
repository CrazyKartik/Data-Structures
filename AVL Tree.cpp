/*
Implementation of AVL Trees(Self Balancing Data Structures) 
Insertion and Deletion
*/

#include<iostream>
#include<cstdlib>
using namespace std;

struct node
{
	int data;
	int height;
	struct node* left;
	struct node* right;
	struct node* parent;
};

struct node* root=NULL;


int Balanced(struct node* rt)
{
	if(rt->left==NULL && rt->right==NULL)
	return 1;
	
	if(rt->left!=NULL && rt->right!=NULL)
	{
		if(((rt->left->height)-(rt->right->height))<-1 || ((rt->left->height)-(rt->right->height))>1)
		return 0;
	}
	else if(rt->left==NULL && rt->right->height>1)
	return 0;
	else if(rt->right==NULL && rt->left->height>1)
	return 0;
	
	return 1;
}

void getHeight(struct node* rt)
{
	if(rt->left==NULL && rt->right==NULL)
	rt->height=1;
	
	else if(rt->left==NULL)
	rt->height=(rt->right->height)+1;
	
	else if(rt->right==NULL)
	rt->height=(rt->left->height)+1;
	
	else
	rt->height=((rt->right->height)>(rt->left->height))?(rt->right->height)+1:(rt->left->height)+1;
}

void rebalance(struct node* rt)
{
	if(rt==NULL)
	return;
	
	rebalance(rt->left);
	rebalance(rt->right);
	getHeight(rt);
}

struct node* rotate_left(struct node* rt1,struct node* rt2)
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
	rt2->right=rt1->left;
	rt1->left=rt2;
	
	return rt1;
}

struct node* rotate_right(struct node* rt1,struct node* rt2)
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
	rt2->left=rt1->right;
	rt1->right=rt2;
	
	return rt1;
}


struct node* Insert(struct node* rt,int v,struct node* prnt)
{
	if(rt==NULL)
	{
		struct node* temp=(struct node*)malloc(sizeof(struct node));
		temp->data=v;
		temp->right=temp->left=NULL;
		temp->parent=prnt;
		temp->height=1;
		return temp;
	}
	
	if(rt->data<v)
	rt->right=Insert(rt->right,v,rt);
	else if(rt->data>v)
	rt->left=Insert(rt->left,v,rt);
	else
	return rt;

	getHeight(rt);

	if(!Balanced(rt))
	{
		if(rt->left!=NULL && rt->left->data>v)
		rt=rotate_right(rt->left,rt);
		else if(rt->right!=NULL && rt->right->data<v)
		rt=rotate_left(rt->right,rt);
		else if(rt->left!=NULL && rt->left->data<v)
		{
			rt->left=rotate_left(rt->left->right,rt->left);
			rt=rotate_right(rt->left,rt);
		}
		else if(rt->right!=NULL && rt->right->data>v)
		{
			rt->right=(rt->right->left,rt->right);
			rt=rotate_left(rt->right,rt);
		}
		rebalance(root);
	}
	return rt;
}

void preorder(struct node* rt)
{
	if(rt==NULL)
	return;
	
	cout<<rt->data<<" "<<rt->height<<"\n";
	preorder(rt->left);
	preorder(rt->right);
}


struct node* deletenode(struct node* rt,int d)
{
	struct node* tmp=rt;
	if(rt==NULL)
	return rt;
	else if(d<rt->data)
	rt->left=deletenode(rt->left,d);
	else if(d>rt->data)
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
			tmp->parent->right=tmp->left;
			if(tmp->left!=NULL)
			tmp->left->parent=tmp->parent;
		}
		else if(tmp->right!=NULL)
		{
			tmp=tmp->right;
			while(tmp->left!=NULL)
			{
				tmp=tmp->left;
			}
			if(tmp!=rt->right)
			tmp->parent->left=tmp->right;
			if(tmp->right!=NULL)
			tmp->right->parent=tmp->parent;
		}
		else
		return NULL;
		if(tmp!=rt->left)
		tmp->left=rt->left;
		if(tmp!=rt->right)
		tmp->right=rt->right;
		tmp->parent=rt->parent;
	}
	
	getHeight(tmp);

	if(!Balanced(tmp))
	{
		if(tmp->left!=NULL && tmp->left->data>d)
		tmp=rotate_right(tmp->left,tmp);
		else if(tmp->right!=NULL && tmp->right->data<d)
		tmp=rotate_left(tmp->right,tmp);
		else if(tmp->left!=NULL && tmp->left->data<d)
		{
			tmp->left=rotate_left(tmp->left->right,tmp->left);
			tmp=rotate_right(tmp->left,tmp);
		}
		else if(tmp->right!=NULL && tmp->right->data>d)
		{
			tmp->right=(tmp->right->left,tmp->right);
			tmp=rotate_left(tmp->right,rt);
		}
		rebalance(root);
	}
	
	return tmp;
}

int main()
{
	int v,c;
	
	do
	{
		cout<<"Enter value to insert : ";
		cin>>v;
		root=Insert(root,v,root);
		rebalance(root);
		preorder(root);
		cout<<endl;
		cout<<"Enter 0 to exit : ";
		cin>>c;
	}
	while(c);
	
	do
	{
		cout<<"Enter the element to delete : ";
		cin>>v;
		root=deletenode(root,v);
		rebalance(root);
		preorder(root);
		cout<<endl;
		cout<<"Enter 0 to exit : ";
		cin>>c;
	}
	while(c);
}
