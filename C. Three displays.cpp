#include<bits/stdc++.h>
#define start_routine cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false); int begtime = clock();
#define end_routine int endtime = clock(); cerr << endl << "Time elapsed: " << (endtime - begtime)*1000/CLOCKS_PER_SEC << " ms"; return 0;
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define int long long
#define mp make_pair
#define fr(i,a,b) for(i=a;i<b;i++)


using namespace std;
int n,s[3001],c[3001];
int dp[3001][3];

signed main()
{
 	//start_routine
 	cin>>n;
 	int i;
 	int inf = (int) 1000000000*1000000000+1;

 	fr(i,1,n+1)cin>>s[i];
 	fr(i,1,n+1)cin>>c[i];

 	fr(i,1,n+1)
 	{
 		dp[i][0] = c[i];
 		dp[i][1] = inf;
 		dp[i][2] = inf;

 		int j;
 		fr(j,1,i)
 		{
 			if(s[j]<s[i] && dp[i][1] > c[i]+dp[j][0])
 				dp[i][1] = dp[j][0]+c[i];
 		}

 		fr(j,1,i)
 		{
 			if(s[j]<s[i] && dp[i][2] > c[i]+dp[j][1])
 				dp[i][2] = dp[j][1]+c[i];
 		}
 	}

 	int min = inf;
 	fr(i,1,n+1)
 	{
 		if(dp[i][2] < min) min = dp[i][2];
 	}

 	if(min!=inf)return cout<<min,0;
 	cout<<-1;
 	return 0;
 	//end_routine
 }




