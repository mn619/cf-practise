#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);

#define p 47 //is a prime?
#define q 41 // is a prime?

using namespace std;

int hp[1000001], hq[1000001], n, m, ans = 0;
int pwrp[1000001], pwrq[1000001];
map<pair<int, int>, int> hcnt;

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

signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

 	cin>>n>>m;

 	fr(i, 1, n + 1){
 		pwrp[i] = power(p, i, mod);
 		pwrq[i] = power(q, i, mod);
 	}

 	fr(i, 1, m + 1){
 		int a, b;
 		cin>>a>>b;
 		hp[a] += pwrp[b];
 		hp[b] += pwrp[a];

 		hq[a] += pwrq[b];
 		hq[b] += pwrq[a];

 	}

 	fr(i, 1, n + 1){
 		hcnt[{hp[i], hq[i]}]++;
 	}


 	for(auto x: hcnt){
 		ans += x.second*(x.second - 1)/2;
 	}


 	hcnt.clear();

 	fr(i, 1, n + 1){
 		hp[i] += pwrp[i];
 		hq[i] += pwrq[i];
 	}

 	fr(i, 1, n + 1){
 		hcnt[{hp[i], hq[i]}]++;
 	}

 	for(auto x: hcnt){
 		ans += x.second*(x.second - 1)/2;
 	}

 	cout<<ans;
 	
}