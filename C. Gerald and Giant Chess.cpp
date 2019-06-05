#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);

using namespace std;

int h, w, n, dp[2001], fac[2000001] = {1};
vector <int> v[2001];

int power(int a, int b, int m)
{
	if(b == 0) return 1;
	int temp = power(a, b/2, m);
	temp *= temp;
	temp %= m;
	if(b&1) temp *=a%m, temp%=m;
	return temp;
}

void compute()
{
	fr(i, 1, 2000001)
	{
		fac[i] = (fac[i - 1]*i)%mod;
	}
}

int f(int x1, int y1, int x2, int y2)
{
	if(x2 < x1 || y2 < y1) return 0;
	int ans = fac[(x2 - x1) + (y2 - y1)];
	ans *= power((fac[x2 - x1]*fac[y2 - y1])%mod, mod - 2, mod);
	ans %= mod;
	return ans;
}

signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

 	compute();
 	cin>>h>>w>>n;

 	fr(i, 1, n + 1)
 	{
 		int x, y;
 		cin>>x>>y;
 		v[i].pb(x);
 		v[i].pb(y);
 	}

 	n++;
 	v[n].pb(h);
 	v[n].pb(w);

 	sort(v + 1, v + n + 1);

 	fr(i, 1, n + 1)
 	{
 		dp[i] = f(1, 1, v[i][0], v[i][1]);
 		fr(j,1,i)
 		{
 			dp[i] -= dp[j]*f(v[j][0], v[j][1], v[i][0], v[i][1]);
 			dp[i] %= mod;
 		}
 		//cout<<dp[i]<<'\n';
 	}
 	int ans = (dp[n] + mod)%mod;
 	cout<<ans<<'\n';
}