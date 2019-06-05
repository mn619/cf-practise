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

 	int n, m, k;
 	cin>>n>>m>>k;

 	if(2*n*m%k != 0) return cout<<"NO", 0;

 	cout<<"YES\n";
 	cout<<"0 0\n";

 	if(__gcd(n, k) > 1){
 		int g = __gcd(2*n, k);
 		cout<<2*n/__gcd(2*n, k)<<" 0\n0 "<<m/(k/g);
 	}
 	else{
 		int g = __gcd(2*m, k);
 		cout<<n/(k/g)<<" 0\n0 "<<2*m/__gcd(2*m, k);
 	}
}