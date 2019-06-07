#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);

using namespace std;

int a, b;

int lcm(int x, int y){
	return x*y/__gcd(x, y);
}

signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

	cin>>a>>b;

	if(a < b) swap(a, b);
	int d = a - b;

	int mn = lcm(a, b), ans = 0;

	for(int i = 1; i*i <= d; i++){
		if(d%i == 0){
			int g = i;
			int x = g*(a/g) + g*(a%g != 0);
			int k = x - a;
			int y = b + k;

			if(lcm(x, y) < mn){
				mn = lcm(x, y);
				ans = k;
			}

			g = d/i;
			x = g*(a/g) + g*(a%g != 0);
			k = x - a;
			y = b + k;

			if(lcm(x, y) < mn){
				mn = lcm(x, y);
				ans = k;
			}
		}
	}
	cout<<ans;
}