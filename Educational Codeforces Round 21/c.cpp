#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);

using namespace std;

int n, w, a[101], ans[101];

signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH
 	cin>>n>>w;
 	int minv = 0;

 	fr(i, 1, n + 1) {cin>>a[i]; minv += a[i]/2 + (a[i]&1);}

 	if(minv > w){
 		return cout<<-1,0 ;
 	}
 	vector <int> v[n + 1];

 	fr(i, 1, n + 1){
 		v[i].pb(a[i]);
 		v[i].pb(i);
 	}

 	sort(v + 1, v + n + 1);
 	reverse(v + 1, v + n + 1);

 	int rem = w - minv;
 	fr(i, 1, n + 1){
 		int x = v[i][0], ind = v[i][1];

 		ans[ind] = x/2 + (x&1);
 		int t = min(x - ans[ind], rem);
 		ans[ind] += t;
 		rem -= t;
 	}

 	fr(i, 1, n + 1) cout<<ans[i]<<" ";

}