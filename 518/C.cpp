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

signed main()
{
	//FILEIO
 	//start_routine
	
	int tests = 1;
	//cin>>tests;

	while(tests--)
	{
		int n;
		cin>>n;
		int a[n+1];
		int dp[n+1][201] = {{0}}, pre[n+1][201] = {{0}}, suf[n+1][202] ={{0}};

		int i;
		fr(i,1,n+1)
		{
			cin>>a[i];
		}

		if(n == 1)
		{
			if(a[1] == -1)  cout<<200<<'\n';
			else cout<<1<<'\n';
			return 0;
		}
		// base cases

		{
			if(a[1] == -1 && a[2] == -1)
			{
				fr(i,1,201)
				{
					dp[1][i] = 1, dp[2][i] = 1;
				}
			}
			else 
			{
				if(a[1] == a[2])
				{
					dp[1][a[1]] = 1;
					dp[1][a[2]] = 1;
				}
				else 
				{
					if(a[1] == -1)
					{
						dp[1][a[2]] = 1;
						dp[2][a[2]] = 1;
					}
					else 
					{
						dp[1][a[1]] = 1;
						dp[2][a[1]] = 1;
					}
				}
			}
			fr(i,1,201)
			{
				pre[1][i] = pre[1][i-1] + dp[1][i];
				pre[2][i] = pre[2][i-1] + dp[2][i];
			}
		}
		fr(i,1,201)
		{
			pre[1][i] = pre[1][i-1]+ dp[1][i];
		}

		fr(i,3,n+1)
		{
			int j;
			fr(j,1,201)
			{
				if(a[i] != -1 && j == a[i]) dp[i][j] = dp[i-1][j];
				else if(a[i] == -1)
				{
					if(a[i-1] != -1)
					{
						if(j < a[i-1])
						{
							dp[i][j] = dp[i-2][a[i-1]];
						}
						else
						{
							dp[i][j] = pre[i-1][j];
						}
					}
					else // a[i-1] == -1 
					{
						dp[i][j] = pre[i-1][j];
					}
					
				}
					pre[i][j] = pre[i][j-1] + dp[i][j];
 			}

 			for(j = 200; j>=1; j--)
 			{
 				suf[i][j] = suf[i][j+1] + dp[i][j];
 			}
		}

		int ans = 0;


		fr(i,1,201)
		{
			if(a[n] != -1 && i == a[n])
			{
				ans = dp[n][i];
				break;
			}
			else if(a[n] == -1)
			{
				cout<<dp[n][i]<<'\n';
				ans +=dp[n][i];
			}
		}
		cout<<ans<<'\n';
	}

 	//end_routine
}
