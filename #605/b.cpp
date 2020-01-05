#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define inf 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
#define maxn 200000

using namespace std;

int n, a[maxn + 1], ans[maxn + 1] = {0};
vector <int> v[maxn + 1];


void dfs(bool b){
	queue <int> q;
	int dist[n + 1];
	vector <bool> vis(n + 1);

	fr(i, 1, n + 1){
		if((a[i]&1) == b){
			q.push(i);
			dist[i] = 0;
		}
		else dist[i] = inf;
	}
	while(!q.empty()){
		int node = q.front();
		q.pop();
		vis[node] = 1;
		for(auto x: v[node]){
			if(!vis[x]){
				q.push(x);
				dist[x] = min(dist[x], dist[node] + 1);
			}
		}
	}


	fr(i, 1, n + 1) if((a[i]&1) != b) ans[i] = dist[i];
}


signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

 	cin>>n;
 	fr(i, 1, n + 1){
 		cin>>a[i];
 		if(i - a[i] >= 1) v[i - a[i]].pb(i);
 		if(i + a[i] <= n) v[i + a[i]].pb(i);
 	}

 	dfs(0);
 	dfs(1);

 	fr(i, 1, n + 1){
 		if(ans[i] == inf) cout<<-1<<" ";
 		else cout<<ans[i]<<" ";
 	}
}