#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define inf 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);

using namespace std;

int n, m, p[100001], sz[100001], logN = 20, dp[100001][21], ans[100001], level[100001];
bool vis[100001] = {0};

vector <int> v[100001];

void dfs0(int node, int parent)
{
	for(auto x: v[node])
	{
		if(x == parent) continue;
		level[x] = level[node] + 1;
		dp[x][0] = node;
		dfs0(x, node);
	}
}

void dfs(int node, int parent)
{
	sz[node] = 1;
	fr(i,0,v[node].size())
	{
		int x = v[node][i];
		if(x == parent || vis[x]) continue;
		dfs(x, node);
		sz[node] += sz[x];
	}
}

void preprocess()
{
	dp[1][0] = 1;
	fr(j,1,logN)
	{
		fr(i,1,n + 1)
		{
			dp[i][j] = dp[dp[i][j - 1]][j - 1];
		}
	}
}

int lca(int node1, int node2)
{
	if(level[node1] < level[node2]) swap(node1, node2);

	int d = level[node1] - level[node2];

	fr(i,0,logN + 1)
		if(d&(1<<i)) node1 = dp[node1][i];
	
	if(node1 == node2) return node1;

	for(int i = logN; i>=0; i--)
	{
		if(dp[node1][i] != dp[node2][i])
		{
			node1 = dp[node1][i], node2 = dp[node2][i];
		}
	}
	return dp[node1][0];
}


void decompose(int node, int parent, int las, int cursz)
{
	for(auto x: v[node])
	{
		if(vis[x] || x == las) continue;
		if(sz[x] > cursz)
		{
			decompose(x, parent, node, cursz);
			return;
		}
	}

	if(parent != -1) p[node] = parent;
	else p[node] = node;

	vis[node] = 1; 
	for(auto x: v[node])
	{
		dfs(x, node);
	}

	fr(i,0,v[node].size())
	{
		int x = v[node][i];
		if(vis[x] == 1) continue;
		decompose(x, node, node, sz[x]/2);
	}
}

void read()
{
	cin>>n>>m;
	fr(i,1,n)
	{
		int a,b;
		cin>>a>>b;
		v[a].pb(b);
		v[b].pb(a);
	}

	level[1] = 0;
	dfs0(1,1);
	preprocess();
	dfs(1,1);
	decompose(1,-1, 1, n/2);
}

int dist(int x, int y)
{
	return level[x] + level[y] - 2*level[lca(x,y)];
}

void update(int node)
{
	ans[node] = 0;
	int x = node;
	//cout<<"HELLO\n";
	while(1)
	{
		ans[x] = min(ans[x], dist(node, x));
		//cout<<x<<" "<<dist(node, x)<<" "<<ans[x]<<" "<<min(ans[x], dist(node, x))<<"\n";
		if(x == p[x]) break;
		x = p[x];
	}
}

int query(int node)
{
	int x = node;
	int ret = inf;

	while(1)
	{
		ret = min(ret, ans[x] + dist(x, node));
		if(x == p[x]) break;
		x = p[x];
	}

	return ret;
}

void solve()
{
	update(1);

	while(m--)
	{
		int t, x;
		cin>>t>>x;
		if(t == 1)
			update(x);
		else cout<<query(x)<<'\n';
	}
}

signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

 	read();
 	fr(i, 1, n + 1) ans[i] = inf;
 	solve();
}