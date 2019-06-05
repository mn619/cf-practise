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

 	int n, d, m;
 	cin>>n>>d>>m;

 	while(m--){
 		int x, y;
 		cin>>x>>y;


 		if( d <= x + y and x + y <= 2*n - d and -d <= y - x and y - x  <= d) cout<<"YES\n";
 		else cout<<"NO\n";
 	}


}