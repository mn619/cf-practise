#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);

using namespace std;

int n, m;

signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

 	cin>>n>>m;
 	int ans = mod;
 	fr(i, 1, m + 1){
 		int l, r;
 		cin>>l>>r;
 		ans = min(ans, r - l + 1);
 	}

 	cout<<ans<<"\n";
 	fr(i, 1, n + 1){
 		cout<<i%ans<<" ";
 	}
 	
}