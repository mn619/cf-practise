#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
#define maxn 200000

using namespace std;

signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

 	int t;
 	cin>>t;

 	while(t--){
 		int n, k1, k2;
 		cin>>n>>k1>>k2;
 		int ans;
 		fr(i, 1, k1 + 1){
 			int x;
 			cin>>x;
 			if(x == n) ans = 1;
 		}
  		fr(i, 1, k2 + 1){
 			int x;
 			cin>>x;
 			if(x == n) ans = 2;
 		}
 		if(ans == 1) cout<<"YES\n";
 		else cout<<"NO\n";	
 	}	
}