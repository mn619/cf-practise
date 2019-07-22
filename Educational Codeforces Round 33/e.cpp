#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);

using namespace std;

int q, x, y, fac[2000001];
vector<int> d[1000001];
vector<bool> isprime(1000001, 1);


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

void compute(){
	for(int i = 2; i <= 1000000; i++){
		if(isprime[i]){
			d[i].pb(i);
			for(int j = 2*i; j <= 1000000; j +=i){
				isprime[j] = 0;
				d[j].pb(i);
			}
		}
	}

	fac[0] = 1;
	fr(i, 1, 2000001){
		fac[i] = (fac[i - 1] * i)%mod;
	}
}

int C(int n, int r){
	int ans = fac[n];
	ans *= power(fac[r], mod - 2, mod);
	ans %= mod;
	ans *= power(fac[n - r], mod - 2, mod);
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

 	cin>>q;
 	while(q--){
 		int x, y;
 		cin>>x>>y;
 		vector<int> cnt;
 		int temp = x;

 		for(auto z: d[x]){
 			int c = 0;
 			while(temp%z == 0){
 				c++;
 				temp /= z;
 			}
 			cnt.pb(c);
 		}

 		int ans = 1;
 		for(auto p: cnt){
 			ans *= C(p + y - 1, y - 1);
 			ans %= mod;
 		}

 		ans *= power(2, y - 1, mod);
 		ans %= mod;
 		cout<<ans<<'\n';
 	}
 	
}