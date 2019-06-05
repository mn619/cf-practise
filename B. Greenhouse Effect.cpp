#include<bits/stdc++.h>
#define start_routine cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false); int begtime = clock();
#define end_routine int endtime = clock(); cerr << endl << "Time elapsed: " << (endtime - begtime)*1000/CLOCKS_PER_SEC << " ms"; return 0;
#define fr(i,a,b) for(i=a;i<b;i++)

using namespace std;
int n,a[5001],dp[50001]={1},m;
int solve()
{
	int i,j;
	fr(i,0,n)
		fr(j,0,i)
			if(a[j]<=a[i] && dp[j]+1>dp[i])dp[i]=dp[j]+1;
	fr(i,0,n)if(dp[i]>dp[0])dp[0]=dp[i];
	return n-dp[0];
}
signed main()
{
 	start_routine
 	int i;
 	float shit;
 	cin>>n>>m;
 	fr(i,0,n)dp[i]=1;
 	fr(i,0,n)cin>>a[i]>>shit;
 	cout<<solve();
 	end_routine
}




