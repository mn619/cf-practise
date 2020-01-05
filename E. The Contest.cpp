#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
#define maxn 200000

using namespace std;

int a[maxn + 1], n, k[4];
int dp[maxn + 2][4];

signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

 	cin>>k[1]>>k[2]>>k[3];
 	fr(i, 1, 4){
  		n += k[i];
 		fr(j, 1, k[i] + 1){
 			int ind;
 			cin>>ind;
 			a[ind] = i;
 		}
 	}

 	for(int i = n; i >= 1; i--){
 		dp[i][3] = dp[i + 1][3];
 		dp[i][3] += (a[i] != 3);
 	}

 	int ans = maxn;
 	fr(i, 1, n + 1){
 		dp[i][1] = dp[i - 1][1] + (a[i] != 1);
 		dp[i][2] = min(dp[i - 1][1], dp[i - 1][2]) + (a[i] != 2);
 		ans = min(ans, min(dp[i][1], dp[i][2]) + dp[i + 1][3]);
 		// cout<<dp[i][1]<<" "<<dp[i][2]<<" "<<dp[i][3]<<'\n';
 	}
 	ans = min(ans, dp[1][3]);
 	cout<<ans<<'\n';

}