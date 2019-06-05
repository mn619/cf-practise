#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("C:/Users/Aman/Desktop/kachda/input.txt", "r", stdin); freopen("C:/Users/Aman/Desktop/kachda/output.txt", "w", stdout);

using namespace std;

struct data{
	map <int, int> mp;
};

int gcd(int a, int b)
{
	if(b == 0) return a;
	return gcd(b, a%b);
}

data dp[20001];
int n,a[20001];
vector <int> v[20001];
int ans = 0;


void dfs(int node, int parent)
{

	fr(i,0,v[node].size())
	{
		if(v[node][i] == parent) continue;
		dfs(v[node][i], node);
		for(auto it: dp[v[node][i]].mp)
		{
			int g = gcd(a[node], it.first);
			cout<<node<<" "<<a[node]<<" "<<it.first<<" "<<it.second<<" "<<g<<" "<<dp[node].mp[g]<<"\n";
			if(g > 1)
			{
				ans = max(ans, dp[node].mp[g] + it.second + 1);
			}
			dp[node].mp[g] = max(dp[node].mp[g], it.second);
			cout<<dp[node].mp[g]<<"\n";
		}
	}

	for(auto it: dp[node].mp)
	{
		dp[node].mp[it.first]++;
	}


	dp[node].mp[a[node]] = max((int)1, dp[node].mp[a[node]]);
	if(a[node] > 1) ans = max(ans, (int)1);
}
signed main()
{
	FILEIO
 	FLASH

	cin>>n;
	fr(i,1,n + 1) cin>>a[i];

	fr(i,1,n)
	{
		int x,y;
		cin>>x>>y;
		v[x].pb(y);
		v[y].pb(x);
	}

	dfs(1,0);
	cout<<ans<<"\n";
}