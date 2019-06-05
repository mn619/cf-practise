#include <bits/stdc++.h>
#define pb push_back
#define MAXN 100001

using namespace std;

vector<int> tree[MAXN];

int main()
{
	int n;
	cin>>n;
	
	for(int i=0;i<n-1;i++)
	{
		int x,y;
		cin>>x>>y;
		tree[x].pb(y);
		tree[y].pb(x);
	}
	int count=0;
	for(int i=1;i<=n;i++)
	{
		if(tree[i].size()>2)count++;
		if(count>1)break;
	}
	
	if(count>1)cout<<"No\n";
	
	else
	{
		cout<<"Yes\n";
		int cent;
		for(int i=1;i<=n;i++)
		{
			if(tree[i].size()>2){cent=i; break;}
		}
		cout<<tree[cent].size()<<"\n";
		
		
		for(int i=0;i<tree[cent].size();i++)
		{
			int node=tree[cent][i],tempnode=cent;
			
			cout<<cent<<" ";
			while(tree[node].size()!=1)
			{
				if(tree[node][0]!=tempnode){tempnode=node; node=tree[node][0];}
				else tempnode=node,node=tree[node][1];
			}
			
			cout<<node<<"\n";
		}
	}
}
