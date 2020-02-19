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

vector <int> v[maxn];
int n, root, a[maxn], in[maxn], out[maxn], t[maxn], level[maxn];
int tim;

vector <pair<int, int>> seg[maxn*2 + 1];

void dfs(int node, int par, int l){
    level[node] = l;
    in[node] = ++tim;
    t[tim] = node;

    for(auto x: v[node]){
        if(x == par) continue;
        dfs(x, node, l + 1);
    }

    out[node] = tim;
}

void update(int ind, int l, int r, int node){
    if(l == r){
        seg[node].pb({level[t[ind]], a[t[ind]]});
        return;
    }

    int mid = (l + r)>>1;

    if(ind <= mid)
        update(ind, l, mid, 2*node);
    else
        update(ind, mid + 1, r, 2*node + 1);

    seg[node].pb({level[t[ind]], a[t[ind]]});
}

int queri(int l1, int r1, int max_level, int l, int r, int node){
    if(l1 > r or r1 < l) return inf;
    if(l1 <= l and r <= r1){
        int a = 0, b = (int)seg[node].size() - 1, ans = inf;
        while(a <= b){
            int c = (a + b)>>1;
            if(seg[node][c].F <= max_level){
                ans = seg[node][c].S;
                a = c + 1;
            }
            else b = c - 1;
        }

        return ans;
    }

    int mid = (l + r)>>1;
    return min(queri(l1, r1, max_level, l, mid, 2*node), queri(l1, r1, max_level, mid + 1, r, 2*node + 1));
}

signed main()
{
    #ifndef ONLINE_JUDGE
    FILEIO
    #endif
    FLASH

    cin>>n>>root;
    for(int i = 1; i <= n; i++) cin>>a[i];

    for(int i = 1; i < n; i++){
        int x, y;
        cin>>x>>y;

        v[x].pb(y);
        v[y].pb(x);
    }

    dfs(root, -1, 1);

    for(int i = 1; i <= n; i++) update(i, 1, n, 1);
    for(int i = 1; i < 2*n; i++) sort(all(seg[i]));

    for(int i = 1; i < 2*n; i++){
        for(int j = 1; j < (int)seg[i].size(); j++){
            seg[i][j].S = min(seg[i][j].S, seg[i][j - 1].S);
        }
    }

    int m;
    cin>>m;
    int las = 0;

    while(m--){
        int p, q;
        cin>>p>>q;
        int x = (p + las)%n + 1, k = (q + las)%n;
        las = queri(in[x], out[x], level[x] + k, 1, n, 1);
        cout<<las<<'\n';
    }
}