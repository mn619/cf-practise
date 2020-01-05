#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
#define maxn 200000

using namespace std;

int w[maxn];
set <pair<int, int>> s;
map <pair<int, int>, int> m;
set <pair<int, int>> v[maxn];

void solv(){
	int n, k;
	cin>>n>>k;

	m.clear();
	s.clear();

	fr(i, 1, n + 1){
		v[i].clear();
		w[i] = 0;
	}

	fr(i, 1, n){
		int a, b, c;
		cin>>a>>b>>c;
		m[{a, b}] = m[{b, a}] = c;
		v[a].insert({c, b});
		v[b].insert({c, a});
	}

	fr(i, 1, n + 1){
		vector <pair<int, int>> ed;
		for(auto x: v[i]) ed.pb(x);

		sort(ed.begin(), ed.end());
		reverse(ed.begin(), ed.end());

		fr(j, 0, k){
			w[i] += ed[j].first;
			v[i].erase(ed[j]);
		}

		cout<<'\n';
		s.insert({w[i], i});
	}

	fr(i, 1, n + 1) cout<<w[i]<<" ";
	cout<<'\n';
	

	int ans = 0;
	while(!s.empty()){
		auto it = prev(s.end());
		int node = (*it).second;
		cout<<node<<" "<<(*it).first<<'\n';
		ans += (*it).first;
		s.erase(it);

		for(auto x: v[node]){
			int node2 = x.second, weight = x.first;
			if(!v[node2].count({weight, node})){
				s.erase({w[node2], node2});
				w[node] -= weight;
				if(!v[node2].empty()){
					w[node2] += (*prev((v[node2].end()))).first;
					v[node2].erase(prev(v[node2].end()));
				}
				s.insert({w[node2], node2});
			}
		}

	}


	cout<<ans<<'\n';

}
signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

 	int q;
 	cin>>q;

 	while(q--)
 	 solv();	
}