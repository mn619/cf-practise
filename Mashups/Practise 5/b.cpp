#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
#define debug(x) cout<<"["<<#x<<": "<<x<<"]"<<endl
#define pc __builtin_popcount
#define fi first
#define sc second
#define pi pair<int, int>
#define deb cout<<"Line: "<<__LINE__<<"\n"

using namespace __gnu_pbds;
using namespace std;


typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

int n, m, a[1001][1001];

ordered_set h[1001], v[1001];

signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

 	cin>>n>>m;

 	fr(i, 1, n + 1){
 		fr(j, 1, m + 1){
 			cin>>a[i][j];
 			h[i].insert(a[i][j]);
 		}
 	}

 	fr(j, 1, m + 1){
 		fr(i, 1, n + 1){
 			v[j].insert(a[i][j]);
 		}
 	}


 	fr(i, 1, n + 1){
 		fr(j, 1, m + 1){
 			int x = a[i][j];
 			int minh = h[i].order_of_key(x), minv = v[j].order_of_key(x), maxh = h[i].size() - h[i].order_of_key(x) - 1, maxv = v[j].size() - v[j].order_of_key(x) - 1;
 			cout<<max(minh, minv) + max(maxh, maxv) + 1<<" ";
 		}
 		cout<<'\n';
 	}
}