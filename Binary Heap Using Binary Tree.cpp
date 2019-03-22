/*
Basic Operations on Bianry Heap using Binary Tree
Insertion--Inserts the node in the heap and balances the heap
Deletion--removes the node and replaces it by the last node of the last level
HeapSort--Deletes the whole heap so set conditions like if input is 1 do heapsort else ask for deletion or construct 2 heaps
But the operations all work fine
*/

#include<iostream>
#include<cstdlib>
#include<queue>
using namespace std;

int xd=INT_MAX,del=0;
int ht=0,count_nodes=0;

struct node
{
	int data;
	struct node* left;
	struct node* right;
	struct node* parent;
};
struct node* root=NULL;

struct node* newnode(int v,struct node* rt,struct node* prnt)
{
	rt=(struct node*)malloc(sizeof(struct node));
	rt->data=v;
	rt->parent=prnt;
	rt->left=rt->right=NULL;
	return rt;
}

struct node* swap(struct node* rt)
{
	int temp;
	if(rt->left!=NULL && rt->right!=NULL)
	{
		if(rt->left->data<rt->right->data && rt->left->data<rt->data)
		{
			temp=rt->left->data;
			rt->left->data=rt->data;
			rt->data=temp;
		}
		else if(rt->right->data<rt->left->data && rt->right->data<rt->data)
		{
			temp=rt->right->data;
			rt->right->data=rt->data;
			rt->data=temp;
		}
	}
	else if(rt->left==NULL && rt->right!=NULL && rt->right->data<rt->data)
	{
		temp=rt->right->data;
		rt->right->data=rt->data;
		rt->data=temp;
	}
	else if(rt->right==NULL && rt->left!=NULL && rt->left->data<rt->data)
	{
		temp=rt->left->data;
		rt->left->data=rt->data;
		rt->data=temp;
	}
	return rt;
}

void minheapify(struct node* rt)
{
	if(rt==NULL ||(rt->left==NULL && rt->right==NULL))
	return;
	rt=swap(rt);
	minheapify(rt->left);
	minheapify(rt->right);
	if(rt->right!=NULL && rt->left==NULL)
	{
		rt->left=rt->right;
		rt->right=NULL;
	}
	rt=swap(rt);
	
}

void Insert(int v)
{
	count_nodes++;
	static queue <struct node*> q;
	struct node* rt=root;
	
	if(rt==NULL)
	{
		root=newnode(v,rt,rt);
		return;
	}
	q.push(rt);
	while(!q.empty())
	{
		rt=q.front();
		q.pop();
		
		if(!rt->left)
		{
		rt->left=newnode(v,rt->left,rt);
		break;
		}
		else
		q.push(rt->left);
		
		if(!rt->right)
		{
		rt->right=newnode(v,rt->right,rt);
		break;
		}
		else
		q.push(rt->right);
	}
	minheapify(root);
}

void get_node(struct node* rt,struct node* pr,int h)
{
	if(rt==NULL)
	{
		if(pr==NULL)
		return;
		if(h==ht)
		xd=pr->data;
		return;
	}

	get_node(rt->left,rt,h+1);
	get_node(rt->right,rt,h+1);
}

int del_last=0;
struct node* remove_last(struct node* rt,int h)
{
	if(rt==NULL)
	return NULL;
	get_node(root,root->parent,0);
	if(rt->data==xd && h==ht && del_last==0)
	{
		del_last=1;
		if(rt->left==NULL && rt->right==NULL)
		return NULL;
		else if(rt->left!=NULL)
		return rt->left;
		return rt->right;
	}
	rt->left=remove_last(rt->left,h+1);
	rt->right=remove_last(rt->right,h+1);
	return rt;
}

int vm;
void delete_node(struct node* rt,int d)
{
	if(rt==NULL)
	return;
	
	if(rt->data==d)
	{
		vm=INT_MAX;
		del=1;
		get_node(root,root->parent,0);
		vm=xd;
		if(rt->data==vm)
		{
			del=0;
			if(rt->parent!=NULL)
			{
				if(rt->parent->left==rt)
					rt->parent->left=NULL;
				else
					rt->parent->right=NULL;
				return;	
			}
			if(rt->left!=NULL)
			root=rt->left;
			else
			root=rt->right;
			return;
		}
		rt->data=vm;
	}
	
	
	else if(rt->left==NULL && rt->right==NULL && rt->data==d)
	{
		del=1;
		if(rt->data=vm)
		del=0;
		if(rt->parent!=NULL)
		{
			if(rt->parent->left==rt)
				rt->parent->left=NULL;
			else
				rt->parent->right=NULL;
			return;
		}
		root=NULL;
		return;
	}
	
	delete_node(rt->left,d);
	delete_node(rt->right,d);
	
}

void Print(struct node* rt)
{
	if(rt==NULL)
	return;
	cout<<rt->data<<" ";
	Print(rt->left);
	Print(rt->right);
}

void heapsort(int A[])
{
	int i=0;
	struct node* temp;
	while(root!=NULL)
	{
		ht=0;
		temp=root;
		while(temp!=NULL)
		{
			ht++;
			temp=temp->left;
		}
		
		A[i++]=root->data;
		delete_node(root,root->data);
		if(root==NULL)
		return;
		root=remove_last(root,1);
		minheapify(root);
	}
}

int main()
{
	int v,c,d;
	struct node* temp;
	do
	{
		cout<<"Enter the element to insert in heap : ";
		cin>>v;
		Insert(v);
		Print(root);
		cout<<endl;
		cout<<"Enter 0 to exit : ";
		cin>>c;
	}
	while(c);
	
	//De-Comment to run HeapSort
	/*int A[count_nodes];
	heapsort(A);
	for(int i=0; i<count_nodes; i++)
	{
		cout<<A[i]<<" ";
	}
	cout<<endl;*/
	
	do
	{
		ht=0;
		int ht1=0;
		temp=root;
		while(temp!=NULL)
		{
			ht++;
			temp=temp->left;
		}
		temp=root;
		while(temp!=NULL)
		{
			ht1++;
			temp=temp->right;
		}
		if(ht1>ht)
		ht=ht1;
		
		cout<<"Enter the element to delete from heap : ";
		cin>>d;
		del=0,del_last=0;
		
		delete_node(root,d);
		if(del)
		root=remove_last(root,1);
		minheapify(root);
		
		cout<<"Remaining Heap is : ";
		Print(root);
		cout<<endl;
		
		cout<<"Enter 0 to exit : ";
		cin>>c;
	}
	while(c);
	
	cout<<"Remaining Heap is : ";
	Print(root);
	cout<<endl;
}
