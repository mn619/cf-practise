#include<bits/stdc++.h>
#define ll long long int
using namespace std;

struct node
{
	int data;
	node *next;
	 
};

class linked_list
{
	
	public :
		node *head,*tail;
		linked_list()
		{
			head=NULL;
			tail=NULL;
		}
		add_node(int n)
		{
			node *tmp = new node;
        	tmp->data = n;
        	tmp->next = NULL;

        	if(head == NULL)
        	{
            	head = tmp;
            	tail = tmp;
        	}
        	else
        	{
            	tail->next = tmp;
            	tail = tail->next;
        	}
		}
		
		
		search_node(int b)
		{
			node *x=head;
			while(x!=tail)
			{
				if(b==x->data) {return 1;}
				x=x->next;
			}
			if(b==x->data) {return 1;}
			return 0;
		}
};



int main()
{
	linked_list a;
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int m;
		cin>>m;
		a.add_node(m);
	}
	
	for(int i=1;i<=n;i++)
	{
		int b;
		cin>>b;
		int k=a.search_node(b);
		if(k==1) cout<<"YES\n";
		if(k==0) cout<<"NO\n";
	}
}

