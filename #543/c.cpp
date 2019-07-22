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

typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;

int n, k, a[1001];
ordered_set s;
pair<int, int> las[101];
vector <int> done[1000*150 + 1];
queue <int> q;
signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

	cin>>n>>k;

	fr(i, 1, n + 1){
		cin>>a[i];
		q.push(i);
	}	

	int ans = 0;

	fr(i, 1, 1000*150 + 1){
		fr(j, 1, k + 1){
			if(las[j] == {0, 0} and !q.empty()){
				int sub = q.front();
				q.pop();
				las[j] = {i, sub};
				done[i + a[sub]].pb(j);
				s.insert(i + a[sub]);
			}
			if(las[j] == {0, 0}) continue;

			int task = las[j].second;
			int m = s.order_of_key(i);
			int proc = i - las[j].first + 1;

			if(proc == round_(100*m, n)) ans++;
		}

		for(auto x: done[i]){
			las[x] = {0, 0};
		}
	}

