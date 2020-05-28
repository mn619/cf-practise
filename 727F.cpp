#include<bits/stdc++.h>
#define int long long
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); //freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
using namespace std;


int n, m, a[751], dp[751];

signed main()
{
    #ifndef ONLINE_JUDGE
    FILEIO
    #endif
    FLASH

    cin>>n>>m;

    for(int i = 1; i <= n; i++) cin>>a[i];

    vector <bool> in(n + 1, 1);

    for(int i = 1; i < n; i++){
        int maxminval = -1000000000000, maxminind = -1;
        for(int j = 1; j <= n; j++){
            if(!in[j]) continue;
            int minval = 1000000000000;
            int sum = 0;
            for(int k = 1; k <= n; k++){
                if((!in[k]) or k == j) continue;
                sum += a[k];
                if(minval > sum){
                    minval = sum;
                }
            }
            if(maxminval < minval){
                maxminval = minval;
                maxminind = j;
            }
        }

        in[maxminind] = 0;
        dp[i] = maxminval;
    }

    for(int i = 1, sum = 0; i <= n; i++){
        sum += a[i];
        dp[0] = min(dp[0], sum);
    }

    while(m--){
        int b;
        cin>>b;

        int ans = n;
        for(int i = 0; i < n; i++){
            if(dp[i] + b >= 0){
                ans = i;
                break;
            }
        }
        cout<<ans<<'\n';
    }
}