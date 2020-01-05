#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
#define maxn 200000
#define logN 18

using namespace std;

int n, m, len_down[maxn], len_up[maxn], sz[maxn], level[maxn], dp[maxn][logN];
vector <int> v[maxn]; 

void dfs(int node, int par){
	len_down[node] = 0;
	sz[node] = 1;
	level[node] = level[par] + 1;
	dp[node][0] = par;
	fr(i, 1, logN) dp[node][i] = dp[dp[node][i - 1]][i - 1];

	for(auto x: v[node]){
		if(x == par) continue;
		dfs(x, node);
		len_down[node] += len_down[x] + sz[x];
		sz[node] += sz[x];
	}
}

void dfs2(int node, int par){
	if(node != 1)len_up[node] = len_up[par] + n - sz[node] + len_down[par] - len_down[node] - sz[node];
	else len_up[node] = 0;

	for(auto x: v[node]){
		if(x == par) continue;
		dfs2(x, node);
	}
}

int lca(int node1, int node2)
{
	if(level[node1] < level[node2]) swap(node1, node2);

	int d = level[node1] - level[node2];

	fr(i,0,logN)
		if(d&(1<<i)) node1 = dp[node1][i];
	
	if(node1 == node2) return node1;

	for(int i = logN - 1; i>=0; i--)
	{
		if(dp[node1][i] != dp[node2][i])
		{
			node1 = dp[node1][i], node2 = dp[node2][i];
		}
	}
	return dp[node1][0];
}

int h_above(int node, int h){
	for(int i = logN - 1; i >=0 ; i--){
		if(h&(1<<i)) node = dp[node][i];
	}
	return node;
}

int dist(int a, int b){
	return level[a] + level[b] - 2*level[lca(a, b)];
}

signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

 	cout<<setprecision(15)<<fixed;
 	cin>>n>>m;

 	fr(i, 1, n){
 		int a, b;
 		cin>>a>>b;
 		v[a].pb(b);
 		v[b].pb(a);
 	}

 	dfs(1, 1);
 	dfs2(1, 1);

 	while(m--){
 		int a, b;
 		cin>>a>>b;
 		if(level[a] > level[b]) swap(a, b);
 		int x = lca(a, b);
 		if(x != a and x != b){
 			double ans = 1.0*(len_down[a]*sz[b] + len_down[b]*sz[a])/(sz[a]*sz[b]) + dist(a, b) + 1;
 			cout<<ans<<'\n';
 		}
 		else{
 			int c = h_above(b, level[b] - level[a] - 1);
 			double ans = 1.0*((len_down[a] - len_down[c] - sz[c] + len_up[a])*sz[b] + len_down[b]*(n - sz[c]))/(sz[b]*(n - sz[c])) + dist(a, b) + 1;
 			cout<<ans<<'\n';
 		}
 	}
}