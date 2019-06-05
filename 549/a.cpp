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
 	
 	int z = 0, o = 0;
 	int a[n + 1];
 	fr(i, 1, n + 1)
 	{
 		int t;
 		cin>>t;
 		a[i] = t;
 		if(t == 0) z++;
 		else o++;
 	}

 	int zc = 0, oc = 0;
 	fr(i, 1, n+ 1)
 	{
 		if(a[i] == 0) zc++;
 		else oc++;
 		if(zc == z || oc == o) return cout<<i, 0;
 	}
}