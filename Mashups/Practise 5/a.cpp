#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define inf 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);

using namespace std;

int n, a[500001];

int sgn(int x){
	if(x > 0) return 1;
	if(x < 0) return -1;
	return 0;
}


signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

 	cin>>n;

 	int mn = inf, mx = -inf, sum = 0;
 	fr(i, 1, n + 1){
 		cin>>a[i];
 		sum += abs(a[i]);
 		mn = min(a[i], mn);
 		mx = max(mx, a[i]);
 	}
 	if(n == 1) return cout<<a[1], 0;
 	
 	if(sgn(mn) != sgn(mx)) cout<<sum; 
 	else if(sgn(mx) < 0) cout<<sum + 2*mx;
 	else cout<<sum - 2*mn;
}