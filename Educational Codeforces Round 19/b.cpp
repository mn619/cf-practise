#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);

using namespace std;

int n;

signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH
 	cin>>n;
 	int emx = 0, omx = -100111, ans = 0;
 	fr(i, 1, n + 1)
 	{
 		int a;
 		cin>>a;
 		int e = emx, o = omx;
 		if(a&1)
 		{
 			omx = max(omx, a + e);
 			emx = max(emx, a + o);
 		}
 		else
 		{

 			omx = max(omx, a + o);
 			emx = max(emx, a + e);
 		}
 	}
 	
 	cout<<omx<<'\n';
}