#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);

using namespace std;

int n, l, r, a[100001], p[100001], b[100001];

signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

 	cin>>n>>l>>r;

 	fr(i, 1, n + 1) cin>>a[i];
 	fr(i, 1, n + 1) cin>>p[i];

 	map <int, int> inv;

 	fr(i, 1, n + 1){
 		inv[p[i]] = i;
 	}

 	int mx = r - a[inv[n]];
 	b[inv[n]] = r;
 	for(int i = n - 1; i >= 1; i--){
 		int ind = inv[i];
 		b[ind] = min(mx - 1 + a[ind], r);
 		mx = min(mx, b[ind] - a[ind]);
 		if(b[ind] < l || b[ind] > r) return cout<<-1, 0;
 	}

 	fr(i, 1, n + 1) cout<<b[i]<<" ";

}	