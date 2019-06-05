#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);

using namespace std;

int n, k;
vector <int> v[100001];
bool vis[100001];


int power(int a, int b, int m)
{
	if(b == 0) return 1;
	int temp = power(a, b/2, m);
	temp *= temp;
	temp %= m;
	if(b&1) temp *=a%m, temp%=m;
	return temp;
}

int dfs(int node, int parent){
	int sz = 1;
	vis[node] = 1;
	for(auto x: v[node]){
		if(x == parent) continue;
		sz += dfs(x, node);
	}

	return sz;
}

signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

 	cin>>n>>k;

 	fr(i, 1, n){
 		int a, b, c;
 		cin>>a>>b>>c;
 		if(c == 1) continue;
 		v[a].pb(b);
 		v[b].pb(a);
 	}


 	int ans = power(n, k, mod);

 	fr(i, 1, n + 1){	
 		if(!vis[i]){
 			int t = dfs(i, i);
 			ans += mod - power(t, k, mod);
 			ans %= mod;
 		}
 	}

 	cout<<ans;

}