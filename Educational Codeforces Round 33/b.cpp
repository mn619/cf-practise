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

 	int n;
 	cin>>n;

 	set <int> s;
 	int p = 2;
 	fr(i, 1, 16){
 		s.insert((p - 1)*(p/2));
 		p *= 2;
 	}

 	int ans = 0;
 	for(auto x: s){
 		if(n%x == 0) ans = x;
 	}
 	cout<<ans;
 	
}