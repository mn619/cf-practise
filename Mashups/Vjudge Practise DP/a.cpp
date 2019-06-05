//Mn619 on codeforces
#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);

using namespace std;

int n, m, c0, d0, dp[11][1001];

signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

 	cin>>n>>m>>c0>>d0;

 	int ans = 0;
 	fr(i, 1,m + 1){
 		int a, b, c, d;
 		cin>>a>>b>>c>>d;

 		fr(j, 1, n + 1){
 			dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
 			fr(k, 1, n + 1){
 				if(a - b*k < 0 || j - c*k < 0) break;
 				dp[i][j] = max(dp[i][j], dp[i - 1][j - c*k] + d*k);
  			} 
  			ans = max(ans, dp[i][j]);
 		}
 	}

 	fr(k, 1, n + 1){
 		if(n - c0*k < 0) break;
 		ans = max(ans, dp[m][n - c0*k] + d0*k);
 	}

 	cout<<ans;
}