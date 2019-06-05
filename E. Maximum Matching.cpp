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
#define FILEIO freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
using namespace std;

int dp[101][101][5][5];
int c1[101], val[101], c2[101];
int n;

signed main()
{
	FILEIO
 	//start_routine
 	memset(dp, -mod, sizeof dp);
	cin>>n;
	int i;
	fr(i,1,n + 1)
	{
		cin>>c1[i]>>val[i]>>c2[i];
		dp[i][i][c1[i]][c2[i]] = val[i];
		dp[i][i][c2[i]][c1[i]] = val[i];
	}
	int j, len;
	fr(len,0,n)
	{
		fr(i,1,n - len + 1)
		{
			j = i + len;
			int t1;
			fr(t1,1,5)
			{
				int t2;
				fr(t2,1,5)
				{	
					int k;
					fr(k,i,j)
					{
						int l;
						dp[i][j][t1][t2] = max(dp[i][j][t1][t2], max(dp[i][k][t1][t2], dp[k+1][j][t1][t2]));
						fr(l,1,5)
						{
							dp[i][j][t1][t2] = max(dp[i][j][t1][t2], max(dp[i][k][t1][l] + dp[k + 1][j][l][t2], dp[i][k][l][t2] + dp[k + 1][j][t1][l]));
						}
					}
				}
			}
		}
	}

	int ans = 0;
	fr(i,1,5)
	{
		fr(j,1,5)ans = max(ans, dp[1][n][i][j]);
	}
 	cout<<ans<<'\n';
 	//end_routine
	
	
}
