#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
#define maxn 200000

using namespace std;
int v1, v2, t, d;	

signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

 	cin>>v1>>v2>>t>>d;
 	int ans = v1;

 	fr(i, 2, t + 1){
 		int rem = (t - i);
 		int nex = min(v1 + d, v2 + rem*d);
 		v1 = nex;
 		ans += v1;
 	}

 	cout<<ans; 	
}