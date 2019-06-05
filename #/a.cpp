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

 	int x,y,z,a,b,c;
 	cin>>x>>y>>z>>a>>b>>c;

 	if(x > a) return cout<<"NO",0;
 	else a -= x, x = 0;

 	if(c > z)
 	{
 		z = 0;
 		if(a + b < y) return cout<<"NO\n", 0;
 		else cout<<"YES";
 		return 0;
 	}


 	z -= c;
 	c = 0;
 	if(y + z > a + b) return cout<<"NO", 0;
 	else cout<<"YES";

}