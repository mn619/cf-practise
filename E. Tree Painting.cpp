#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
#define maxn 200000

using namespace std;

int n, sz[maxn + 1], dp[maxn + 1], ans = 0;
vector<int> v[maxn +1];

void dfs1(int node, int par){
	sz[node] = 1;
	for(auto x: v[node]){
		if(x == par) continue;
		dfs1(x, node);
		sz[node] += sz[x];
	}
}

void dfs2(int node, int par){
	dp[node] += sz[node];
	for(auto x: v[node]){
		if(x == par) continue;
		dfs2(x, node);
		dp[node] += dp[x];
	}
}

void dfs3(int node, int par){
	if(par == 0) ans = dp[node];
	else ans = max(ans, dp[par] + n - 2*sz[node]);
	if(par != 0) dp[node] = dp[par] + n - 2*sz[node];

	for(auto x: v[node]){
		if(x == par) continue;
		dfs3(x, node);
	}
}

signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

 	cin>>n;

 	fr(i, 1, n){
 		int a, b;
 		cin>>a>>b;
 		v[a].pb(b);
 		v[b].pb(a);
 	}


 	dfs1(1, 0);
 	dfs2(1, 0);
	dfs3(1, 0); 	

	cout<<ans;
}