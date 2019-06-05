#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);

using namespace std;

int n, k, a[200001];
long double ans = 0;

signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

 	cout<<setprecision(60);

 	cin>>n>>k;
 	fr(i, 1, n + 1) cin>>a[i];


 	fr(i, 1, n + 1){
 		int l = max((int)1, i - k + 1), r = min(i, n - k + 1);
 		ans += a[i]*(r - l + 1);
 	}

 	
 	ans = 1.0*ans/(n - k + 1);
 	cout<<ans;
 	
}