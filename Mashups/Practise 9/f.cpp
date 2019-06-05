#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);

using namespace std;

int n, a[200001];

int y, x;

int dis(int l, int k){
	return abs(l%y - k%y + y*(l%y == 0) - y*(k%y == 0)) + abs((l - 1)/y - (k - 1)/y);
}

signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

 	cin>>n;

 	int g = 0;

 	fr(i, 1, n + 1){
 		cin>>a[i];
 		if(i > 1){
 			int d = abs(a[i] - a[i - 1]);
 			if(d > 1) g = __gcd(d, g);
 		}
 	}

 	y = g;
 	if(y == 0){
 		int mx = 0;
 		fr(i, 1, n + 1){
 			mx = max(a[i], mx);
 		}
 		cout<<"YES\n";
 		cout<<mx<<" "<<1<<'\n';
 		return 0;
 	}

 	g = 0;
 	fr(i, 1, n + 1){
 		g = __gcd(g, a[i] - (a[i]%y) - y*(a[i]%y==0));
 	}

 	bool ok = 1;

 	fr(i, 2, n + 1){
 		if(dis(a[i], a[i - 1]) > 1) return cout<<"NO", 0;
 	}
 	x = g;

 	cout<<"YES\n";
 	cout<<x<<" "<<y<<'\n';

}