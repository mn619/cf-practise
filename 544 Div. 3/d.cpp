#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);

using namespace std;

int n, a[200001], b[200001];
map <pair<int, int>,int> m;

int abss(int x)
{
	if(x >= 0) return x;
	return -x;
}


int gcd(int a, int b)
{
	if(b == 0) return a;
	return gcd(b, a%b);
}


signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

 	cin>>n;
 	fr(i,1,n + 1) cin>>a[i];
 	fr(i,1,n + 1) cin>>b[i];

 	int temp = 0;
 	fr(i,1,n + 1)
 	{
 		if(a[i] == 0 && b[i] != 0) continue;
 		if(b[i] == 0) {m[{0, 0}]++; temp += (a[i] == 0); continue;}

 		int p = b[i],  q = a[i];
 		int g = gcd(abss(p), abss(q));

 		p /= g;
 		q /= g;

 		if(q < 0) {p *= -1; q *= -1;}
 		m[{p,q}]++;
 	}

 	int ans = 0;
 	for(auto x: m) ans = max(ans, x.second);
 	cout<<ans<<'\n';

}
