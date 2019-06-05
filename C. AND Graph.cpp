#include<bits/stdc++.h>
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define int long long
#define mp make_pair
#define mod 1000000007
#define inf 100000000

using namespace std;

struct node{
	node *b[2];
	bool isend;
};

void createnode(node * n)
{
	n->b[0]=NULL;
	n->b[1]=NULL;
	n->isend=false;
}

int n,m, a[5000000],g[5000000];
node * root;

void createtrie(int a)
{
	node *temp=root;
	while(a!=0)
	{
		if(temp->b[a%2]==NULL){temp->b[a%2]=new node; createnode(temp->b[a%2]);}
		temp=temp->b[a%2];
		a/=2;
	}
	temp->isend=true;
}

void solve(int a)
{
	node * temp= root;
	int num=0,j=0;
	cout<<a<<"\t"<<g[a]<<"\t";
	int aa=a;
	
	while(aa!=0)
	{
		if(aa%2==0)
			{if(temp->b[1]!=NULL)temp=temp->b[1];}
		else if(temp->b[0]!=NULL)temp=temp->b[0];
		else {if(g[a]>g[num])g[a]=g[num]; break;}
		if(temp->isend){if(g[a]>g[num])g[a]=g[num];}
		if(aa%2==0)num+=pow(2,j);j++;
		aa/=2;
	}
	cout<<g[a]<<"\n";
}
signed main()
{
 	//ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	root =new node;
	createnode(root);
	cin>>n>>m;

	for(int i=0;i<5000000;i++)g[i]=inf;

	for(int i=1;i<=m;i++)
	{
		cin>>a[i];
		createtrie(a[i]);
		g[a[i]]=a[i];	
	}
	sort(a+1,a+m+1);

	for(int i=1;i<=m;i++)
		solve(a[i]);
	
	for(int i=1;i<21;i++)cout<<g[i]<<" ";

	sort(g+1,g+m+1);
	int ans=0;
	for(int i=1;i<5000000;i++)if(g[i]!=g[i-1] && g[i]!=inf)ans++;
	cout<<"\n"<<ans;
}

/*
 © Copyright 			all rights reserved
     __           __      __       __    	   __	   _
    //\\         //||    //||     //\\        //||    //
   //  \\       // ||   // ||    //  \\      // ||   //
  //----\\     //  ||  //  ||   //----\\    //  ||  //
 //      \\   //   || //   ||  //      \\  //   || //
//        \\ //    ||//    || //        \\//    ||//

*/

