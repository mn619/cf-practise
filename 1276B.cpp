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

VII v[maxn + 1];
VI t[maxn + 1];
PII e[maxn + 1]; 
int w[maxn + 1], low[maxn + 1], tin[maxn + 1], sz[2];
int s, tim = 0;
vector <bool> is_bridge(maxn + 1, 0), vis(maxn + 1, 0);
int n, m;

void dfs(int node, int par = -1){
    tin[node] = ++tim;
    low[node] = tim;
    vis[node] = 1;

    for(auto x: v[node]){
        if(x.F == par) continue;
        if(vis[x.F]){
            low[node] = min(tin[x.F], low[node]);
        }
        else{
            dfs(x.F, node);
            low[node] = min(low[node], low[x.F]);
            if(low[x.F] > tin[node]) is_bridge[x.S] = 1;
        }
    }
}

void dfs2(int node, bool b){
    vis[node] = 1;
    sz[b]++;
    for(auto x: v[node]){
        if(is_bridge[x.S] or vis[x]) continue;
        dfs2(x.F, b);
    }
}

void solv(){
    cin>>n>>m>>x>>y;

    fr(i, 1, n + 1) v[i].clear();
    fr(i, 1, m + 1) is_bridge[i] = 0;

    fr(i, 1, m + 1){
        int a, b;
        cin>>a>>b;
        e[i] = {a, b};
        v[a].pb({b, i});
        v[b].pb({a, i});
    }

    dfs(1);

    tim = 0;

    fr(i, 1, n + 1) vis[i] = 0;

    dfs2(x, -1, 0);
    if(vis[y]){
        cout<<0<<'\n';
        return;
    }
    dfs2(y, -1, 1);
    cout<<sz[0]*sz[1]<<'\n';
}

signed main()
{
    #ifndef ONLINE_JUDGE
    FILEIO
    #endif
    FLASH

    int t;
    cin>>t;
    while(t--) solv();
    
}