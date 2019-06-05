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

 	int mx = 0;
 	fr(i, 1, 100000){
 		set<int> s;
 		bool ok = 1;
 		int las = mx;
 		fr(k, 1, i){
	 		if(s.find(i%k) != s.end()) ok = 0;
	 		else s.insert(i%k);
	 		mx = max(k, mx);
	 		//if(ok) cout<<k<<" ";
	 		if(!ok) break;
 		}
 		if(las < mx) {las = mx; cout<<i<<" "<<mx<<'\n';}
 		//cout<<'\n';
 	}
 	cout<<mx<<'\n';
}