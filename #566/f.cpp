#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
#define pii pair<int, int>

using namespace std;

int n, m, low[300001], tin[300001], timer = 0, ans = 0, mx[300001];
bool vis[300001];
vector<int> v[300001];

void dfs(int node, int p = -1){
	vis[node] = 1;
	tin[node] = low[node] = ++timer;
	int max1 = 0, max2 = 0;

	for(auto x: v[node]){
		if(x == p) continue;
		if(vis[x]){
			low[node] = min(low[x], low[node]);
		}
		else {
			dfs(x, node);
			low[node] = min(low[x], low[node]);
			int len = mx[x];
			if(low[x] > tin[node]) len++;

			if(len > max1){
				max2 = max1;
				max1 = len;
			}
			else if(len > max2) max2 = len;
			ans = max(max1 + max2, ans);
		}
	}
	mx[node] = max1;
}


signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

 	cin>>n>>m;

 	fr(i, 1, m + 1){
 		int a, b;
 		cin>>a>>b;
 		v[a].pb(b);
 		v[b].pb(a);
 	}

 	dfs(1);

 	cout<<ans;
}