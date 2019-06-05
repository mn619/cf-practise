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
string s;
int n,dp[1000005],ans[1000005]={0},a=0;

signed main()
{
 	start_routine
 	cin>>s;
 	n=s.size();
 	ans[0]=0;
 	dp[0]=0;
 	int i;
 	fr(i,0,n)
 	{
 		if(s[i]=='a'){a++; dp[a]=(2*dp[a-1]+1)%mod; if(i)ans[i]=ans[i-1];}
 		else
 		{
 			ans[i]=dp[a]%mod;
 			if(i)ans[i]+=ans[i-1];
 			ans[i]%=mod;
 		}
 	}
 	cout<<ans[n-1];
	end_routine
}



