#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
#define maxn 200000

using namespace std;

int n, m, a[100], b[100], ans;


int check(vector <int> v){
	int ans = 0;

	set <pair<int, int>> s;
	fr(i, 1, m + 1){
		if(s.count({v[a[i]], v[b[i]]}) || s.count({v[b[i]], v[a[i]]})) continue;
		else {
			ans++;
			s.insert({v[a[i]], v[b[i]]});
		}
	}
	return ans;
}

signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

 	cin>>n>>m;

 	fr(i, 1, m + 1) {cin>>a[i]>>b[i]; a[i]--,b[i]--;}

 	int p = 1;
 	fr(i, 1, n + 1) p *= 6;

 	fr(i, 0, p + 1){
 		int mask = i;
 		vector <int> v;
 		fr(j, 0, n){
 			v.pb(mask%6);
 			mask /= 6;
 		}
 		ans = max(ans, check(v));
 	}
 	
 	cout<<ans;
}