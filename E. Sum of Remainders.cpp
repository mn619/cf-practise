#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);

using namespace std;

int inv = 500000004;

int presum(int a)
{
	a %= mod;
	int ret = a*(a + 1);
	ret %= mod;
	ret *= inv;
	ret %= mod;
	return ret;
}

signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH
 	inv = 500000004;
	int n,m;
	cin>>n>>m;
	
	int ans = ((n%mod)*(m%mod))%mod;
	
	for(int i = min(m,n);i >= 1;)
	{
		int x = n/i;
		int temp = presum(min(m,n/x)) - presum(min(m,n/(x + 1)));
		temp %= mod;
		temp *= (x%mod);
		temp %= mod;
		ans -=  temp;
		ans %= mod;
		i = n/(x + 1);
	}

	ans += mod;
	ans %= mod;
	cout<<ans<<"\n";

}
