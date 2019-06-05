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


int dp[51][10] = {{0}};

signed main()
{
	//FILEIO
 	//start_routine
	
	string s;
	cin>>s;
	int n = s.size();
	int a[s.size() + 2];
	bool ok = 1;
	fr(i,0,s.size())
	{
		a[i + 1] = s[i] - '0';
	}

	

	memset(dp, 0, sizeof dp);

	fr(i,0,10)
	{
		dp[1][i] = 1;
	}
	fr(i,2,n + 1)
	{
		if(abs(a[i] - a[i - 1]) > 1) ok = 0;
	}

	fr(i,1,n)
	{
		fr(j,0,10)
		{
			int x = dp[i][j];
			dp[i + 1][((j +  a[i + 1])/2)] += x;

			if((j + a[i + 1])%2 == 1)
			{
				dp[i + 1][(j + a[i + 1])/2 + 1] += x;
			}
		}
	}

	int ans = -ok;

	fr(i,0,10) ans += dp[n][i];
	cout<<ans<<'\n';

 	//end_routine
}
