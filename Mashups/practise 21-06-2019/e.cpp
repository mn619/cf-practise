#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
#define maxn 200000


using namespace __gnu_pbds;
using namespace std;

typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;

int n, p[maxn + 1], q[maxn + 1];

signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

 	cin>>n;		
	map<int, int> m;
	fr(i, 1, n + 1) cin>>p[i];
	fr(i, 1, n + 1) {cin>>q[i]; m[q[i]] = i;}

	int ans = 0;

	fr(i, 1, n + 1){
		p[i] = m[p[i]];
	}
	ordered_set s;

	for(int i = n; i >= 1; i--){
		s.insert(p[i]);
		int les = s.order_of_key(p[i]), mor = s.size() - les - 1;
		ans = max(ans, (i + les - p[i] != 0)*(n - i + 1));
	}

	cout<<ans;
 	
}