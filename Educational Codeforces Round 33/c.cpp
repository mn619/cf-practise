#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define inf 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);

using namespace std;

int n, m, c[100001], cost = inf;
vector<int> v[100001];
bool vis[100001];


void dfs(int node){
	vis[node] = 1;
	cost = min(cost, c[node]);

	for(auto x: v[node]){
		if(!vis[x]) dfs(x);
	}
}
signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

 	cin>>n>>m;
 	fr(i, 1, n + 1) cin>>c[i];

 	fr(i, 1, m + 1){
 		int x, y;
 		cin>>x>>y;
 		v[x].pb(y);
 		v[y].pb(x);
 	}

 	int ans = 0;
 	fr(i, 1, n + 1){
 		if(!vis[i]){
 			cost = inf;
 			dfs(i);
 			ans += cost;
 		}
 	}
 	cout<<ans;
}