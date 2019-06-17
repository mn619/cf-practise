#include<bits/stdc++.h>
#define ll long long int
#define pb push_back

using namespace std;

struct node
{
	int win,loose;
	node * n[26];

};

node * trie;

void makenode(node * x)
{
	for(int  i=0;i<26;i++) x->n[i]=NULL;
} 

void instrie(string s)
{
	node * temp=trie;
	for(int i=0;i<s.size();i++)
	{
		if(temp->n[s[i]-'a']!=NULL)
		{
			temp=temp->n[s[i]-'a'];
		}
		else 
		{
			temp->n[s[i]-'a']=new node;
			makenode(temp->n[s[i]-'a']);
			temp=temp->n[s[i]-'a'];
		}
	}
}

void win(node * x)
{
	
	bool b=0;
	for(int i=0;i<26;i++)
	{
		if(x->n[i]!=NULL)
		{
			b=1;
			win(x->n[i]);
		}
	}
	
	if(!b)
	{
		x->win=0;  return;
	}
	
	else
	{
		b=0;
		for(int i=0;i<26;i++)
		{
			if(x->n[i]!=NULL && x->n[i]->win==0)
			{
				x->win=1; b=1; return;
			}
		}
		
		if(!b)x->win=0;
		return;
	}
}

bool loose(node * x)
{
	bool b=0;
	for(int i=0;i<26;i++)
	{
		if(x->n[i]!=NULL)
		{
			b=1;
			loose(x->n[i]);
		}
	}
	if(!b)
	{
		x->loose=1;
		return 1;
	}
	for(int i=0;i<26;i++)
	{
		if(x->n[i] && x->n[i]->loose==false)
		{
			x->loose=1;
			return 1;
		}
	}
	x->loose=0; return 0;
	
}

int main()
{	
	trie=new node;
	makenode(trie);
	int n,k;
	cin>>n>>k;
	string s;
	
	for(int i=0;i<n;i++)
	{
		cin>>s;
		instrie(s);
	}
	
	win(trie);
	loose(trie);
	/*
		cout<<"\n\n";
	node * temp=trie;
	while(1)
	{
		bool b=0;
		for(int i=0;i<26;i++)
		{
			if(temp->n[i]!=NULL)
			{
				temp=temp->n[i];
				cout<<i<<endl;
				b=1; break;
			}
		}
		if(!b)break;
	}
	cout<<"end\n\n";
	*/
	bool w=trie->win;
	bool l=trie->loose;
	/*
	
	for(int i=0;i<26;i++)
	{
		if(trie->n[i] && trie->n[i]->win)
		{
			cout<<"win in "<<i<<"\t"<<trie->n[i]->win<<endl;
			w=true;
		}
		if(trie->n[i] && trie->n[i]->loose)
		{
			cout<<"loose in "<<i<<endl;
			l=true;
		}
	}*/
	
	//cout<<"\n"<<trie->n[0]->win<<" hello\n";
	//cout<<"\n"<<w<<endl<<l<<endl;
	
	
	if(w==0)cout<<"Second\n";
	else if(w==1 && l==0)
	{
		if(k%2)cout<<"First\n";
		else cout<<"Second\n";		
	}
	
	else if(w==1 && l==1)
	{
		cout<<"First\n";
	}
	
}

