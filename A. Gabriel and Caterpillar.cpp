#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);

using namespace std;

int n, m, inv[300001], pos[300001];
vector<int> v[300001];

signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

 	cin>>n>>m;

 	fr(i, 1, n + 1){
 		cin>>pos[i];
 	}
 	fr(i, 1, m + 1){
 		int a, b;
 		cin>>a>>b;
 		v[a].pb(b);
 		v[b].pb(a);
 	}
 	int las = 1, ans = 0;
 	aman
 	fr(i, 1, n + 1){
 		int p = pos[i];
 		inv[p] = i;
 		for(auto x: v[p]){
 			las = max(las, inv[x] + 1);
 		}
 		ans += (i - las + 1);
 	}
 	cout<<ans;
}