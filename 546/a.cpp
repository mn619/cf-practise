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

 	vector <int> end[n + 1];

 	fr(i, 1, n + 1)
 	{
 		int l, r;
 		cin>>l>>r;
 		end[i].pb(r);
 	}

 	int x ;
 	cin>>x;

 	int ans = n;
 	fr(i, 1, n + 1)
 	{
 		if(end[i][0] >= x) break;
 		else ans--;
 	}

 	cout<<ans<<'\n';

}