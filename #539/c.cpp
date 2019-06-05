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
 	map <int, int> dp0, dp1;
 	int p = 0;
 	dp0[p]++;
 	int ans = 0;
 	fr(i,1,n + 1)
 	{
 		int a;
 		cin>>a;
 		if(i&1)
 		{
 			p^=a;
 			ans += dp1[p];
 			dp1[p]++;
 		}
 		else p^=a, ans += dp0[p], dp0[p]++;
 	}
 	cout<<ans<<'\n';
}