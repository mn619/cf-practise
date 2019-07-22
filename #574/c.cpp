#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
#define maxn 200000

using namespace std;

int n, h[maxn][2], dp[maxn][2];

signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

 	cin>>n;
 	fr(i, 1, n + 1) cin>>h[i][0];
 	fr(i, 1, n + 1) cin>>h[i][1];
 		
 	dp[1][0] = h[1][0];
 	dp[1][1] = h[1][1];
 	
 	fr(i, 2, n + 1){
 		fr(j, 0, 2){
 			dp[i][j] = max(dp[i - 1][!j], dp[i - 2][!j]) + h[i][j];
 		}
 	}

 	cout<<max(dp[n][0], dp[n][1]);
}