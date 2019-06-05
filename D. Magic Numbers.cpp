#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);

using namespace std;

int m, d;
int pwr[2001] = {1};


bool check(string a)
{
	int n = a.size();
	int s =  0;
	fr(i,0,n)
	{
		s += ((a[i]-'0')*pwr[n - i - 1])%m;
		s %= m;
	}
	if(s%m) return 0;
	bool b = 1;
	fr(i,0,n)
	{
		if(b && a[i]-'0' == d)  return 0;
		if(!b && a[i]-'0' != d) return 0;
		b = !b;
	}
	return 1;
}

int solve(string a)
{
	reverse(a.begin(), a.end());
	int n = a.size();
	int dp[n+1][m][2] = {{{0}}};
	bool b = n%2;

	fr(k,0,10)
	{
		int dig = a[0] - '0';
		if((b && k == d) || (!b && k != d)) continue;
		dp[1][k%m][1]++;
		if(k <= dig) dp[1][k%m][0]++;
	}
	b = !b;
	fr(i,2,n + 1)
	{
		int dig = a[i - 1] - '0';
		fr(j,0,m)
		{
			fr(k,0,10)
			{
				if((b && k == d) || (!b && k != d)) continue;
				int v = (pwr[i - 1]*k)%m;
				v = (j - v + m)%m;
				dp[i][j][1] += dp[i - 1][v][1];
				if(k < dig) dp[i][j][0] += dp[i - 1][v][1];
				else if(k == dig) dp[i][j][0] += dp[i - 1][v][0];
			}
			dp[i][j][1] %= mod;
			dp[i][j][0] %=mod;
		}	
		b = !b;
	}
	return dp[n][0][0];
}

signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH
 	string a,b;

 	cin>>m>>d>>a>>b;
 	fr(i,1,2001) pwr[i] = (10*pwr[i - 1])%m;

 	int ans = solve(b) - solve(a);
 	if(check(a)) ans++;
 	ans = (ans + mod)%mod;
 	cout<<ans<<'\n';
}