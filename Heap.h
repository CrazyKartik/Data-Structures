#include<iostream>
#include<cstdlib>
#include<queue>
using namespace std;

struct node
{
	int v;
	int p;
	struct node* left;
	struct node* right;
	struct node* parent;	
};

struct node* root;

class Heap
{
	public:
	int xd,xp,ht,ht1,vm,count_nodes,del,del_last;
	
	Heap()
	{
		root=NULL;
		this->xd=INT_MAX;
		this->xp=INT_MAX;
		this->ht=0;
		this->vm=INT_MAX;
		this->count_nodes=0;
	}
	
	struct node* newnode(int v,int p,struct node* prnt,struct node* rt)
	{
		rt=new node;
		rt->v=v;
		rt->p=p;
		rt->parent=prnt;
		rt->left=rt->right=NULL;
		return rt;
	}
	
	struct node* swap(struct node* rt=root)
	{
		int temp,temp2;
		if(rt->left!=NULL && rt->right!=NULL)
		{
			if(rt->left->p<rt->right->p && rt->left->p<rt->p)
			{
				temp=rt->left->p;
				temp2=rt->left->v;
				rt->left->p=rt->p;
				rt->left->v=rt->v;
				rt->v=temp2;
				rt->p=temp;
			}
			else if(rt->right->p<rt->left->p && rt->right->p<rt->p)
			{
				temp=rt->right->p;
				temp2=rt->right->v;
				rt->right->p=rt->p;
				rt->right->v=rt->v;
				rt->v=temp2;
				rt->p=temp;
			}
		}
		else if(rt->left==NULL && rt->right!=NULL && rt->right->p<rt->p)
		{
			temp=rt->right->p;
			temp2=rt->right->v;
			rt->right->p=rt->p;
			rt->right->v=rt->v;
			rt->v=temp2;
			rt->p=temp;
		}
		else if(rt->right==NULL && rt->left!=NULL && rt->left->p<rt->p)
		{
			temp=rt->left->p;
			temp2=rt->left->v;
			rt->left->p=rt->p;
			rt->left->v=rt->v;
			rt->v=temp2;
			rt->p=temp;
		}
		return rt;
	}
	
	void minheapify(struct node* rt=root)
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
	
	void Insert(int v,int p)
	{
		count_nodes++;
		queue <struct node*> q;
		struct node* rt=root;
		
		if(rt==NULL)
		{
			root=newnode(v,p,rt,rt);
			return;
		}
		q.push(rt);
		while(!q.empty())
		{
			rt=q.front();
			q.pop();
			
			if(!rt->left)
			{
			rt->left=newnode(v,p,rt->left,rt);
			break;
			}
			else
			q.push(rt->left);
			
			if(!rt->right)
			{
			rt->right=newnode(v,p,rt->right,rt);
			break;
			}
			else
			q.push(rt->right);
		}
		minheapify(root);
	}
	
	void get_node(int h,struct node* rt,struct node* pr)
	{
		if(rt==NULL)
		{
			if(pr==NULL)
			return;
			if(h>=this->ht)
			{
				this->xd=pr->v;
				this->xp=pr->p;
			}
			return;
		}
	
		get_node(h+1,rt->left,rt);
		get_node(h+1,rt->right,rt);
	}
	
	struct node* remove_last(int h,struct node* rt=root)
	{
		if(rt==NULL)
		return NULL;
		if(rt->v==this->xd && h==this->ht && this->del_last==0)
		{
			this->del_last=1;
			if(rt->left!=NULL)
			return rt->left;
			return rt->right;
		}
		rt->left=remove_last(h+1,rt->left);
		rt->right=remove_last(h+1,rt->right);
		return rt;
	}
	
	void delete_node(int d,struct node* rt=root)
	{
		if(rt==NULL)
		return;
		
		if(rt->v==d)
		{
			vm=INT_MAX,xp=INT_MAX;
			this->del=1;
			get_node(0,root,root->parent);
			this->vm=xd;
			if(rt->v==vm)
			{
				this->del=0;
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
			rt->v=vm;
			rt->p=xp;
		}
		
		else if(rt->left==NULL && rt->right==NULL && rt->v==d)
		{
			this->del=1;
			if(rt->v==vm)
			this->del=0;
			
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
		
		delete_node(d,rt->left);
		delete_node(d,rt->right);
	}
	
	void Print(struct node* rt=root)
	{
		if(rt==NULL)
		return;
		cout<<rt->v<<" "<<rt->p<<endl;
		Print(rt->left);
		Print(rt->right);
	}
	
	void remove(int v)
	{
		this->ht1=0,this->ht=0;
		this->del=0,this->del_last=0;
		struct node* temp;
		temp=root;
		while(temp!=NULL)
		{
			this->ht++;
			temp=temp->left;
		}
		temp=root;
		while(temp!=NULL)
		{
			this->ht1++;
			temp=temp->right;
		}
		if(ht1>ht)
		this->ht=this->ht1;
		
		delete_node(v,root);
		if(del)
		root=remove_last(1);
		minheapify(root);
	}
	
	struct node* set_Priority(int v,int p,struct node* rt=root)
	{
		if(rt==NULL)
		return NULL;
		
		if(rt->v==v)
		{
			rt->p=p;
			return rt;
		}
		
		rt->left=set_Priority(v,p,rt->left);
		rt->right=set_Priority(v,p,rt->right);
	}
	void setP(int v,int p)
	{
		root=set_Priority(v,p);
		minheapify();
	}
	
	int top()
	{
		return root->v;
	}
	
	bool isempty()
	{
		if(root==NULL)
		return true;
		return false;
	}
	
};
