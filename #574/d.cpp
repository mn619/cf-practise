#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 998244353
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
#define maxn 200000

using namespace std;

int n;

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
	int p = 0;
	int ans = 0;
	while(a){
		int d = a%10;
		a /= 10;
		ans += power(10, 2*p + 1, mod)*d;
		p++;
		ans %= mod;
	}
	ans *= n;
	ans %= mod;
	return ans;
}



int sum2(int a){
	int p = 0;
	int ans = 0;
	while(a){
		int d = a%10;
		a /= 10;
		ans += power(10, 2*p, mod)*d;
		p++;
		ans %= mod;
	}
	ans *= n;
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
 		int a;
 		cin>>a;
 		ans += sum1(a);
 		ans += sum2(a);
 		ans %= mod;
 	}

 	cout<<ans;
}