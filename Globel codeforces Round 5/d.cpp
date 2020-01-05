#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define inf 1000000000000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
#define pii pair<int, int>
#define maxn 1000000
using namespace __gnu_pbds;
using namespace std;

typedef tree<pii,null_type,less<pii>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;
typedef priority_queue <int, std::vector<int>, function<bool(int, int)>> custom_priority_queue; //custom priority_queue to sort elements in an order defined by custom bool function: Eg- custom_priority_queue pq(comp)

ordered_set s;
int n, a[maxn];
signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH
 	cin>>n;
 	fr(i, 1, n + 1) cin>>a[i];

 	
}