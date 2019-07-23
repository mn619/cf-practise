#include <bits/stdc++.h>
#define ll long long int
#define ld long double
#define mp make_pair
#define pi pair<int,int>
#define pl pair<long long int,long long int>
#define pb push_back
#define fi first
#define se second
#define sz(a) (a).size()
#define MAXN 200001
using namespace std;

vector <int> adj[MAXN];
ll a[MAXN], n, sts[MAXN] = {0}, par[MAXN], dp[MAXN] = {0}, ans = -1;

void dfs (int x, int p)
{
	par[x] = p;
	sts[x] = a[x];
	for (int i=0; i<adj[x].size(); ++i)
		if (adj[x][i] != p)
		{
			dfs(adj[x][i], x);
			dp[x] += dp[adj[x][i]] + sts[adj[x][i]];
			sts[x] += sts[adj[x][i]];
		}
}

void dfs1 (int i, int p)
{
	if (i != 1) dp[i] += dp[par[i]] - dp[i] - sts[i] + sts[1] - sts[i];
	ans = max(ans, dp[i]);
	for (int j=0; j<adj[i].size(); ++j)
		if (adj[i][j] != p)
			dfs1(adj[i][j], i);
}

int main ()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	for (int i=1; i<=n; ++i)
		cin >> a[i];
	for (int i=0, u, v; i<n-1; ++i)
	{
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	dfs(1, 0);
	dfs1(1, 0);
	cout << ans << endl;
	return 0;
}