#include<bits/stdc++.h>
#define start_routine cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false); int begtime = clock();
#define end_routine int endtime = clock(); cerr << endl << "Time elapsed: " << (endtime - begtime)*1000/CLOCKS_PER_SEC << " ms"; return 0;
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define int long long
#define mp make_pair
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
using namespace std;

int dp[1000001] = {0}, n, p[1000001];
bool b[1000001] = {0};
signed main()
{
	//FILEIO
 	//start_routine
	
	cin>>n;
	int ans = 0;
	fr(i,1,n + 1)
	{
		cin>>p[i];
		if(p[i] == 1)
		{
			dp[i + 1] = 1;
			b[1]!=b[1];
		}
		else
		{
			if(b[p[i]] == 0)
			{
				dp[i + 1] = dp[p[i]] + 1;
				ans = max(ans, dp[i + 1]);
				b[p[i]] = 1;
			}
			else 
			{
				dp[i + 1] = dp[p[i]];
				b[p[i]] = 0;
			}
		}
		b[i + 1] = 1;
		cout<<dp[i + 1]<<" ";
	}
 	//end_routine
}
