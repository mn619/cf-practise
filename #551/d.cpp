#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);

using namespace std;

int n, a[300001], p[300001], c[300001];
vector <int> v[300001];

int dfs1(int node){

	if(v[node].size() == 1 && v[node][0] == p[node]) return 1;
	int sz = 0;
	for(auto x: v[node]){
		if(x == p[node]) continue;
		sz += dfs1(x);
	}
	c[node] = sz;
	return sz;
}


int dfs(int node, int l, int r){
	vector <int> s1, s2;

	if(l == r) return r;

	for(auto x: v[node]){
		if(x == p[node]) continue;
		if(a[x] == 0) s1.pb(c[x]);
		else s2.pb(c[x]);
	}

	int sm1 = 0, sm2 = 0;
	for(auto x: s1) sm1 += x;
	for(auto x: s2) sm2 += x;
		
	if(a[node] == 0){
		int r1 = r - sm1 - s2.size() + 1;
		int mnind = 0, mn = 300001;
		for(auto x: v[node]){
			if(x == p[node]) continue;
			if(a[x] == 1){
				if(c[x] < mn){
					mn = c[x];
					mnind = x;
				}
			}
		}
		return dfs(mnind, r1 - c[mnind] + 1, r1);
	}
	if(a[node] == 1){
		int r1; 
		int mn = 0, mn = 0;
		for(auto x: v[node]){
			if(x == p[node]) continue;
			if(a[x] == 1){
				if(c[x] < mn){
					mn = c[x];
					mnind = x;
				}
			}
		}
		dfs(mnind, r1 - c[mnind] + 1, r1);
	}
}
signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH
 	cin>>n;
 	fr(i, 1, n + 1) cin>>a[i];
 	fr(i, 2, n + 1){
 		cin>>p[i];
 		v[i].pb(p[i]);
 		v[p[i]].pb(i);
 	}

 	int k = dfs1(1);
 	cout<<dfs(1, 1, k);

}