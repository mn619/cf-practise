#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 998244353
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);

using namespace std;

int n;

int ans = 1, fac[200001] = {1};
vector <int> v[200001];

void dfs(int node, int par){
	int cnt = 0;
	for(auto x: v[node]){
		if(x == par) continue;
		cnt++;
		dfs(x, node);
	}

	int t = fac[cnt];
	if(node != 1) t *= cnt + 1;
	
	t %= mod;
	ans *= t;
	ans %= mod;
}

signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

 	cin>>n;
 	fr(i, 1, n + 1) fac[i] = (i*fac[i - 1])%mod;

 	fr(i, 1, n){
 		int a, b;
 		cin>>a>>b;
 		v[a].pb(b);
 		v[b].pb(a);
 	}
 	dfs(1, 1);

 	ans *= n;
 	ans %= mod;
 	cout<<ans;
 }