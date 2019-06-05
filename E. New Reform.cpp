#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);

using namespace std;


vector <int> v[100001];
bool vis[100001];

int dfs(int node, int parent){
	if(vis[node]) return 1;
	vis[node] = 1;

	bool ok = 0;
	for(auto x: v[node]){
		if(x == parent) continue;
		ok |= dfs(x, node);
	}	
	return ok;
}

signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

 	int n, m;
 	cin>>n>>m;


 	fr(i, 1, m + 1){
 		int a, b;
 		cin>>a>>b;
 		v[a].pb(b);
 		v[b].pb(a);
 	}


 	int ans= 0;
 	fr(i, 1, n + 1){
 		if(!vis[i]) ans += 1 - dfs(i, 0);
 	}

 	cout<<ans;
}
