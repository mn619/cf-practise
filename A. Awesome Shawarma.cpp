#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define inf 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); 

using namespace std;

int n, l, r, p[100001], sz[100001], logN = 20, DP[100001][21], ans, level[100001];
bool vis[100001] = {0};

vector <int> v[100001];
map <int, int> dp[100001], dp1[100001];

void dfs0(int node, int parent)
{
	for(auto x: v[node])
	{
		if(x == parent) continue;
		level[x] = level[node] + 1;
		DP[x][0] = node;
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
	DP[1][0] = 1;
	fr(j,1,logN)
	{
		fr(i,1,n + 1)
		{
			DP[i][j] = DP[DP[i][j - 1]][j - 1];
		}
	}
}

int lca(int node1, int node2)
{
	if(level[node1] < level[node2]) swap(node1, node2);

	int d = level[node1] - level[node2];

	fr(i,0,logN + 1)
		if(d&(1<<i)) node1 = DP[node1][i];
	
	if(node1 == node2) return node1;

	for(int i = logN; i>=0; i--)
	{
		if(DP[node1][i] != DP[node2][i])
		{
			node1 = DP[node1][i], node2 = DP[node2][i];
		}
	}
	return DP[node1][0];
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

int dist(int x, int y)
{
	return level[x] + level[y] - 2*level[lca(x,y)];
}

void read()
{
	cin>>n>>l>>r;
	l = n - 1 - l, r = n - 1 - r;
	swap(l,r);
	//cout<<l<<' '<<r<<'\n';
	fr(i,1,n + 1) {v[i].clear(); dp[i].clear(); dp1[i].clear(); vis[i] = 0;}
	ans = 0;

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

int sum(int i, int lf, int rt)
{
	if(lf < 0) lf = 0;
	if(rt >= dp[i].size()) rt = dp[i].size() - 1;
	if(rt < 0 || lf >= dp[i].size()) return 0;
	if(lf == 0) return dp[i][rt];
	return dp[i][rt] - dp[i][max((int)0, lf - 1)];
}

int sum1(int i, int lf, int rt)
{
	if(lf < 0) lf = 0;
	if(rt >= dp1[i].size()) rt = dp1[i].size() - 1;
	if(rt < 0 || lf >= dp1[i].size()) return 0;
	return dp1[i][rt] - dp1[i][max((int)0, lf - 1)];
}

void solve()
{
	fr(i,1,n + 1)
	{
		int x = i;
		dp[i][0] = 1;
		while(1)
		{
			if(x == p[x]) break;
			int temp = dist(p[x],i);
			dp1[x][temp]++;
			dp[p[x]][temp]++;
			x = p[x];
		}
	}

	fr(i,1,n + 1)
	{
		fr(j,1,dp[i].size()) {dp[i][j] += dp[i][j - 1];}
		fr(j,1,dp1[i].size()) dp1[i][j] += dp1[i][j - 1];
		dp1[i][0] = 0;
	}
	/*
	fr(i,1,n + 1)
	{
		for(auto x: dp[i]) cout<<x.second<<' ';
		cout<<'\n';
	}
	cout<<'\n';
	fr(i,1,n + 1)
	{
		for(auto x: dp1[i]) cout<<x.second<<' ';
		cout<<'\n';
	}
	cout<<'\n';
	cout<<sum(2,0,1)<<" is the val \n\n";
	*/
	fr(i,1,n + 1)
	{
		int x = i;
		ans += sum(i, l, r);
		//cout<<"at this stage ans = "<<ans<<'\n';
		while(1)
		{
			if(x == p[x]) break;
			int d = dist(i, p[x]);
			int l1 = l - d, r1 = r - d;
			ans += sum(p[x], l1, r1) - sum1(x, l1, r1);
			x = p[x];
		}
	}
	cout<<ans/2<<'\n';
}


signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH
 	int tests;
 	cin>>tests;

 	while(tests--)
 	{
 		read();
 		solve();
 	}
}