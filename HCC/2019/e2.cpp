#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000000
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
#define maxn 200000

using namespace std;

int n, m, parent[maxn], rnk[maxn];
int x, y;
map<pair<int, int> , int> w;
vector<pair<int, pair<int, int>>> e;

int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (rnk[a] < rnk[b])
            swap(a, b);
        parent[b] = a;
        if (rnk[a] == rnk[b])
            rnk[a]++;
    }
}


signed main()
{
	FILEIO	
 	FLASH

 	cin>>n>>m;
 	fr(i, 1, m + 1){
 		int a, b, c;
 		cin>>a>>b>>c;
 		if(i == 1) x = a, y = b;
 		w[{a, b}] = c;
 	}
 	w[{x,y}] = mod;

 	for(auto z: w){
		e.pb({z.second, {z.first.first, z.first.second}});
	}

	sort(e.begin(), e.end());
	int ans;
 	fr(i, 1, n + 1) parent[i] = i, rnk[i] = 0;
	
	for(auto z: e){
		int p = z.second.first, q = z.second.second;
		if(find_set(p) == find_set(q)) continue;
		else{
			union_sets(p, q);
		}
		if(find_set(x) == find_set(y)){
			ans = z.first;
			break;
		}
	}

 	cout<<ans;
}
