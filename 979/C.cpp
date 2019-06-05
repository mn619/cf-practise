#include<bits/stdc++.h>
#define ll long long int
#define pb push_back

using namespace std;

bool visited[300000+1]={0};
bool check[300000+1]={0};
ll depth[300000+1];
ll child[300000+1];

void dfs(vector <ll> v[],ll root, ll x, ll y)
{
	visited[root]=1;
	//cout<<root<<endl;
	for(int i=0;i<v[root].size();i++)
	{
		bool b=0;
		if(!visited[v[root][i]])
		{
			visited[v[root][i]]=1;
			depth[v[root][i]]=depth[root]+1;
			b=1;
			dfs(v,v[root][i],x,y);
			if(check[v[root][i]])check[root]=1;
			child[root]+=child[v[root][i]];
		}
	}
}

int main()
{
	for(int i=0;i<300000;i++)child[i]=1;
	ll n,x,y;
	cin>>n>>x>>y;
	vector <ll> v[n+1];
	ll a,b;
	check[y]=1;
	ll k;
	for(auto i:v[root])
	{
		cin>>a>>b;
		v[a].pb(b);
		v[b].pb(a);
	}
	
	depth[x]=1;
	dfs(v,x,x,y);
	//cout<<check[x]<<"\n"<<check[2]<<"\n"<<check[3]<<"\n"<<check[5]<<endl;;
	for(int i=0;i<v[x].size();i++) if(check[v[x][i]]){k=child[v[x][i]];break;}
	
	ll ans=n*(n-1)-child[y]*(n-k);
	cout<<ans;
}

