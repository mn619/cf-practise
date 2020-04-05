#include<bits/stdc++.h>
#define int long long
#define maxn 300000
#define inf 10000000000
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); //freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
using namespace std;

int n, q, mxchild[maxn + 1], ans[maxn + 1], sz[maxn + 1], p[maxn + 1];
vector <int> v[maxn + 1];

void dfs(int node){

	sz[node] = 1;
	if(v[node].size() == 0){
		ans[node] = node;
		return;
	}

	for(auto x: v[node]){
		dfs(x);
		sz[node] += sz[x];
	}
	for(auto x: v[node]){
		if(sz[x] > sz[mxchild[node]]){
			mxchild[node] = x;
		}
	}

	ans[node] = ans[mxchild[node]];

	while(max(sz[mxchild[ans[node]]], sz[node] - sz[ans[node]])*2 > sz[node]){
		ans[node] = p[ans[node]];
		assert(node != 0);
	}
}

signed main(){
	FILEIO
	cin>>n>>q;
	
	for(int i = 2; i <= n; i++){
		int par;
		cin>>par;
		p[i] = par;

		v[par].push_back(i);
	}	

	dfs(1);

	while(q--){
		int v;
		cin>>v;
		cout<<ans[v]<<'\n';
	}
}
