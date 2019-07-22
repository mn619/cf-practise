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

	int a[4], d;
	cin>>a[1]>>a[2]>>a[3]>>d;
	sort(a + 1, a + 4);

	int ans = max((int) 0, (d - (a[2] - a[1]))) +  max((int) 0, (d - (a[3] - a[2])));	
 	cout<<ans;
}