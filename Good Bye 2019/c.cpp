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
 		int n;
 		cin>>n;
 		int sm = 0, xr = 0;
 		fr(i, 1, n + 1){
 			int a;
 			cin>>a;
 			sm += a;
 			xr ^= a;
 		}

 		if(sm == xr*2){
 			cout<<"0\n\n";
 		}
 		else
 		cout<<2<<'\n'<<xr<<" "<<(sm + xr)<<'\n';
 	}
}