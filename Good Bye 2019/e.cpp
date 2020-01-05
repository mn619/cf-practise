#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
#define maxn 200000

using namespace std;

int n, x[1001], y[1001];
bool ans[1001], vis[1001];
int dist(int a, int b){
	return (x[a] - x[b])*(x[a] - x[b]) + (y[a] - y[b])*(y[a] - y[b]);
}
vector <int> v[1001];

void dfs(int node, int clr){
	ans[node] = clr;
	vis[node] = 1;
	for(auto x: v[node]){
		if(vis[x]){
			// assert(ans[x] != clr);
			continue;
		}
		dfs(x, !clr);
	}
}

signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

 	cin>>n;
 	fr(i, 1, n + 1){
 		cin>>x[i]>>y[i];
 	}

 	vector <pair<int, pair<int, int>>> p;
 	fr(i, 1, n + 1){
 		fr(j, i + 1, n + 1){
 			p.pb({dist(i, j), {i, j}});
 		}
 	}
 	if(n == 2){
 		cout<<"1\n1\n";
 		return 0;
 	}

 	int l = p.size();
 	sort(p.begin(), p.end());

 	fr(i, 0, p.size()){
 		bool ok = 0;
 		cout<<p[i].first<<' '<<p[i].second.first<<" "<<p[i].second.second<<'\n';

 		if(i > 0)
 		if(p[i].first == p[i - 1].first){
 			int x = p[i].second.first, y = p[i].second.second;
 			v[x].pb(y);
 			v[y].pb(x);
 			ok = 1;
 		}

 		if(i < l - 1)
 		if(p[i].first == p[i + 1].first and !ok){
 			int x = p[i].second.first, y = p[i].second.second;
 			v[x].pb(y);
 			v[y].pb(x);
 			ok = 1;
 		}
 	}

 	fr(i, 1, n + 1){
 		if(!vis[i]) dfs(i, 0);
 	}

 	vector <int> ANS;
 	fr(i, 1, n + 1){
 		if(!ans[i]) ANS.pb(i);
 	}

 	if(ANS.size() == n){
 		return cout<<"1\n1\n", 0;
 	}

 	cout<<ANS.size()<<'\n';
 	for(auto x: ANS) cout<<x<<" ";
}