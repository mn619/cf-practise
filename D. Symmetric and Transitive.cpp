#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);

using namespace std;

int s[2][4001] = {{1}}, b[4001] = {1}, fac[4001] = {1}, n;

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
	fr(i,1,4001)
	{
		fac[i] = (i*fac[i - 1])%mod;
	}
}
int C(int n, int r)
{
	return (fac[n]*power((fac[n - r]*fac[r])%mod, mod - 2, mod))%mod;
}

signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

 	cin>>n;

 	compute();

 	fr(i,1,n + 1)
 	{
 		s[i&1][1] = 1;
 		b[i] = 1;
 		fr(j,2,i + 1)
 		{
 			s[i&1][j] = s[!(i&1)][j - 1] + j*s[!(i&1)][j];
 			s[i&1][j] %= mod;
 			b[i] += s[i&1][j];
 			b[i]%=mod;
 		}
 	}

 	int ans = 0;

 	fr(i,0,n)
 	{
 		ans += C(n,i)*b[i];
 		ans %= mod;
 	}

 	cout<<ans<<"\n";
}