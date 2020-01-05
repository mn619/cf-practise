#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define inf 1000000000000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
#define maxn 1000000
#define pii pair<int, int> 

using namespace std;
int n,m,source,end;
vector <int> v[maxn], vrev[maxn];
priority_queue <pair<int,int> > pq;
int s[maxn], t[maxn], ans[maxn], p, q;
bool vis[maxn]={0};
int parent[maxn]={0};
map <pair<int,int> ,int> w, wrev;
map<pair<pii, int>, int> cnt;
pair<pii, int> ed[maxn];

void dij(int source)
{
	pq.push({0,source});
	for(int i = 1; i <= n; i++)s[i] = inf, vis[i] = 0;
	int cnt=1;
	s[source]=0;

	while(!pq.empty())
	{
		int u = pq.top().second;
		pq.pop();
		if(vis[u])continue;
		vis[u]=1;
		
		for(auto x: v[u])
		{	 
			if(s[x] > s[u] + w[{u,x}] && !vis[x])
			{
				s[x] = s[u] + w[{u, x}];
				pq.push({-s[u] - w[{u, x}], x});
				parent[x] = u;
			}
		}
		
	}
}


void dijrev(int source)
{
	pq.push({0,source});
	for(int i=1;i<=n;i++)t[i] = inf, vis[i] = 0;
	int cnt = 1;
	t[source] = 0;

	while(!pq.empty())
	{
		int u = pq.top().second;
		pq.pop();
		if(vis[u])continue;
		vis[u] = 1;
		
		for(auto x: vrev[u])
		{	 
			if(t[x] > t[u] + wrev[{u,x}] && !vis[x])
			{
				t[x] = t[u] + wrev[{u, x}];
				pq.push({-t[u] - wrev[{u, x}], x});
				parent[x] = u;
			}
		}	
	}
}

void compute(){
	vector <pair<pii, int>> v;
	fr(i, 1, m + 1) ans[i] = 1;
	int d = s[q];

	fr(i, 1, m + 1){
		int a = ed[i].first.first, b = ed[i].first.second, l = ed[i].second;
		if(s[a] + l + t[b] != d) continue;
		v.pb({{s[a], s[b]}, i});
	}

	sort(v.begin(), v.end());
	int rmx = 0;

	fr(i, 0, v.size()){
		if(i > 0){
			if(v[i - 1].first.second > v[i].first.first){
				ans[v[i - 1].second] = ans[v[i].second] = 0;
			}
		}
		if(v[i].first.first < rmx) ans[v[i].second] = 0;
		rmx = max(rmx, v[i].first.second);
	}
}

signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

 	cin>>n>>m>>p>>q;

 	fr(i, 1, m + 1){
 		int a, b, l;
 		cin>>a>>b>>l;
 		v[a].pb(b);
 		vrev[b].pb(a);
 		if(w.count({a, b})){
 			w[{a, b}] = wrev[{b, a}] = min(l, w[{a, b}]);
 		}
 		else w[{a, b}] = wrev[{b, a}] = l;
 		ed[i] = {{a, b}, l};
 		cnt[ed[i]]++;
 	}

 	
 	dij(p);
 	dijrev(q);

 	int d = s[q];
 	
 	compute();

 	fr(i, 1, m + 1){
 		int a = ed[i].first.first, b = ed[i].first.second, l = ed[i].second;
 		if(s[a] + l + t[b] != d) continue;
 	}

 	fr(i, 1, m + 1){
 		int a = ed[i].first.first, b = ed[i].first.second, l = ed[i].second;
 		int d1 = s[a] + t[b] + l;
 		if(d1 == d and cnt[ed[i]] == 1 and ans[i]){
 			cout<<"YES\n";
 		}
 		else if(d1 - d + 1 > 0 and l > d1 - d + 1){
 			cout<<"CAN "<<d1 - d + 1<<'\n';
 		}
 		else cout<<"NO\n";
 	}

}