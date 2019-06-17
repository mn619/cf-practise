#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);

using namespace std;

int dp[311][311];

int solve(int a, int b){
	if(a <= 1 and b <= 1) return 0;
	if(a <= 0 || b <= 0) return 0;
	if(dp[a][b] != -1) return dp[a][b];
	dp[a][b] = max(solve(a - 2, b + 1), solve(b - 2, a + 1)) + 1;
	return dp[a][b];
}

signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

 	int a, b;
 	cin>>a>>b;

 	fr(i, 1, 311){
 		fr(j, 1, 311) dp[i][j] = -1;
 	}

 	int ans = solve(a, b);
 	cout<<ans;
 	
}