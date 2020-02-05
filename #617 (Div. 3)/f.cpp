#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

#define F first
#define S second
#define pb push_back
#define int long long
#define maxn 200000
#define mod 1000000007
#define inf 1000000000000000000

#define fr(i,a,b) for(int i=a;i<b;i++)
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); //freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
#define all(x) begin(x), end(x)
#define PII pair<int, int>
#define VI vector<int>
#define VII vector<PII>

using namespace std;

int n, m, f[maxn], par[maxn], par_edge[maxn], level[maxn];
vector <pair<int, int>> v[maxn];

void dfs(int node, int p, int h){
	par[node] = p;
	level[node] = h;

	for(auto x: v[node]){
		if(x.F == p) continue;
		par_edge[x.F] = x.S;
		dfs(x.F, node, h + 1);
	}
}

int lca(int a, int b){
	if(level[a] < level[b]) swap(a, b);

	while(level[a] != level[b]) a = par[a];;
	if(a == b) return a;

	while(par[a] != par[b])
		a = par[a], b = par[b];

	return par[a];
}

bool check(int a, int b, int g){
	int l = lca(a, b);
	int a1 = a, b1 = b;

	int mn = inf;
	while(a != l)
		mn = min(f[par_edge[a]], mn), a = par[a];
	while(b != l)
		mn = min(f[par_edge[b]], mn), b = par[b];

	if(mn == g) return 1;
	if(mn < g) return 0;

	a = a1, b = b1;
	while(a != l){
		if(f[par_edge[a]] == inf){
			f[par_edge[a]] = g;
			return 1;
		}
		a = par[a];
	}

	while(b != l){
		if(f[par_edge[b]] == inf){
			f[par_edge[b]] = g;
			return 1;
		}
		b = par[b];
	}

	return 0;
}

signed main()
{
    #ifndef ONLINE_JUDGE
    FILEIO
    #endif
    FLASH

    cin>>n;
    fr(i, 1, n){
    	f[i] = inf;
    	int a, b;
    	cin>>a>>b;
    	v[a].pb({b, i});
    	v[b].pb({a, i});
    }

    dfs(1, 0, 0);

    int m;
    cin>>m;

    vector <pair<int, pair<int, int>>> q;

    fr(i, 1, m + 1){
	    int a, b, g;
	    cin>>a>>b>>g;
	    q.pb({g, {a, b}});
    }

    sort(all(q));

    fr(i, 0, m){
    	int g = q[i].F, a = q[i].S.F, b = q[i].S.S;
    	if(!check(a, b, g)){
    		return cout<<-1, 0;
    	}
    }

    fr(i, 1, n){
    	if(f[i] == inf) f[i] = 1000000;
    }

    fr(i, 0, m ){
    	int g = q[i].F, a = q[i].S.F, b = q[i].S.S;

    	int l = lca(a, b);
    	int mn = inf;
		while(a != l)
			mn = min(f[par_edge[a]], mn), a = par[a];
		while(b != l)
			mn = min(f[par_edge[b]], mn), b = par[b];

		if(mn != g){
			return cout<<"-1\n", 0;
		}
    }

    fr(i, 1, n) cout<<f[i]<<" ";
}