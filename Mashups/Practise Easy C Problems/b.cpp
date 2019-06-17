#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);

using namespace std;

int l, r;


int findodd(int a, int b){
	a %= mod;
	b %= mod;
	return (mod + (b*b)%mod - ((a - 1)*(a - 1))%mod)%mod;
}

int findeve(int a, int b){
	a %= mod;
	b %= mod;
	return (mod + (b*(b + 1))%mod - (a*(a - 1))%mod)%mod;
}

int find(int n){
	int p1 = 1, p2 = 1;
	int p = 1, cnt = 1;
	int ans = 0;

	while(n > 0){
		if(cnt&1){
			ans += findodd(p1, p1 + min(p - 1, n - 1));
			p1 += p;
		}
		else{
			ans += findeve(p2, p2 + min(p - 1, n - 1));
			p2 += p;
		}
		ans %= mod;
		n -= p;
		p *= 2;
		cnt++;
	}

	return ans;
}

signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH
 	
 	cin>>l>>r;
 	int ans = (mod + find(r) - find(l - 1))%mod;
 	cout<<ans;
}