#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
#define maxn 200000

using namespace std;

int n, m, dp[300001];
map<int, int> dp2;

vector<pair<int, int>> v[300001];

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
 		v[c].pb({a,b});
 	}

 	int ans = 0;

 	fr(i, 1, 300001){
	 	for(auto x: v[i]){
	 		int a = x.first, b = x.second;

	 		dp2[b] = max(dp2[b], dp[a] + 1);
	 	}
	 	
	 	for(auto x: dp2){
	 		dp[x.first] = max(dp[x.first], x.second);
	 	}
	 	dp2.clear();
 	}

 	fr(i, 1, n + 1) ans = max(ans, dp[i]);
 	cout<<ans;		
}