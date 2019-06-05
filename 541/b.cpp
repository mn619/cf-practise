#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);

using namespace std;

int x[10001], y[10001], n;
signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

 	int n;
 	cin>>n;

 	int ans = 0;
 	fr(i,1,n + 1)
 	{
 		cin>>x[i]>>y[i];
 	}

 	fr(i,1,n + 1)
 	{
 		if(x[i - 1] == x[i] && y[i - 1] == y[i]) continue; 
 		int m1 = max(x[i - 1], y[i  - 1]), m2 = min(x[i], y[i]);
 		ans += max((int)0,  m2 - m1 + 1);
 		if(x[i] == y[i]) ans--;
 	}	
 	if(x[n] == y[n]) ans++;
 	cout<<ans<<'\n';

}