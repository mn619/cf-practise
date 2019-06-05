#include<bits/stdc++.h>
#define ll long long int

using namespace std;
struct node
{
	int data;
	node *lchild,*rchild;
};

class bt
{
	public:
		node *root;
		bt(){root=NULL;}
		
		void addNode(int n)
		{
			node *temp=new node;
			if(root==NULL){root=temp; root->data=n; root->lchild=NULL; root->rchild=NULL;}
			
			node *x=root;
			while(1)
			{
				if(n<=x->data)
				{
					if(x->lchild==NULL)
					{
						x->lchild=temp; 
						temp->data=n; 
						temp->lchild=NULL; 
						temp->rchild=NULL; 
						break;
					}
					else x=x->lchild;
				}
				
				else
				{
					if(x->rchild==NULL)
					{
						x->rchild=temp; 
						temp->data=n; 
						temp->lchild=NULL; 
						temp->rchild=NULL;
						break;
					}
					else x=x->rchild;
				}
			}
		}
		bool searchNode(int n)
		{
			node *x=root;
			while(1)
			{
				if(n==x->data)return 1;
				
				if(n<x->data)
				{	
					if(x->lchild==NULL) return 0;
					x=x->lchild; continue;
				}
				
				else
				{
					if(x->rchild==NULL) return 1;
					x=x->rchild; continue;
				}
							
			}
		}
};

int main()
{
	bt aman;
	int n,k;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>k;
		aman.addNode(k);
	}
	
	cout<<"\nenter m\n";
	int m;
	cin>>m;
	
	for(int i=1;i<=m;i++)
	{
		cin>>k;
		if(aman.searchNode(k)) cout<<"Yes it exists\n";
		else cout<<"It do not exist\n";
	}
}

