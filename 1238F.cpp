#include<bits/stdc++.h>
#define int long long
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); //freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
using namespace std;

int n, dp[300001], ans;
vector <int> v[300001];

void dfs(int node, int par){
    int c = 0;
    for(auto x: v[node])
        if(x == par) continue;
        else c++;
    
    vector <int> temp;
    dp[node] = c + 1;

    for(auto x: v[node]){
        if(x == par) continue;
        dfs(x, node);
        temp.push_back(dp[x]);
        dp[node] = max(dp[node], dp[x] + c);
    }

    ans = max(ans, dp[node]);
    sort(temp.begin(), temp.end(), greater<>());
    if(c > 1)
        ans = max(ans, temp[0] + temp[1] + (int)v[node].size() - 1);
}

void solv(){
    cin>>n;

    for(int i = 1; i < n; i++){
        int a, b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    if(n == 2){
        cout<<"2\n";
        ans = 0;
        for(int i = 1; i <= n; i++)
            v[i].clear();
        return;
    }

    dfs(1, -1);

    cout<<ans<<'\n';
    ans = 0;
    for(int i = 1; i <= n; i++) v[i].clear();
}
signed main()
{
    #ifndef ONLINE_JUDGE
    FILEIO
    #endif
    FLASH

    int t;

    cin>>t;
    while(t--)  solv();
}
    