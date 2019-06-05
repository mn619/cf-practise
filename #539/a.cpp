#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define inf 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);

using namespace std;

signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

 	int n,v;
 	cin>>n>>v;
 	int ans[n+ 1] = {0}, lef[n + 1] = {0};
 	fr(i,1,min(n, v + 1) + 1) ans[i] = i;

 	fr(i,v + 2,n + 1)
 	{
 		ans[i] = inf;
 		fr(j,1,v + 1)
 		{
 			ans[i] = min()
 		}
 	}
}