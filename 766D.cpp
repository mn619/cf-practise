#include<bits/stdc++.h>
#define int long long
#define maxn 200000
#define inf 10000000000
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); //freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
using namespace std;

int n, m, q;
string a[maxn];
map<string, int> ind;

int sz[maxn];
pair<int, int> p[maxn];

int find_set(int v) {
    while(v != p[v].first){
    	v = p[v].first;
    }
    return v;
}

signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
	FLASH

	cin>>n>>m>>q;

	for(int i = 1; i <= n; i++){
		p[i] = {i, 0};
		sz[i] = 1;

		cin>>a[i];
		ind[a[i]] = i;
	}

	for(int i = 1; i <= m; i++){
		int t;
		cin>>t;

		string x, y;
		cin>>x>>y;
		int a = ind[x], b = ind[y];
		int cnt = 0;
		while(p[a].first != a){
			cnt += p[a].second;
			a = p[a].first;
		}

		while(p[b].first != b){
			cnt += p[b].second;
			b = p[b].first;
		}

		if(a == b){
			if((t&1) == (cnt&1)){
				cout<<"NO\n";
			}
			else cout<<"YES\n";
		}
		else{
			cout<<"YES\n";
			if(sz[a] > sz[b]){
				swap(a, b);
			}

			if(t == 1){
				if(cnt&1){
					p[a] = {b, 1}, sz[b] += sz[a];
				}
				else p[a] = {b, 0}, sz[b] += sz[a];
			}
			else{
				if(cnt&1){
					p[a] = {b, 0};
				}
				else p[a] = {b, 1};				
			}
		}
	}

	for(int i = 1; i <= q; i++){
		string x, y;
		cin>>x>>y;

		int a = ind[x], b = ind[y];

		int cnt = 0;
		while(a != p[a].first){
			cnt += p[a].second;
			a = p[a].first;
		}
		while(b != p[b].first){
			cnt += p[b].second;
			b = p[b].first;
		}

		if(a != b) cout<<"3\n";
		else if(cnt&1) cout<<"2\n";
		else cout<<"1\n";
	}
}
//Mahmoud wants to write a new dictionary that contains n 