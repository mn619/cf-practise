#include<bits/stdc++.h>
#define mod 998244353
#define int long long
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); //freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
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
int n, k, fac[1000001];

int C(int n, int r){
	if(r < 0 or r > n) return 0;
	int ans = fac[n];
	ans *= power((fac[r]*fac[n - r])%mod, mod - 2, mod);
	ans %= mod;
	return ans;
}

signed main()
{
    #ifndef ONLINE_JUDGE
    FILEIO
    #endif
    FLASH

    fac[0] = 1;
    for(int i = 1; i <= 1000000; i++) fac[i] = (fac[i - 1]*i)%mod;
    	
    cin>>n>>k;

    int ans = 0;
	for(int i = 1; i <= n; i++){
		int t = n/i;
		ans += C(t - 1, k - 1);
		ans %= mod;
	}
	cout<<ans<<'\n';
}