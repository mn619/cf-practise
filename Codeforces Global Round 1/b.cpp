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
 	int n,m,k;
 	cin>>n>>m>>k;
 	int a[n + 1];
 	fr(i,1,n + 1)
 	{
 		cin>>a[i];
 	}
 	int b[n + 1];
 	fr(i,2,n + 1)
 	{
 		b[i - 1] = a[i] - a[i - 1];
 	}

 	sort(b + 1, b + n);

 	int t = k;
 	k = n - k;

 	int ans = 0;
 	int cur = 1;
 	while(k--)
 	{
 		ans += b[cur];
 		cur++;
 	}

 	cout<<ans + t;


}