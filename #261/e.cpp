#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
#define maxn 300000
#define pii pair<int, int>

using namespace std;

int n, m;
vector<int> v[maxn + 1];
map <pii, int> w, dp;

int solv(int par, int node, int len){
	int ans = len;
	for(auto x: v[node]){
		if(w[{node, x}] <= w[{par, node}]) continue;
		if(dp.count({node, x})) ans = max(len + dp[{node, x}], ans);
		else{
			int t = solv(node, x, len + 1);
			dp[{node, x}] = t - len;
			ans = max(ans, t);
		}
	}

	dp[{par, node}] = ans - len + 1;
	return ans;
}

signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

 	cin>>n>>m;
 	fr(i, 1, m + 1){
 		int a, b, c;
 		cin>>a>>b>>c;
 		v[a].pb(b);
 		w[{a,b}] = c;
 	}

 	int ans = 0;

 	fr(i, 1, n + 1){
 		int mn = 1000000;

 		for(auto x: v[i])
 			if(w[{i, x}] < mn)
 			mn = w[{i, x}];
 		
 		for(auto x: v[i])
 			if(w[{i, x}] == mn)
 			ans = max(ans, solv(i, x, 1));
 	}


 	cout<<ans;
}