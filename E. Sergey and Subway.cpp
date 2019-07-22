#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
#define maxn 200000	

using namespace std;

int n, h[maxn + 1],cnt[2], sum = 0, ans = 0, sz[maxn + 1];
vector<int> v[maxn + 1];

void dfs(int node, int par, int ht){
	cnt[ht&1]++;
	sz[node] = 1;
	h[node] = ht;

	for(auto x: v[node]){
		if(x == par) continue;
		dfs(x, node, ht + 1);
		sz[node] += sz[x];
		h[node] += h[x];
	}

	ans += h[node]*(sz[node] - 1);
	ans -= sz[node]*(sz[node] - 1)*ht;
	cout<<node<<" "<<ans<<'\n';
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

 	dfs(1, 0, 1);
 	cout<<ans/2 + cnt[0]*cnt[1];
}