#include<bits/stdc++.h>
#define maxn 1000000
#define int long long
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); //freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
using namespace std;

int n, m, s, cur = 0, val[maxn + 1], sum[maxn + 1], dp[maxn + 1];
vector <pair<int, int>> g[maxn + 1], gr[maxn + 1], v[maxn + 1];
vector <bool> used(maxn + 1);
stack <int> st;

void dfs1 (int node) {
    used[node] = true;
    for (auto x: g[node])
        if (!used[x.first])
            dfs1 (x.first);
    st.push(node);
}

void dfs2 (int node) {
    used[node] = true;
    val[node] = cur;
    for (auto x: gr[node]){
        
        if(!used[x.first] or val[x.first] == cur){
            int t = x.second;
            int k = sqrt(t*2) - 1;
            if((k + 1)*(k + 2)/2 < t) k++;
            sum[cur] += (k + 1)*t - (k*(k + 1)*k/2 - k*(k + 1)*(2*k + 1)/6 + k*(k + 1)/2);
        }

        if (used[x.first])
            continue;

        dfs2 (x.first);
    }
}

void dfs(int node){
    dp[node] = sum[node];
    used[node] = 1;
    for(auto x: v[node]){
        if(!used[x.first])
            dfs(x.first);
        dp[node] = max(dp[node], sum[node] + x.second + dp[x.first]);
    }
}

signed main()
{
    #ifndef ONLINE_JUDGE
    FILEIO
    #endif
    FLASH

    cin>>n>>m;

    for(int i = 1; i <= m; i++){
        int x, y, w;
        cin>>x>>y>>w;
        g[x].push_back({y, w});
        gr[y].push_back({x, w});
    }
    
    cin>>s;

    for(int i = 1; i <= n; i++){
        if(!used[i])
            dfs1(i);
    }

    used.assign(n, 0);

    while(!st.empty()){
        int i = st.top();
        st.pop();
        if(used[i]) continue;
        ++cur;
        dfs2(i);
    }

    used.assign(n, 0);

    for(int i = 1; i <= n; i++)
        for(auto x: g[i]){
            if(val[i] == val[x.first]) continue;
            v[val[i]].push_back({val[x.first], x.second});
        }
    
    dfs(val[s]);

    cout<<dp[val[s]]<<'\n';
}