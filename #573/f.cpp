#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
#define pii pair<int, int>
#define maxn 200000
 
using namespace __gnu_pbds;
using namespace std;
 
typedef tree<pii,null_type,less<pii>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;
 
int n, x[maxn + 1], y[maxn + 1], ans = 0;
map<int, vector<int> > v;
 
ordered_set s;
 
signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH
 
 	cin>>n;
 
 	fr(i, 1, n + 1){
 		cin>>x[i]>>y[i];
 		v[x[i]].pb(y[i]);
 	}
 
 	int l = v.size();
 
 	for(auto x: v){
 		int mx = 0;
 		for(auto y: x.second){
 			mx = max(mx, y);
 		}
 		s.insert({-mx, x.first});
 	}
 
	
 	for(auto x: v){
 		int mx = 0;
 		for(auto y: x.second){
 			mx = max(mx, y);
 		}
 		for(auto y: x.second){
 			ans += s.order_of_key({-(y - 1), 0});
 		}
 		s.erase({-mx, x.first});
 	}
 
 	cout<<ans;
}
