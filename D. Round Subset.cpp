/*
#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);

using namespace std;

int n, k, a[201], b[201], dp[201][201][2];

int cnt(int p, int x)
{
	int ans = 0;
	while(x%p == 0) {ans++; x /= p;}
	return ans;
}
signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

 	cin>>n>>k;

 	fr(i,1, n+  1)
 	{
 		cin>>a[i];
 		b[i] = cnt(5, a[i]);
 		a[i] = cnt(2, a[i]);
 	}
 	memset(dp, 0, sizeof dp);

 	fr(i, 1, n + 1)
 	{
 		dp[i][1][0] = a[i];
 		dp[i][1][1] = b[i];

 		fr(j, 1, k + 1)
 		{
 			fr(l, 1, i)
 			{
 				if(min(dp[i][j][0], dp[i][j][1]) <= min(dp[l][j - 1][0] + a[i], dp[l][j - 1][1] + b[i]))
 				{
 					dp[i][j][0] = dp[l][j - 1][0] + a[i];
 					dp[i][j][1] = dp[l][j - 1][1] + b[i];
 				}
 			}
 			cout<<i<<" "<<j<<" "<<dp[i][j][0]<<" "<<dp[i][j][1]<<'\n';
 		}
 	}

 	int ans = 0;
 	fr(i, 1, n + 1)
 	{
 		ans = max(ans, min(dp[i][k][0], dp[i][k][1]));
 	}
 	cout<<ans<<'\n';

}