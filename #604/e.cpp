#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 998244353
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
#define maxn 200000

using namespace std;

int power(int a, int b, int m)
{
    int ans = 1;
    a %= m;
    while(b){
        if(b & 1) ans = (ans * a) % m;
        a = (a * a) % m;
        b >>= 1;
    }
    return ans;
}

int n, p[maxn + 1], dp[maxn + 1];
signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

	cin>>n;
	fr(i, 1, n + 1) cin>>p[i];

	dp[1] = 100*power(p[1], mod - 2, mod);
	dp[1] %= mod;

	fr(i, 2, n + 1){
		dp[i] = (dp[i - 1] + 1)*power(p[i], mod - 2, mod);
		dp[i] %= mod;
		dp[i] *= 100;
		dp[i] %= mod;
	}

	cout<<dp[n]<<'\n';

}