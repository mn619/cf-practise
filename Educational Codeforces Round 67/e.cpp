#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
#define maxn 200000

using namespace std;

int n, dp[maxn + 1], sz[maxn + 1];
vector<int> v[maxn + 1];

void dfs(int node, int par){

	if(v[node].size() == 1 and v[node][0] == par){
		dp[node] = 1;
		sz[node] = 1;
		return;
	}
	vector<int> val;
	int sm = 0, mx = 0;

	for(auto x: v[node]){
		if(x == par) continue;
		dfs(x, node);
		sz[node] += sz[x];
		sm += dp[x];
		if(dp[mx] > dp[x]){
			mx = x;
		}
	}

	sz[node]++;
	dp[node] = sz[node]*(sz[node] + 1)/2 - (sz[node] - sz[mx] + 1)*(sz[node] - sz[mx])/2 + sm - dp[mx];
	
	cout<<node<<" "<<dp[node]<<" "<<sz[node]<<' '<<sm<<" "<<dp[mx]<<' '<<sz[mx]<<'\n';
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


 	dfs(1, 1);
 	cout<<dp[1]<<'\n';
}