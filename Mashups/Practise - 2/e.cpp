#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);

using namespace std;

int n, a[100001], dp[1000001] = {1};

signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

 	cin>>n;
 	fr(i, 1, n + 1) cin>>a[i];

 	fr(i, 1, n + 1)
 	{
 		vector <int> v[2];
 		for(int j = 1; j*j <= a[i]; j++)
 		{
 			int x = 0, y = 0;
 			if(a[i]%j == 0)
 			{
 				x = dp[j - 1];
 				v[0].pb(j);
 				v[1].pb(x);

 				if(j*j != a[i])
 				{	
 					y = dp[a[i]/j - 1];
 					v[0].pb(a[i]/j);
 					v[1].pb(y);
 				}
 			}
 		}
 		fr(j, 0, v[0].size())
 		{
 			dp[v[0][j]] += v[1][j];
 			dp[v[0][j]] %= mod;
 		}
 	}

 	int ans = 0;
 	fr(i, 1, n + 1)
 	{
 		ans += dp[i];
 		ans %= mod;
 	}

 	cout<<ans<<'\n';

}