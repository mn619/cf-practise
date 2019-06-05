#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);

using namespace std;


int n, ans[3001];
vector <int> v[3001];
bool vis[3001];
int start = -1;
queue <int> q;
set <int> s;

bool dfs(int node, int parent){

	if(vis[node] and start != -1) return 0;
	if(vis[node]) {start = node; s.insert(node); return 1;}
	vis[node] = 1;

	bool ok = 0;
	for(auto x: v[node]){
		if(x == parent) continue;
		ok = ok | dfs(x, node);
	}

	if(ok && node != start){ s.insert(node); return 1;}
	return 0;
}

signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

 	cin>>n;
 	fr(i, 1, n + 1){
 		int a, b;
 		cin>>a>>b;
 		v[a].pb(b);
 		v[b].pb(a);
 	}

 	dfs(1, 0);
 	
 	for(int i = 1; i <= n; i++){
 		if(s.find(i) == s.end()) vis[i] = 0;
 		else {vis[i] = 1; q.push(i);} 
 	}

 	while(!q.empty()){
 		int node = q.front();

 		vis[node] = 1;
 		q.pop();

 		for(auto x: v[node]){
 			if(vis[x]) continue;
 			

 			ans[x] = ans[node] + 1;
 			q.push(x);
 		}
 	}

 	fr(i, 1, n + 1) cout<<ans[i]<<" ";
}