#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);

using namespace std;

int n, k, a, b;

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
 	
 	cin>>n>>k>>a>>b;

 	int mx = 1, mn = n*k;
 	fr(i, 0, n)
 	{
 		int pos = i*k + b;
 		int l = max(pos, a) - min(pos, a);
 		mx = max(mx, gcd(n*k, l));
 		mn = min(mn, gcd(n*k, l));
 	}
 	fr(i, 1, n + 1)
 	{
 		int pos = i*k - b;
 		int l = max(pos, a) - min(pos, a);
 		mx = max(mx, gcd(n*k, l));
 		mn = min(mn, gcd(n*k, l));
 	}
 	cout<<n*k/mx<<" "<<n*k/mn;
}