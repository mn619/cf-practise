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

 	int x0, y0;
 	cin>>x0>>y0;
 	int a = y0, b = y0, c = y0;
 	int ans = 0;
 	while(min(a, min(b,c)) < x0){
 		ans++;
 		int x = min(a, min(c,b)), z = max(a, max(b,c)), y = a + b + c - x - z;
 		a = x, b = y, c = z;
 		a = min(b + c - 1, x0);
 		//cout<<a<<" "<<b<<" "<<c<<'\n';
 	}
 	cout<<ans;
}