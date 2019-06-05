#include<bits/stdc++.h>
#define ll long long int
#define pb push_back


//stack <int> s;
using namespace std;
int n;
vector <int> v[100001];
int visited[100001],c[100001];
int ans=-1;
void read()
{
	cin>>n;
	int x,y;
	for(int i=0;i<n-1;i++)
	{
		cin>>x>>y;
		v[x].pb(y);
		v[y].pb(x);
	}
	for(int i=0;i<n;i++)visited[i]=0;
}

int solve(int node)
{
	//s.push(node);
	visited[node]=1;
	//if(v[node].size()==1&&node!=1) return 1;
	
	c[node]=1;
	for(int i=0;i<v[node].size();i++)
	{
		if(!visited[v[node][i]])
		{
			c[node]+=solve(v[node][i]);
		}
		if(c[node]%2==0){c[node]=0;}
	}
	//cout<<node<<"\t"<<c[node]<<"\n";
	return c[node];
}
void solve()
{
	if(n%2)ans=-1;
	
	else
	{
		solve(1);
		for(int i=1;i<=n;i++)
		{
			if(c[i]%2==0)ans++;
		}
	}
	
	
}


int main()
{
 	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	read();
	solve();
	cout<<ans;
}


