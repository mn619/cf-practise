#include<bits/stdc++.h>
#define start_routine cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false); int begtime = clock();
#define end_routine int endtime = clock(); cerr << endl << "Time elapsed: " << (endtime - begtime)*1000/CLOCKS_PER_SEC << " ms"; return 0;
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define int long long
#define mp make_pair
#define fr(i,a,b) for(i=a;i<b;i++)
#define mod 1000000007

using namespace std;
signed main()
{
 	//start_routine
 	int n,i;
 	cin>>n;
 	int a[n+1];
 	fr(i,1,n+1)cin>>a[i];

 	int dp[n+1];
 	dp[n] = 1;

 	for(i=n-1;i>=1;i--)
 	{
 		if(a[i]*2 >=a[i+1]) dp[i] = dp[i+1]+1;
 		else dp[i]=1;
 	}
 	int ans = 0;
 	fr(i,1,n+1) if(dp[i]>ans) ans = dp[i];
 	cout<<ans;
 	//end_routine
}