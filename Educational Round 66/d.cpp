#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);

using namespace std;

int n, k, a[300001], p[300002];

signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

	cin>>n>>k;
	fr(i, 1, n + 1) cin>>a[i];
	if(n == 1) return cout<<a[1], 0;

	for(int i = n; i >= 1; i--){
		p[i] = p[i + 1] + a[i];
	}

	int ans = p[1];

	sort(p + 2, p + n + 1);
	reverse(p + 2, p + n + 1);

	fr(i, 2, k + 1){
		ans += p[i];
	}

	cout<<ans;
}