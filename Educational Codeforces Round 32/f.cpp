#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);

using namespace std;

int power(int a, int b, int m)
{
    int ans = 1;
    a %= m;
    b %= m - 1;

    while(b){
        if(b & 1) ans = (ans * a) % m;
        a = (a * a) % m;
        b >>= 1;
    }
    return ans;
}

signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

 	int A, B, n, x;
 	cin>>A>>B>>n>>x;

 	int ans = (power(A, n, mod)*x)%mod;
 	if(A == 1){
 		ans += ((n%mod)*B)%mod;
 		ans %= mod;
 	}
 	else {
 		int  t = B*(power(A, n, mod) - 1);
 		t %= mod;
 		t *= power(A - 1, mod - 2, mod);
 		t %= mod;
 		ans += t;
 		ans %= mod;
 	}

 	cout<<ans;
}