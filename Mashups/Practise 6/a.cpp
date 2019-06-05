#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);

using namespace std;

int n, x[300001];
vector <int> v[300001];

signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

 	cin>>n;

 	fr(i, 1, n + 1){
 		int a;
 		x[i] = a;

 		cin>>a;
 		v[i].pb(a);
 		v[i].pb(i);
 	}

 	sort(v + 1, v + n + 1);
 	reverse(v + 1, v + n + 1);

 	int ans = (int)100000*10000;

 	set <int> s;
 	s.insert(v[1][1]);

 	fr(i, 2, n + 1){
 		int a = v[i][0];
 		int p = v[i][1];
 		s.insert(p);

 		auto it = s.begin();

 		if(p > *it) ans = min(ans, a/(p - *it));

 		it = s.end();
 		it--;
 		if(p < *it) ans = min(ans, a/(*it - p));
 	}

 	cout<<ans;

}