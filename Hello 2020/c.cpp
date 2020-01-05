#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

#define F first
#define S second
#define pb push_back
#define int long long
#define maxn 300000
#define inf 1000000000000000000

#define fr(i,a,b) for(int i=a;i<b;i++)
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); //freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
#define all(x) begin(x), end(x)
#define PII pair<int, int>
#define VI vector<int>
#define VII vector<PII>

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
int n, mod, fac[maxn] = {1};

int C(int n , int r){
	int ans = fac[n];
	ans *= power((fac[n - r]*fac[r])%mod, mod - 2, mod);
	ans %= mod;
	return ans;
}

signed main()
{
    #ifndef ONLINE_JUDGE
    FILEIO
    #endif
    FLASH


    cin>>n>>mod;
    fr(i, 1, maxn) fac[i] = (fac[i - 1]*i)%mod;

    int ans = 0;
    fr(i, 1, n + 1){
    	int temp = (n - i + 1)*(n - i + 1);
    	temp %= mod;
    	temp *= fac[i];
    	temp %= mod;
    	temp *= fac[n - i];	
    	temp %= mod;
    	ans += temp;
    	ans %= mod;
    }
    cout<<ans<<'\n';
}