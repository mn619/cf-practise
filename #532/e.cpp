#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("C:/Users/Aman/Desktop/kachda/input.txt", "r", stdin); freopen("C:/Users/Aman/Desktop/kachda/output.txt", "w", stdout);

using namespace std;

int n, m;
int edge[100001], vis[100001] = {0}, toporder[100001] = {0};

vector <int> v[100001], g[100001];
vector <int> topo;
map <pair<pair<int, int> , pair<int, int>>, int > e;

bool cyc = 0;

void dfs(int node)
{
	if(vis[node] == 1) {cyc = 1; return;}
	if(vis[node] == 2)  return;
	vis[node] = 1;
	fr(i,0,v[node].size())
	{
		dfs(v[node][i]);
	}
	vis[node] = 2;
}

void topvis(int node)
{
	vis[node] = 1;
	fr(i,0,v[node].size())
	{
		if(vis[v[node][i]]) continue;
		topvis(v[node][i]);
	}
	topo.pb(node);
}

void reset()
{
	cyc = 0;
	fr(i,1,n + 1) {v[i].clear(); vis[i] = 0;}
}

signed main()
{
	FILEIO
 	FLASH
	cin>>n>>m;
	fr(i,1,m + 1)
	{
		int a,c,b;
		cin>>a>>b>>c;
		g[a].pb(b);
		e[{{c,i},{a,b}}] = i;
		edge[i] = c;
	}

	edge[0] = 0;

	sort(edge + 1, edge + 1 + m);

	int l = 0, r = m, ans;
	while(l <= r)
	{
		int mid = (l + r)>>1;
		int k = edge[mid];

		for(auto x: e)
			if(x.first.first.first > k) v[x.first.second.first].pb(x.first.second.second);

		fr(i,1,n + 1)
			if(vis[i] == 0) dfs(i);

		if(cyc)
			l = mid + 1;
		else ans = k, r = mid - 1;

		reset();
	}

	for(auto x: e)
		if(x.first.first.first > ans) v[x.first.second.first].pb(x.first.second.second);
	
	fr(i,1,n + 1)
		if(vis[i] == 0) topvis(i);

	reverse(topo.begin(), topo.end());

	fr(i,0,topo.size())
		toporder[topo[i]] = i + 1;

	vector <int> rev;

	for(auto edges: e)
	{
		if(edges.first.first.first <= ans)
		{
			if(toporder[edges.first.second.first] > toporder[edges.first.second.second])
			{
				rev.pb(edges.second);
			}
		}
	}

	sort(rev.begin(), rev.end());

	cout<<ans<<' '<<rev.size()<<'\n';
	fr(i,0,rev.size())
		cout<<rev[i]<<" ";
}