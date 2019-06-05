#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);

using namespace std;

int n,q, c[100001],v[100001];
int mod  = 100000000700000;

signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

 	cin>>n>>q;
 	fr(i,1,n + 1)
 	{
 		cin>>v[i];
 	}
 	fr(i,1,n + 1)
 	{
 		cin>>c[i];
 	}

 	while(q--)
 	{
 		int a,b;
 		cin>>a>>b;
 		int dp[n + 1] = {0};
 		memset(dp, -mod, sizeof dp);

 		int ans = 0, mx1 = 0, mx2 = 0;
 		dp[0] = 0;

 		fr(i,1,n + 1)
 		{
 			int temp = -mod;
 			temp = max((mx1 != c[i]? dp[mx1]:dp[mx2]), (int) 0) + b*v[i];
 			if(dp[c[i]] != -mod) temp = max(dp[c[i]] + a*v[i],temp);
 			if(temp > dp[c[i]]) dp[c[i]] = temp;

 			if(mx1 == c[i] || mx2 == c[i])
 			{
 				if(dp[mx1] < dp[mx2]) swap(mx1, mx2);
 			}
 			else
 			{
 				if(dp[c[i]] > dp[mx1]) mx2 = mx1, mx1 = c[i];
 				else if(dp[c[i]] > dp[mx2]) mx2 = c[i];
 			}
			ans = max(ans, dp[c[i]]);

 		}
 		cout<<ans<<'\n';
 	}


}