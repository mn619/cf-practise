#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
#define maxn 200000

using namespace std;

int n, a, b, p[maxn];
vector<int> g[maxn + 1], gt[maxn + 1];
vector<bool> used;
vector<int> order, comp;
vector<bool> assignment;
map<int, int> m;

void dfs1(int v) {
    used[v] = true;
    for (int u : g[v]){
        if (!used[u])
        	dfs1(u);
    }
    order.push_back(v);
}

void dfs2(int v, int cl) {
    comp[v] = cl;
    for (int u : gt[v]) {
        if (comp[u] == -1)
            dfs2(u, cl);
    }
}
bool solve_2SAT() {
    used.assign(n, false);
    for (int i = 0; i < n; ++i) {
        if (!used[i])
            dfs1(i);
    }

      comp.assign(n, -1);
    for (int i = 0, j = 0; i < n; ++i) {
        int v = order[n - i - 1];
        if (comp[v] == -1)
            dfs2(v, j++);
    }

    assignment.assign(n / 2, false);
    for (int i = 0; i < n; i += 2) {
        if (comp[i] == comp[i + 1])
            return false;
        assignment[i / 2] = comp[i] > comp[i + 1];
    }
    return true;
}

signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

 	cin>>n>>a>>b;
 	fr(i, 0, n){
 		cin>>p[i];
 		m[p[i]] = i;
 	}

 	fr(i, 0, n){
 		if(m.count(a - p[i])){
 			int x = i, y = m[a - p[i]];
 			g[2*x].pb(2*y);
 			gt[2*y].pb(2*x);
 			g[2*y + 1].pb(2*x + 1);
 			g[2*x + 1].pb(2*y + 1);
 		}
 		else{
 			int x = i;
 			g[2*x].pb(2*x + 1);
 			gt[2*x + 1].pb(2*x);
 		}

 		if(m.count(b - p[i])){
 			int x = i, y = m[b - p[i]];
 			g[2*x + 1].pb(2*y + 1);
 			gt[2*y + 1].pb(2*x + 1);
 			g[2*y].pb(2*x);
 			gt[2*x].pb(2*y);
 		}
 		else{
 			int x = i;
 			g[2*x + 1].pb(2*x);
 			gt[2*x].pb(2*x + 1);
 		}
 	}

 	n *= 2;
	

 	if(solve_2SAT()) {
 		cout<<"YES\n";
 		fr(i, 0, n/2){
			cout<<!assignment[i]<<" ";
		}
 	}
 	else cout<<"NO\n";
	
	
}
 	