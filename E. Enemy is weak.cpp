#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
#define maxn 1000000

using namespace __gnu_pbds;
using namespace std;

typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;

int n, a[maxn + 1], les[maxn + 1];
ordered_set s;

signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

	cin>>n;
	fr(i, 1, n + 1){
		cin>>a[i];
		les[i] = i - s.order_of_key(a[i]) - 1;
		s.insert(a[i]);
	}
	s.clear();
	int ans = 0;

	for(int i = n; i >= 1; i--){
		ans += s.order_of_key(a[i])*les[i];
		s.insert(a[i]);
	}

	cout<<ans;
}