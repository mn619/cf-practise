#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;
typedef long long ll;

ll n,m,s;
ll in[100001];
vector<vector<ll> >adj;
vector<vector<ll> >nadj;
bool visit[100001];

void DFS(ll x){
	visit[x] = 1;
	for (auto nx:adj[x]){
		if (visit[nx]) continue;
		DFS(nx);
	}
	
}

ll cr_sub(ll x){
	visit[x] = 1;
	if (adj[x].size() == 0) return 1;
	ll ret = 0;
	for (auto nx:adj[x]){
		if (visit[nx]) continue;
		ret += cr_sub(nx);
	}
	return 1 + ret;
}



bool comp(ll x,ll y){
	return in[x] > in[y];
}
ll sub[100001];
int main(){
	cin>>n>>m>>s;
	adj.resize(n+1);
	nadj.resize(n+1);
	for (int i=1;i<=m;i++){
		ll x,y;
		cin>>x>>y;
		adj[x].push_back(y);
	}
	for (int i=1;i<=n;i++){
		memset(visit,0,sizeof visit);
		sub[i] = cr_sub(i) - 1;
	}
	memset(visit,0,sizeof visit);
	DFS(s);
	ll ans = 0;
	while(1){
		ll idx = -1;
		ll val = -1;
		for (int i=1;i<=n;i++){
			if (visit[i]) continue;
			if (sub[i] > val){
				val = sub[i];
				idx = i;
			}
		}
		if (idx == -1) break;
		ans++;
		DFS(idx);
	}
	cout<<ans<<endl;
}
