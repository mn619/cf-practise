#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
#define maxn 200000

using namespace std;

int n, x[maxn], y[maxn], c1[maxn], c[maxn], k[maxn], parent[maxn];

int dis(int a, int b){
	return abs(x[a] - x[b]) + abs(y[a] - y[b]);
}


int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b)
        parent[b] = a;
}



signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

 	cin>>n;

 	set <int> power;
 	vector <pair<int, int>> conn;

 	fr(i, 1, n + 1){
 		parent[i] = i;
 		cin>>x[i]>>y[i];
 	}
 	fr(i, 1, n + 1) {cin>>c[i]; c1[i] = c[i];}
 	fr(i, 1, n + 1) cin>>k[i];

 	vector <pair<int, pair<int, int>>> v;
	fr(i, 1, n + 1){
		int mn = c[i], mnconn = i;
		fr(j, i + 1, n + 1){
			v.pb({dis(i, j)*(k[i] + k[j]), {i, j}});
		}
	}

	sort(v.begin(), v.end());
	for(auto x: v){
		int cur = x.second.first, nex = x.second.second;
		if(find_set(cur) == find_set(nex)) continue;

		if(c[find_set(cur)] < c[find_set(nex)]){
			if(x.first  < c[find_set(nex)]){
				c[find_set(nex)] = c[find_set(cur)];	
				union_sets(cur, nex);
				conn.pb({cur, nex});
			}
		}
		else if(x.first  < c[find_set(cur)]){
				c[find_set(cur)] = c[find_set(nex)];	
				union_sets(cur, nex);
				conn.pb({cur, nex});
			}	
	}
	
	map <int, int> m;
	fr(i, 1, n + 1){
		if(!m.count(find_set(i))) m[find_set(i)] = c[i];
		else m[find_set(i)] = min(m[find_set(i)], c[i]);
	}

	for(auto x: m){
		fr(i, 1, n + 1){
			if(find_set(i) == x.first and x.second == c1[i]){
				power.insert(i);
				break;
			}
		}
	}
 	int ans = 0;

 	for(auto x: power) ans += c[x];
 	for(auto x: conn){
 		ans += dis(x.first, x.second)*(k[x.first] + k[x.second]);
 	}

 	cout<<ans<<'\n';
 	cout<<power.size()<<'\n';
 	for(auto x: power) cout<<x<<" ";
 	cout<<'\n';
 	cout<<conn.size()<<'\n';
 	for(auto x: conn){
 		cout<<x.first<<" "<<x.second<<'\n';
 	}
}