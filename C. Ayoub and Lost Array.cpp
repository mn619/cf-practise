#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("C:/Users/Aman/Desktop/kachda/input.txt", "r", stdin); freopen("C:/Users/Aman/Desktop/kachda/output.txt", "w", stdout);

using namespace std;

int n, dp[200001][3], l, r, z, o, t;

int cal(int c)
{
	int r1 = (r/3)*3 +c;
	if(r1 > r) r1-=3;
	int l1 = (l/3)*3 + c;
	if(l1 < l) l1 += 3;

	return (r1 - l1)/3 + 1;
}
signed main()
{
	FILEIO
 	FLASH
	cin>>n>>l>>r;
	dp[0][0] = 1;
	dp[0][1] = 1;
	dp[0][2] = 1;

	dp[1][0] = z = cal(0)%mod;
	dp[1][1] = o = cal(1)%mod;
	dp[1][2] = t = cal(2)%mod;

	fr(i,2,n + 1)
	{
		dp[i][0] = (dp[i - 1][0]*z + dp[i - 1][1]*t + dp[i - 1][2]*o)%mod;
		dp[i][1] = (dp[i - 1][0]*o + dp[i - 1][1]*z + dp[i - 1][2]*t)%mod;
		dp[i][2] = (dp[i - 1][0]*t + dp[i - 1][1]*o + dp[i - 1][2]*z)%mod;
	}

	cout<<dp[n][0]<<'\n';
	
}