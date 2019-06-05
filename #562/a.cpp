#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);

using namespace std;

int n, m, a[300001];

bool check(int x){
	int v = 0;
	int b[n + 1];
	fr(i, 1, n + 1){
		int cnt = 0;
		while((m + v - a[i])%m > x){
			v++;
			if(v == m || cnt > x) return 0;
			v %= m;
		}
		b[i] = v;
	}

	return 1;
}

signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH
 	string s;
	
	cin>>n>>m;
	fr(i, 1, n + 1) cin>>a[i];

	int l = 0, r = m - 1;
	int ans = 0;

	while(l <= r){
		int mid = (l + r)/2;
		if(check(mid)){
			r = mid - 1;
			ans = mid;
		}
		else l = mid + 1;
	}

	cout<<ans;
}