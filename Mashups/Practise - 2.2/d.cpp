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


typedef tree<pair<int ,int>, null_type, less<pair<int ,int> >, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

int n, k, a[200001];
ordered_set s;

bool ans[200001];
signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

 	cin>>n>>k;
 	fr(i, 1, n + 1){
 		cin>>a[i];
 		s.insert({-a[i], i});
 	}

 	bool t = 0;

 	while(!s.empty()){
 		cout<<s.size()<<'\n';

 		pair <int, int> p = *s.find_by_order(0);
 		int ind = p.second - 1;
 		ans[ind] = t;

 		cout<<p.first<<" "<<p.second<<'\n';

 		s.erase(p);

 		int cnt = 1;

 		while(cnt <= k && ind >= 1){
 			if(!ans[ind]){
 				s.erase({-a[ind], ind});
 				ans[ind] = t;
 				cnt++;
 			}
 		 	ind--;
 		}

 		ind = p.second + 1;
 		cnt = 1;

 		while(cnt <= k && ind <= n){
 			if(!ans[ind]){
 				s.erase({-a[ind], ind});
 				ans[ind] = t;
 				cnt++;
 			}
 		 	ind++;
 		}

 		t = !t;
 	}

 	fr(i, 1, n + 1) cout<<ans[i] + 1<<'\n';

}