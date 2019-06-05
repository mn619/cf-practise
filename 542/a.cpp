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
 	int z = 0, p = 0, ne = 0;

 	fr(i,1,n + 1)
 	{
 		int x;
 		cin>>x;
 		if(x > 0) p++;
 		if(x < 0) ne++;
 		if(x == 0) z++;
 	}
 	//cout<<p<<'\n';
 	if(p >= n/2 + (n%2 != 0)) cout<<1<<'\n';
 	else if(ne >= n/2 + (n%2 != 0)) cout<<-1;
 	else cout<<0<<'\n';
}