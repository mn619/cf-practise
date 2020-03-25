#include<bits/stdc++.h>
#define int long long
#define inf 1000000000000000000
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); //freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
using namespace std;

int n, cnt[21][21], pos[21][400001], dp[1<<20];
vector <int> v[21];

signed main(){
    // FILEIO
    FLASH

    cin>>n;    
    
    for(int i = 1; i <= n; i++){
        int a;
        cin>>a;
        a--;

        v[a].push_back(i);
        pos[a][i]++;
    }

    for(int i = 0; i < 20; i++){
        for(int j = 1; j <= n; j++){
            pos[i][j] += pos[i][j - 1];
        }
    }

    for(int i = 0; i < 20; i++){
        for(int j = 0; j < 20; j++){
            if(i == j) continue;
            for(auto x: v[i]){
                cnt[i][j] += pos[j][x];
            }
         }
    }

    dp[0] = 0;

    for(int i = 1; i < (1<<20); i++){
        dp[i] = inf;
        for(int j = 0; j < 20; j++){
            if(i>>j&1){
                int ans1 = 0;
                for(int k = 0; k < 20; k++){
                    if(k == j) continue;
                    if(i>>k&1) ans1 += cnt[j][k];
                }
                dp[i] = min(dp[i], dp[i^(1<<j)] + ans1);
            }
        }
    }

    cout<<dp[(1<<20) - 1];
}