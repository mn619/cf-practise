#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 998244353
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
#define maxn 200000

using namespace std;

int n, lencnt[11], big[11], smol[11], a[maxn];

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

int sum1(int a){
	int p = 1;
	int ans = 0;
	while(a){
		int d = a%10;
		a /= 10;
		int pwr = power(10, 2*p - 1, mod);
		ans += d*big[p]*pwr + (((a*lencnt[p])%mod)*((10*pwr)%mod))%mod;
		p++;
		ans %= mod;
	}
	ans %= mod;
	return ans;
}

int sum2(int a){
	int p = 1;
	int ans = 0;

	while(a){
		int d = a%10;
		a /= 10;
		int pwr = power(10, 2*p - 2, mod);
		ans += (d*big[p]*pwr)%mod + (((a*lencnt[p])%mod)*((100*pwr)%mod))%mod;
		p++;
		ans %= mod;
	}
	ans %= mod;
	return ans;
}

signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

 	cin>>n;
 	int ans = 0;

 	fr(i, 1, n + 1){
 		string x;
 		cin>>x;
 		a[i] = stoi(x);
 		lencnt[x.size()]++;
 	}

 	fr(i, 1, 11) smol[i] = smol[i - 1] + lencnt[i];
 	for(int i = 10; i >= 1; i--) big[i] = big[i + 1] + lencnt[i];

 	fr(i, 1, n + 1){
 		ans += sum1(a[i]) + sum2(a[i]);
 		ans %= mod;
 	}
 	cout<<ans;
}