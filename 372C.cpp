#include<bits/stdc++.h>
#define int long long
#define inf 1000000000000000000
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); //freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
using namespace std;

int n, m, d, a[301], b[301], t[301];
int dp[2][150001];

signed main()
{
    #ifndef ONLINE_JUDGE
    FILEIO
    #endif
    FLASH

    cin>>n>>m>>d;
    t[0] = 1;

    for(int i = 1; i <= m; i++){
        cin>>a[i]>>b[i]>>t[i];

        deque <int> q;
        int D = min(d*(t[i] - t[i - 1]), n);
        
        for(int j = 1; j <= D; j++){
            while(!q.empty() and dp[(i&1)^1][q.back()] <= dp[(i&1)^1][j])
                q.pop_back();
            q.push_back(j);
        }

        for(int j = 1; j <= n; j++){
            while(!q.empty() and q.front() < j - D) q.pop_front();
            if(j + D <= n){
                while(!q.empty() and dp[(i&1)^1][q.back()] <= dp[(i&1)^1][j + D])
                    q.pop_back();
                q.push_back(j + D);
            }
            dp[i&1][j] = dp[(i&1)^1][q.front()] + b[i] - abs(j - a[i]);
        }
    }

    int ans = -inf;
    for(int i = 1; i <= n; i++){
        ans = max(ans, dp[m&1][i]);
    }
    cout<<ans<<'\n';
}