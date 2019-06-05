#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);

using namespace std;

int n, k, a[5001];

int dp[5001][5001][6] = {{{0}}};

signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH
 	cin>>n>>k;

 	fr(i, 1,n + 1) cin>>a[i];

 	sort(a + 1, a + n + 1);

 	dp[n][1][0] = 1;
 	int ans = 1;

 	for(int i = n - 1; i >= 1; i--)
 	{
 		fr(j, 1, k + 1)
 		{
 			int d = a[i + 1]  - a[i];
 			fr(l,0,6) dp[i][j][0] = max(dp[i][j][0], dp[i + 1][j - 1][l] + 1);
			if(a[i +  1] == a[i]) dp[i][j][0] = max(dp[i][j][0], dp[i + 1][j][0] + 1);
			fr(l, 1, 6)
			{
				if(l < d) continue;
				else dp[i][j][l] = dp[i + 1][j][l - d] + 1;
 			}
 			fr(l, 0, 6)ans = max(ans, dp[i][j][l]);
 		}
 	}
 	cout<<ans<<'\n';
}