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


 	int n, k;
 	cin>>n>>k;
 	int a[n + 1];
 	int sum = 0, rem = k;

 	int ans = -1;
 	
 	fr(i, 1, n + 1){
 		cin>>a[i];
 		sum += a[i];

 		int t = min((int)8, min(sum, rem));

 		sum -= t;
 		rem -= t;

 		if(rem <= 0) {ans = i; break;}
 	}

 	cout<<ans;
}