#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);

using namespace std;
int n, sz0[200001] = {0}, sz1[200001] = {0}, s0[200001] = {0}, s1[200001] = {0};
vector <int> v0[200001],  v1[200001];

void dfs0(int node, int parent, int y){
	s0[node] = y;
	sz0[y]++;
	for(auto x: v0[node]){
		if(x == parent) continue;
		dfs0(x, node, y);
	}
}

void dfs1(int node, int parent, int xnxx){
	s1[node] = xnxx;
	sz1[xnxx]++;
	for(auto x: v1[node]){
		if(x == parent) continue;
		dfs1(x, node, xnxx);
	}
}

signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

 	cin>>n;

 	fr(i,1, n){
 		int x, y, c;
 		cin>>x>>y>>c;
 		if(c == 0) v0[x].pb(y), v0[y].pb(x);
 		else if(c == 1) v1[x].pb(y), v1[y].pb(x);
 	}

 	fr(i, 1, n+ 1){
 		if(s0[i] == 0) dfs0(i, i, i);
 		if(s1[i] == 0) dfs1(i, i, i);
 	}

 	int ans = 0;
 	fr(i, 1, n + 1){
 		ans += sz0[s0[i]]*(sz1[s1[i]] - 1);
 	}

 	fr(i, 1, n + 1){
		ans += sz0[i]*(sz0[i] - 1);
 	}

 	cout<<ans;

}