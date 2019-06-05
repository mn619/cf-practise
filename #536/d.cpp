#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("C:/Users/Aman/Desktop/kachda/input.txt", "r", stdin); freopen("C:/Users/Aman/Desktop/kachda/output.txt", "w", stdout);

using namespace std;
vector <int> v[100001];
map <pair<int,int>,bool> edge;

map<int,bool> mp;
vector<int> ans;
int n,m;

void dfs(int node)
{
	cout<<node<<'\n';
	if(mp.count(node) == 0)
	{
		ans.pb(node);
		mp[node] = 1;
	}
	if(ans.size() == n) return;
	
	fr(i,0,v[node].size())
	{
		dfs(v[node][i]);
		if(ans.size() == n) return;
	}
}

signed main()
{
	//FILEIO
 	FLASH
	cin>>n>>m;
	fr(i,1,m + 1)
	{
		int a,b;
		cin>>a>>b;
		if(edge.count({a,b})) continue;
		edge[{a,b}] = 1;
		v[a].pb(b);
		v[b].pb(a);
	}

	fr(i,1,n + 1)
	{
		sort(v[i].begin(), v[i].end());
	}


	dfs(1);

	fr(i,0,n) cout<<ans[i]<<" ";
}