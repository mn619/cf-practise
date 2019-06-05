#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);

using namespace std;

int fac[1000001] = {1};

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
	fr(i,1,1000001)
	{
		fac[i] = (fac[i - 1]*i)%mod;
	}
}

int C(int n, int r)
{
	if(r > n) return 0;
	int ans = fac[n];
	ans *= power(fac[r], mod - 2, mod);
	ans%=mod;
	ans*=power(fac[n - r], mod - 2, mod);
	ans %= mod;
	return ans;
}


signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

 	int a, b, n, m;

 	cin>>n>>m>>a>>b;
 	compute();

 	int ans = 0;
 	
 	fr(i,1,n)
 	{
 		int temp = C(m - 1, i - 1);
 		temp *= fac[n - 1];
 		temp %= mod;
 		temp *= power(fac[i], mod - 2, mod);
 		temp %= mod;
 		temp *= power(m, n -1 - i, mod);
 		temp %= mod;
 		temp *= fac[n - 2];
 		temp %= mod;
 		ans += temp;
 		//ans %= mod;
 	}
 	cout<<ans<<'\n';
}