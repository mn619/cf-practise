#include<bits/stdc++.h>
#define start_routine cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false); int begtime = clock();
#define end_routine int endtime = clock(); cerr << endl << "Time elapsed: " << (endtime - begtime)*1000/CLOCKS_PER_SEC << " ms"; return 0;
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define int long long
#define fr(i,a,b) for(i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
using namespace std;
vector <int> v[300001];
int n, w[300001], dp[300001];
int ans = 0;
map < pair<int, int> , int> mp;

void dfs(int node, int parent)
{
	if(v[node].size() == 1 && v[node][0] == parent)
	{
		ans = max(ans, w[node]);
		dp[node] = w[node];
		return;
	}
	vector <int> val;
	int i;
	int temp = -mod;
	fr(i,0,v[node].size())
	{
		if(v[node][i] == parent) continue;
		dfs(v[node][i], node);
		val.pb(dp[v[node][i]] - mp[{node,v[node][i]}]);
		temp = max(temp , dp[v[node][i]] + w[node] - mp[{node, v[node][i]}]);
	}
	dp[node] = max(w[node], temp);
	ans = max(ans , temp);
	if(val.size() >= 2)
	{
		sort(val.begin(), val.end());
		reverse(val.begin(), val.end());
		ans = max(ans, val[0] + val[1] + w[node]);
	}

}
signed main()
{
	//FILEIO
 	//start_routine
	
	cin>>n;	
	int i;
	fr(i,1,n +1) cin>>w[i];
	if(n == 1)
	{
		cout<<w[1]<<'\n';
		return 0;
	}
	fr(i,1,n)
	{
		int x ,y, c;
		cin>>x>>y>>c;
		v[x].pb(y);
		v[y].pb(x);
		mp[{x,y}] = c;
		mp[{y,x}] = c;
	}
	dfs(1,1);

	cout<<ans<<'\n';
 	//end_routine
}
