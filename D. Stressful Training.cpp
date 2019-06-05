#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);

using namespace std;
int n, k, a[200001], b[200001];
vector <int> charg[200001];

bool check(int x)
{
	fr(i, 1, n + 1)
	{
		if(a[i]/(x - b[i]) + 1 <= k) charg[max((int) 0, a[i]/(x - b[i]) + 1)].pb(a[i] + x - b[i]);
	}
	if(charg[0].size() > 0) return 0;
	
	fr(i, 1, n + 1)
	{
		
	}
	return 1;
}
signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

 	cin>>n>>k;

 	fr(i, 1, n + 1) cin>>a[i];
 	fr(i, 1, n + 1) cin>>b[i];


 	int l = 1, r = 1e13;

 	int ans = -1;
	fr(i, 1, n + 1) ;

 	while(l <= r)
 	{
 		int mid = (l + r)/2;
 		if(check(mid))
 		{
 			r = mid - 1;
 			ans = mid;
 		}
 		else l = mid + 1;
	}

	cout<<ans<<'\n';
}