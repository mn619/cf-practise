#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
#define maxn 200000

using namespace std;

int n, a[101];
map <int, vector<int>> v;

signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

 	cin>>n;
 	int tot = 0;
 	fr(i, 1, n + 1){
 		cin>>a[i];
 		tot += a[i];
 		if(i > 1) v[a[i]].pb(i);
 	}

 	int sum = a[1];
 	tot -= a[1];

 	vector<int> ans;
 	ans.pb(1);

 	fr(i, 1, a[1]/2 + 1){
 		for(auto x: v[i]){
 			ans.pb(x);
 			sum += a[x];
 			tot -= a[x];
 		}
 	}

 	if(sum > tot){
 		cout<<ans.size()<<'\n';
 		for(auto x: ans) cout<<x<<" ";
 	}
 	else cout<<0;

 	
}