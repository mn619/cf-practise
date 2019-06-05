#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define double long double
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);

using namespace std;

int n;
double p[19][19], dp[19][(1<<17)];

signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

 	cin>>n;

 	int temp[n][n];
 	fr(i, 0, n)
 	{
 		fr(j, 0, n)
 		{
 			cin>>p[i][j];
 		}
 	}


 	memset(dp, 0.0, sizeof dp);

 	/*
 	fr(i, 0, n)
 	{
 		fr(j, 0, n) cout<<p[i][j]<<" ";
 		cout<<'\n';
 	}*/



	fr(i, 1, (1<<(n - 1)))
	{
		fr(j, 0,  n - 1)
		{
			if(i&(1<<j))
			{
				if(__builtin_popcount(i) == 1)
				{
					dp[j][i] = p[0][j + 1];
					continue;
				}

				fr(k, 0, n - 1)
				{
					if(k == j || !(i&(1<<k))) continue;
					dp[j][i] = max(dp[j][i],(p[j + 1][k + 1]*dp[j][i - (1<<k)] + p[k + 1][j + 1]*dp[k][i - (1<<j)]));
				}
			}
		}
	}

	double ans = 0;

	fr(i, 0, n - 1)
	{
		ans = max(ans, dp[i][(1<<(n - 1)) - 1]);
	}
	
	cout<<ans<<"\n";
}