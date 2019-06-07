#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);


using namespace __gnu_pbds;
using namespace std;
#define pii pair<int, int>
typedef tree<pii,null_type,less<pii>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;


int n, a[200001];
vector <int> v[200001];
ordered_set s;

signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

 	cin>>n;

 	fr(i, 1, n + 1){cin>>a[i]; v[i].pb(a[i]); v[i].pb(i);}
 	sort(v + 1, v + n + 1);


 	int ans = 0;
 	int p = 1;

 	fr(i, 1, n + 1){
 		int ep = v[i][0];
 		while(p <= n and p <= ep){
 			s.insert({-a[p], p});
 			p++;
 		}
 		
 		ans += s.order_of_key({-v[i][1], mod}) - (v[i][0] >= v[i][1]);
 	}

 	cout<<ans/2; 	
}