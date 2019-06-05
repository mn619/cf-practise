#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
#define LogN 17
using namespace std;

vector <int> v[5];
int dp[6][200001][LogN + 1];

int n, m, k;


int find_max(int i, int j, int l)
{
	int ans = 0;
	for(int k = LogN; k >= 0; k--)
	{
		if(l&(1<<k))
		{
			ans = max(ans, dp[i][j][k]);
			j -= (1<<k);
			l -= (1<<k);
		}
	}
	return ans;
}

signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

 	cin>>n>>m>>k;

 	fr(i, 1, n + 1)
 	{
 		fr(j, 1, m + 1)
 		{
 			int x;
 			cin>>x;
 			v[j].pb(x);
 		}
 	}

 	fr(i, 1, m + 1)
 	{
 		fr(j, 0, n)
 		{
 			fr(k, 0, LogN)
 			{
 				if(k == 0) 
 				{
 					dp[i][j][k] = v[i][j];
 					continue;
 				}
 				else
 				{
 					dp[i][j][k] = dp[i][j][k - 1];
 					if(j - (1<<(k - 1)) >= 0)
 					{
 						dp[i][j][k] = max(dp[i][j][k], dp[i][j - (1<<(k - 1))][k - 1]);
 					}
 				}
 			}
 		}
 	}

 	int ans = 0, ind = 0;
 	fr(j, 0, n)
 	{
 		int l = 0, r = j + 1;
 		while(l <= r)
 		{
 			int mid = (l + r)/2, ans1 = 0;
	 		fr(i, 1, m + 1)
 			{
 				ans1 +=  find_max(i, j, mid);
 			}
 			if(ans1 <= k)
 			{
 				if(ans < mid) {ans = mid, ind = j;}
 				l = mid + 1;
 			}
 			else r = mid - 1;
 		}
 	}

 	fr(i, 1, m + 1)
 	{
 		cout<<find_max(i, ind, ans)<<" ";
 	}
}