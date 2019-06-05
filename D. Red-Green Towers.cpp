#include<bits/stdc++.h>
#define start_routine cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false); int begtime = clock();
#define end_routine int endtime = clock(); cerr << endl << "Time elapsed: " << (endtime - begtime)*1000/CLOCKS_PER_SEC << " ms"; return 0;
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define int long long
#define mp make_pair
#define fr(i,a,b) for(i=a;i<b;i++)
#define mod (int)1000000007

using namespace std;
int r,g;
inline int height()
{
	int h=0;
	while((h+1)*(h+2)<=2*(r+g))h++;
	return h;
}
signed main()
{
 	//start_routine
 	cin>>r>>g;
 	int h=height();
 	cout<<h<<"\n";
	int dp[2][20001]={{0}};
 	int i,j;
 	dp[0][0]=1,dp[0][1]=0;
 	fr(i,1,h+1)
 	{
 		dp[i&1][0]=1;
 		cout<<i<<" "<<dp[i&1][0]<<" ";
 		fr(j,1,20001)
 		{
 			dp[i&1][j]=dp[!(i&1)][j];
 			if(j>=i){dp[i&1][j]+=dp[!i&1][j-i];dp[i&1][j]%=mod;}if(j<=r)cout<<dp[i&1][j]<<" ";
 		}
 		cout<<"\n";
 	}
 	int ans=0;
 	int x=max(r,g),y=min(r,g);
 	r=x,g=y;
 	fr(i,0,r+1)cout<<dp[h&1][i]<<" ";
 	cout<<"\n";
 	fr(i,h*(h+1)/2-g,r+1){ans+=dp[h&1][i],ans%=mod;}
 	cout<<ans<<"\n";
 	
	//end_routine
}