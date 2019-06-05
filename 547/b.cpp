#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);

using namespace std;

int b[400001], n;

signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH
 	cin>>n;

 	fr(i, 1, n + 1)
 	{
 		cin>>b[i];
 		b[i + n] = b[i];
 	}

 	int l = 0, ans = 0;

 	fr(i, 1, 2*n + 1)
 	{
 		if(b[i] == 1) l++;
 		else l = 0;
 		ans = max(l, ans);
 	}
 	cout<<ans;
}