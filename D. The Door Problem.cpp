#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
#define maxn 200000

using namespace std;
int n, m, btn[maxn];
bool r[maxn];

vector<vector<int>> g(maxn), gt(maxn);
vector<bool> used;
vector<int> order, comp;
vector<bool> assignment;

void dfs1(int v) {
    used[v] = true;
    for (int u : g[v]) {
    	gt[u].pb(v);
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

 	cin>>n>>m;
 	fr(i, 1, n + 1) cin>>r[i], btn[i] = -1;

 	fr(i, 0, m){
 		int x;
 		cin>>x;
 		fr(j, 1, x + 1){
 			int room;
 			cin>>room;

 			if(btn[room] != -1){
 				if(r[room]){
 					g[2*i].pb(2*btn[room]);	
 					g[2*i + 1].pb(2*btn[room] + 1);
 					g[2*btn[room]].pb(2*i);
 					g[2*btn[room] + 1].pb(2*i + 1);
 				}
 				else{
 					g[2*i].pb(2*btn[room] + 1);
	 				g[2*i + 1].pb(2*btn[room]);
	 				g[2*btn[room]].pb(2*i + 1);
	 				g[2*btn[room] + 1].pb(2*i);
 				}
 			}
 			else btn[room] = i;
 		}
 	}
 	n = m*2;
 	if(solve_2SAT()) cout<<"YES\n";
 	else cout<<"NO\n";

}