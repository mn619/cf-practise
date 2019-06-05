#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);

using namespace std;


void solve(){
	int n, k;
	cin>>n>>k;

	int a[n + 1];
	fr(i, 1, n + 1){
		cin>>a[i];
	}

	if(k == 0){
		cout<<a[1]<<"\n";
		return;
	}


	int l = a[n] - a[1];
	int dis = min(a[k + 1] - a[1], a[n] - a[n - k]), ans;
	if(dis == a[k + 1] - a[1]) ans = a[1];
	else ans = a[n];

	fr(i, 1, n + 1){
		if(i + k > n) break;
		int d = a[i + k] - a[i];
		if(k&1 == 0) d = d/2 + (d&1);
		else d = d/2;
		if(dis > d){
			dis = d;
			ans = a[i] + dis;
		}
	}
	if(k == n - 1){
		if(dis > l/2) ans = (a[1] + l/2);
	}

	cout<<ans<<'\n';
}
signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

 	int t;
 	cin>>t;
 	while(t--){
 		solve();
 	}
}