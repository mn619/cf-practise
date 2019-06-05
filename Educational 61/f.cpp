#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);

using namespace std;

int n, dp[501][501] = {{0}};
string s;

signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH
 	cin>>n>>s;
 	
 	fr(l,0,n)
 	{
 		fr(i,0,n - l)
 		{
 			int j = i + l;
 			if(l == 0) {dp[i][i] = 1; continue;}
 			dp[i][j] = dp[i + 1][j] + 1;
 			
 			fr(k,i + 1,j + 1)
 			{
 				if(s[i] == s[k])
 				{
 					dp[i][j] = min(dp[i][j], dp[i + 1][k] + dp[k + 1][j]);
 				}
 				else dp[i][j] = min(dp[i][k - 1] + dp[k + 1][j] + 1, dp[i][j]);
 			}
 		}
 	}
	cout<<dp[0][n - 1]<<"\n";
}