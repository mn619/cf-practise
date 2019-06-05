#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);

using namespace std;

int n;
vector <int> v[300001];

signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

	cin>>n;
	fr(i, 1, n + 1) {
		int a;
		cin>>a;
		v[i].pb(a);
		v[i].pb(i);
	}

	sort(v + 1, v + n + 1);
	reverse(v + 1, v + n + 1);

	int mxind = v[1][1], mnind = v[1][1];
	int ans = mod;

	fr(i, 2, n + 1){
		int ind = v[i][1];
		if(ind < mxind)ans = min(v[i][0]/(mxind - ind), ans);
		if(ind > mnind)ans = min(v[i][0]/(ind - mnind), ans);
		mxind = max(mxind, ind);
		mnind = min(mnind, ind);
	}

	cout<<ans<<'\n';


}