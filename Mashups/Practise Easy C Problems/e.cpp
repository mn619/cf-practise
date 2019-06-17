#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);

using namespace std;

signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

 	int a, b, c, x, y, z;
 	cin>>x>>y>>z;

 	a = min(x, min(y, z)), c = max(x, max(y, z));
 	b = x + y + z - a - c;

 	int m = (a + b + c)&1;
 	int e = c + ((c&1) != m);
 	int ans = ((c&1) != m);
 	a += ans;

 	ans += (e - a)/2 + (e - b)/2 + ((e - a)&1);
 	cout<<ans;
}