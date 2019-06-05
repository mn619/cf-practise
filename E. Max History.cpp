#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
#define maxn 1000000

using namespace std;

int n, a[maxn + 1];
int fac[maxn + 1] = {1};

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
	fr(i, 1, maxn + 1) fac[i] = (i*fac[i - 1])%mod;
}

int C(int a, int b){
	if(b > a) return 0;
	return (fac[a]*power((fac[b]*fac[a - b])%mod, mod - 2, mod))%mod;
}
signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

 	cin>>n;	
 	fr(i, 1, n + 1) cin>>a[i];

 	sort(a + 1, a + n + 1);

 	int ans = 0;
 	int p = 0;

 	fr(i, 1, n + 1){
 		p += power(fac[i - 1], )
 		ans += 
 	}
}	