#include<bits/stdc++.h>
#define int long long
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); //freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
using namespace std;

int power(int a, int b, int m)
{
    int ans = 1;
    a %= m;
    while(b){
        if(b & 1) ans = (ans * a) % m;
        a = (a * a) % m;
        b >>= 1;
    }
    return ans;
}
int n, k, m, dp[1001][100], pwr[1010];

int f(int i){
    int d = n - i;
    if(d == 0) return 1;
    if(d == 1) return 9;
    int ans = 9*power(10, d - 1, m);
    ans %= m;
    return ans;
}

signed main()
{
    #ifndef ONLINE_JUDGE
    FILEIO
    #endif
    FLASH

    cin>>n>>k>>m;

    pwr[0] = 1;
    for(int i = 1; i <= 1000; i++) pwr[i] = (pwr[i - 1]*10)%k;


    for(int i = 1; i < 10; i++)
        dp[1][i%k]++;

    int ans = 0;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j < k; j++){
            for(int d = 0; d < 10; d++){
                dp[i + 1][(j + pwr[i]*d)%k] += dp[i][j];
                dp[i + 1][(j + pwr[i]*d)%k] %= m;
            }
        }
        
        for(int d = 1; d < 10; d++)
           dp[i + 1][(pwr[i]*d)%k]++;


        ans += dp[i][0]*f(i);
        ans %= m;
    }

    cout<<ans<<'\n';
}