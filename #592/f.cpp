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
#define maxn 1000000
using namespace __gnu_pbds;
using namespace std;

typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;

int n, m;
priority_queue <pair<int, pii>> pq;
ordered_set row[maxn + 1], clm[maxn + 1];
pii lasx[maxn + 1], lasy[maxn + 1];

signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

 	cin>>n>>m;
 	int ans[n + 1][m + 1];

 	fr(i, 1, n + 1){
 		fr(j, 1, m + 1){
 			int a;
 			cin>>a;
 			pq.push({-a, {i, j}});
 			row[i].insert(a);
 			clm[j].insert(a);
 		}
 	}
 	
 	while(!pq.empty()){
 		auto p = pq.top();
 		pq.pop();
 		int a = -p.first, x = p.second.first, y = p.second.second;

 		int valx = row[x].order_of_key(a) + 1, valy = clm[y].order_of_key(a) + 1;
 		// cout<<valx<<" "<<valy<<' ';
 		if(valx == lasx[x].first and lasx[x].second != a) valx++;
 		if(valy == lasy[y].first and lasy[y].second != a) valy++;
 		
 		// cout<<a<<" "<<valx<<" "<<valy<<' '<<lasx[x].first<<" "<<lasy[y].first<<'\n';
 		ans[x][y] = max(valx, valy);
 		
 		lasx[x] = {ans[x][y], a};
 		lasy[y] = {ans[x][y], a};
 	}

 	fr(i, 1, n + 1){
 		fr(j, 1, m + 1) cout<<ans[i][j]<<" ";
 		cout<<'\n';
 	}
}