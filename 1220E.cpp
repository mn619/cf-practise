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
int w[maxn + 1], low[maxn + 1], tin[maxn + 1], comp[maxn + 1], sum[maxn + 1], sz[maxn + 1], dp[maxn + 1][2];
int s, tim = 0;
vector <bool> is_bridge(maxn + 1, 0), vis(maxn + 1, 0), ok(maxn + 1);
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

void dfs2(int node, int c){
    comp[node] = c;
    sz[c]++;
    vis[node] = 1;
    sum[c] += w[node];
    for(auto x: v[node]){
        if(vis[x.F] or is_bridge[x.S]) continue;
        dfs2(x.F, c);
    }
}

void dfs3(int node, int par = -1){
    for(auto x: t[node]){
    	if(x == par) continue;
    	dfs3(x, node);
    	if(ok[x]){
    		dp[node][0] += dp[x][0];
    	}
    	ok[node] = ok[node]|ok[x];
    }

    dp[node][0] += sum[node];
	
	int temp = 0;
    for(auto x: t[node]){
    	if(x == par) continue;
		temp = max(temp, dp[x][1] + ((!ok[x])?sum[x]:0));
	}

	dp[node][1] = temp;

	// cout<<node<<" "<<sum[node]<<" "<<dp[node][0]<<" "<<dp[node][1]<<'\n';
}


signed main()
{
    #ifndef ONLINE_JUDGE
    FILEIO
    #endif
    FLASH

    cin>>n>>m;
    fr(i, 1, n + 1) cin>>w[i];

    fr(i, 1, m + 1){
        int a, b;
        cin>>a>>b;
        e[i] = {a, b};
        v[a].pb({b, i});
        v[b].pb({a, i});
    }

    cin>>s;

    dfs(1);

    fr(i, 1, n + 1) vis[i] = 0;
    tim = 0;
    fr(i, 1, n + 1){
        if(vis[i]) continue;
        dfs2(i, ++tim);
    }

    fr(i, 1, m + 1){
        if(comp[e[i].F] == comp[e[i].S]) continue;
        t[comp[e[i].F]].pb(comp[e[i].S]);
        t[comp[e[i].S]].pb(comp[e[i].F]);
    }
    fr(i, 1, tim + 1) ok[i] = (sz[i] > 1);
    dfs3(comp[s]);

    int ans = dp[comp[s]][0] + dp[comp[s]][1];
    cout<<ans<<'\n';
}