#include<bits/stdc++.h>
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define int long long
#define mp make_pair
#define mod 1000000007

using namespace std;
int n,m;
int a[1001][1001],dp[4][1002][1002]={{{0}}};
signed main()
{
 	//ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>a[i][j];
	
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		dp[0][i][j]=max(dp[0][i-1][j],dp[0][i][j-1])+a[i][j];

	for(int i=n;i>=1;i--)
		for(int j=m;j>=1;j--)
		dp[1][i][j]=max(dp[1][i+1][j],dp[1][i][j+1])+a[i][j];

	for(int i=n;i>=1;i--)
		for(int j=1;j<=m;j++)
		dp[2][i][j]=max(dp[2][i+1][j],dp[2][i][j-1])+a[i][j];

	for(int i=1;i<=n;i++)
		for(int j=m;j>=1;j--)
		dp[3][i][j]=max(dp[3][i-1][j],dp[3][i][j+1])+a[i][j];
	int ans=0;
	
	for(int i=2;i<n;i++)
		for(int j=2;j<m;j++)
			ans=max(ans,max(dp[0][i-1][j]+dp[1][i+1][j]+dp[2][i][j-1]+dp[3][i][j+1],dp[0][i][j-1]+dp[1][i][j+1]+dp[2][i+1][j]+dp[3][i-1][j]));
			
			
	cout<<ans;
	
}



