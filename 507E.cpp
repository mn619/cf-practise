#include<bits/stdc++.h>
#define int long long
#define inf 100000000000000
#define maxn 100000
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); //freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
using namespace std;

int n, m;
pair<pair<int, int>, int> e[maxn + 1];
vector <pair<int, int>> v[maxn + 1];
vector <int> d1, dn;

vector <int> dij(int node){
    vector<int> dist(n + 1, inf);
    priority_queue<pair<int, int>> pq;

    pq.push({0, node});
    dist[node] = 0;

    while(!pq.empty()){
        int node = pq.top().second, d = -pq.top().first;
        pq.pop();
        
        for(auto x: v[node]){
            if(dist[x.first] > d + 1){
                pq.push({-d - 1, x.first});
                dist[x.first] = d + 1;
            }
        }
    }
    return dist;
}

vector<pair<int, int>> bfs(int l){
    vector <pair<int, int>> dp(n + 1, {inf, -1});
    dp[1] = {0, -1};
    deque<int> q;
    q.push_back(1);

    while(!q.empty()){
        int node = q.front();
        q.pop_front();

        for(auto x: v[node]){
            if(d1[x.first] + dn[x.first] > l) continue;
            if(e[x.second].second == 1 and dp[x.first].first > dp[node].first){
                q.push_front(x.first);
                dp[x.first] = {dp[node].first, x.second};
            }
            else if(e[x.second].second == 0 and dp[x.first].first > dp[node].first + 1){
                q.push_back(x.first);
                dp[x.first] = {dp[node].first + 1, x.second};
            }
        }
    }

    return dp; 
}

signed main()
{
    #ifndef ONLINE_JUDGE
    FILEIO
    #endif
    FLASH

    cin>>n>>m;
    int a = 0;
    for(int i = 1; i <= m; i++){
        int x, y, z;
        cin>>x>>y>>z;
        e[i] = {{x, y}, z};
        a +=  z;
        v[x].push_back({y, i});
        v[y].push_back({x, i});
    }

    d1 = dij(1), dn = dij(n);
    int l = d1[n];
    auto dp = bfs(l);

    assert(dn[1] == d1[n]);
    cout<<a - l + 2*dp[n].first<<'\n';

    // cout<<l<<'\n';
    // for(int i = 1; i <= n; i++){
    //     cout<<i<<" "<<d1[i]<<" "<<dn[i]<<'\n';
    // }
    // return 0;

    int node = n;
    set <int> in;


    int len = l;
    while(node != 1){
        len--;
        in.insert(dp[node].second);
        if(e[dp[node].second].first.first == node){
            node = e[dp[node].second].first.second;
        }
        else if(e[dp[node].second].first.second == node){
            node = e[dp[node].second].first.first;
        }
    }

    assert(len == 0);

    int b = 0;
    for(int i = 1; i <= m; i++){
        if(!in.count(i) and e[i].second == 1){
            b++;
            cout<<e[i].first.first<<" "<<e[i].first.second<<" 0\n";
        }
        else if(in.count(i) and e[i].second == 0){
            b++;
            cout<<e[i].first.first<<" "<<e[i].first.second<<" 1\n";
        }
    }

    assert(b == a - l + 2*dp[n].first);
}