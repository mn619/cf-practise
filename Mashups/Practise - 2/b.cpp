#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);

using namespace std;

int n, x, y, s1, s2;
vector <int> v[300001];
bool ok[300004];

int dfs(int node, int parent){
	int siz = 1;
	for(auto x: v[node]){
		if(x == parent) continue;
		siz += dfs(x, node);
		ok[node] = (ok[node] || ok[x]);
	}

	if(ok[node] && parent == x) s2 = siz;
	if(node == y) s1 = siz;
	return siz;
}

signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

 	cin>>n>>x>>y;
 	ok[y] = 1;
 	fr(i, 1, n){
 		int a, b;
 		cin>>a>>b;
 		v[a].pb(b);
 		v[b].pb(a);
 	}

 	dfs(x, -1);
 	int ans = n*(n - 1) - s1*(n - s2);
 	cout<<ans;
}