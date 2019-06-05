#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define inf 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);

using namespace std;

int n, q, m, p[100001], sz[100001], logN = 20, dp[100001][21], level[100001];
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

void read()
{
	cin>>n>>q;
	fr(i,2,n + 1)
	{
		int p;
		cin>>p;

		v[i].pb(p);
		v[p].pb(i);
	}

	level[1] = 0;
	dfs0(1,1);
	preprocess();
	dfs(1,1);
}

int dist(int x, int y)
{
	return level[x] + level[y] - 2*level[lca(x,y)];
}


void solve()
{
	while(q--){
		int a, b, c;
		cin>>a>>b>>c;

		if(a == b){
			cout<<dist(c , a) + 1<<'\n';
		}
		else if(a == c){
			cout<<dist(a, b) + 1<<'\n';
		}
		else if(b == c){
			cout<<dist(a, b) + 1<<'\n';

		}
		else{
			int l = lca(lca(a, b), c);
			int ans = 0;
			
			if(lca(b, c) != l){
				ans = dist(lca(b, c), a) + 1;
			}
			else{
				ans = max(ans, min(dist(lca(a, b), a), dist(lca(a, c), a)) + 1);
			}
			if(lca(a, c) != l){
				ans = max(ans, dist(lca(a, c), b) + 1);
			}
			else{
				ans = max(ans, min(dist(lca(a, b), b), dist(lca(b, c), b)) + 1);
			}

			if(lca(b, c) != l){
				ans = max(ans, dist(lca(b, a), c) + 1);
				cout<<ans<<'\n';
			}
			else{
				ans = max(ans, min(dist(lca(c, b), c), dist(lca(a, c), c)) + 1);
			}
			
			cout<<ans<<'\n';
		}
	}
}

signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

 	read();
 	solve();
}