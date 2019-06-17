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
 	int ans = 0, l = 0, r = 0, u = 0, d = 0;

 	fr(i, 1, n + 1){
 		char c;
 		cin>>c;

 		if(c == 'U') u++;
 		else if(c == 'D') d++;
 		else if(c == 'R') r++;
 		else l++;

 		ans = max(ans, 2*min(u, d) + 2*min(l, r));
 	}

 	cout<<ans;
}