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

using namespace __gnu_pbds;
using namespace std;

typedef tree<pii,null_type,less<pii>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;

ordered_set s;
int n, a[1000001], c[1000001];
map <int,int> cnt;

signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

 	cin>>n;
 	int ans = 0;
 	fr(i, 1, n + 1){
 		cin>>a[i];
 	}

 	for(int i = n; i >= 1; i--){
 		cnt[a[i]]++;
 		s.insert({cnt[a[i]], i});
 		c[i] = cnt[a[i]];
 	}
 	
 	cnt.clear();

 	fr(i, 1, n + 1){
 		cnt[a[i]]++;
 		s.erase({c[i], i});
 		int t = s.order_of_key({cnt[a[i]], 0});
 		ans += t;
 	}

 	cout<<ans;		
}