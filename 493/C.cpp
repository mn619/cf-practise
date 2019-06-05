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
int n,x,y;
char c[300011];
signed main()
{
 	//start_routine
 	cin>>n>>x>>y;
 	int i;
 	fr(i,1,n+1)cin>>c[i];
 	int dp[n+1]={0};
 	if(c[1]=='0')dp[1]=y;
 	fr(i,2,n+1)
 	{
 		if(c[i]=='1')dp[i]=dp[i-1];
 		else
 		{
 			if(c[i-1]=='0')dp[i]=dp[i-1];
 			else
 			{
 				dp[i]=min(x+dp[i-1],y+dp[i-1]);
 			}
 		}
 	}
 cout<<dp[n];
	//end_routine
}



