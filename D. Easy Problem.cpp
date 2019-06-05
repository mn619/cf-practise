#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);

using namespace std;

int a[100001], n, dp[100001][4] = {{0}};
string s;
signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH
 	cin>>n>>s;
 	fr(i,1,n + 1)cin>>a[i];
 	//memset(dp, 0, sizeof dp);

 	fr(i,1,n + 1)
 	{
 		fr(j,0,4) dp[i][j] += dp[i - 1][j];
 		if(s[i - 1] == 'h') dp[i][0] += a[i];
 		else if(s[i - 1] == 'a') dp[i][1] = min(dp[i - 1][0], dp[i - 1][1] + a[i]);
 		else if(s[i - 1] == 'r') dp[i][2] = min(dp[i - 1][1], dp[i - 1][2] +  a[i]);
 		else if(s[i - 1] == 'd') dp[i][3] = min(dp[i - 1][2], dp[i - 1][3] + a[i]);
 		//fr(j,0,4) cout<<dp[i][j]<<" ";
 		//cout<<'\n';
 	}

 	cout<<dp[n][3];//<<" "<<dp[n][0];
}