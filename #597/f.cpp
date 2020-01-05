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
 		int l, r;
 		cin>>l>>r;
 		int ans = 0;
 		fr(i, l, r + 1){
 			fr(j, i + 1, r + 1){
 				if((i&j) == 0) ans++;
 			}
 		}

 		int ans1 = 0;
 		fr(i, l, r + 1){
 			fr(j, i + 1, r + 1){
 				if((i^j) == i + j)ans1++;
 			}
 		}
 		ans1 *= 2;
 		ans *= 2;

 		cout<<ans<<' '<<ans1<<'\n';
 	}	
}