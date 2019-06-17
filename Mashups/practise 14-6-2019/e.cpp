#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);

using namespace std;

unsigned int dp[101];

signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

	dp[1] = 2;
	dp[2] = 3;

	int n = 100;

	fr(i, 3, 100){
		dp[i] = dp[i - 1] + dp[i - 2];
		if(dp[i] < dp[i - 1]) break;
	}

	cin>>n;
	fr(i, 1, 100){
		if(dp[i] == n) return cout<<i<<"\n", 0;
		else if(dp[i] > n) return cout<<i - 1, 0;
	}
}