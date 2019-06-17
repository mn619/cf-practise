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

 	map<int, int> d;

 	int n, m, k;
 	cin>>n>>m>>k;

 	fr(i, 1, n + 1){
 		int t;
 		cin>>t;
 		d[t]++;
 	}

 	fr(i, 1, m + 1){
 		int t;
 		cin>>t;
 		d[t]--;
 	}

 	vector<int> v;
 	for(auto x: d){
 		v.pb(x.second);
 	}
 	reverse(v.begin(), v.end());
 	v.pb(0);
 	int sum = v[0];
 	fr(i, 1, v.size()){
 		if(sum > 0) return cout<<"YES", 0;
 		sum += v[i];
 	}


 	cout<<"NO";
}