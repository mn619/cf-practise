/*

#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);

using namespace std;

int n, a[101], dp[101][(1<<17)], s[60];

vector <int> p;

void compute()
{
	int b[60] = {0};
	fr(i, 1, 60)
	{
		if(!b[i]) 
		{
			p.push_back(i);
			for(int j = i*i; j < 60; j +=i)
			{
				b[i] = 1;
			}
		}
	}

	fr(i, 1, 60)
	{
		int ans = 0;
		fr(j, 0, p.size())
		{
			if(i%p[j]) ans += (1<<j);
		}
		s[i] = ans;
	}

}

signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

 	compute();

 	cin>>n;
 	fr(i, 1, n + 1) cin>>a[i];
 
 	memset(dp, mod, sizeof dp);

	fr(i, 0, (1<<17)) 
		dp[0][i] = 0;

	
	fr(i, 1, n + 1)
	{
		fr(j, 1, 60)
		{
			fr(k, 0, 17)
			{
				if(s[j]&(1<<k)) dp[i][j] = min(dp[i][j], )
			}
		}
	}
}