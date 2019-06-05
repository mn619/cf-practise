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
	int a[n + 1];
	int mx = 0;
	fr(i,1,n + 1)
	{
		cin>>a[i];
		mx = max(a[i], mx);
	}

	int len = 0, ans = 0;
	fr(i,1,n + 1)
	{
		if(a[i] == mx)
		{
			len++;
		}
		else len = 0;
		ans = max(len, ans);
	}
	cout<<ans<<'\n';

}	