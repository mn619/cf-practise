#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);

using namespace std;

signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

	int n, h, m;
	cin>>n>>h>>m;
	int a[n + 1];
	fr(i, 1, n+  1){
		a[i] = h;
	}


	while(m--){
		int l, r, x;
		cin>>l>>r>>x;
		fr(i, l, r + 1) a[i] = min(a[i], x);
	}


	int ans = 0;
	fr(i, 1, n + 1){
		ans += a[i]*a[i];
	} 

	cout<<ans;

}