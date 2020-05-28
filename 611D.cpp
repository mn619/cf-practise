#include<bits/stdc++.h>
#define int long long
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); //freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
using namespace std;

int n, s[5011];
int dp[5011][5011], c[5011][5011];

signed main()
{
    #ifndef ONLINE_JUDGE
    FILEIO
    #endif
    FLASH

    cin>>n;
    
    for(int i = 1; i <= n; i++){
        char c;
        cin>>c;
        s[i] = (int)c - '0';
    }
    s[n + 1] = 10;

    for(int i = n + 1; i >= 1; i--){
        for(int j = i - 1; j >= 1; j--){
            if(s[i] != s[j]){
                c[j][i] = 0;
            }
            else{
                c[j][i] = 1 + c[j + 1][i + 1];
            }
        }
    }
    
    // for(int i = 1; i <= n; i++){
    //     for(int j = 1; j < i; j++)
    //         cout<<c[i][j]<<" ";
    //     cout<<'\n';
    // }

    for(int i = 0; i <= n; i++) dp[0][i] = 1;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= i; j++){
            dp[i][j] = dp[i][j - 1];
            if(s[i - j + 1] == 0) continue;
            if(i - 2*j + 1>= 1){
                int d = c[i - 2*j + 1][i - j + 1];
                if(i - j + 1 + d <= i and s[i - 2*j + 1 + d] < s[i - j + 1 + d]){
                    dp[i][j] += dp[i - j][j];
                }
                else{
                    dp[i][j] += dp[i - j][j - 1];
                }
            }
            else{
                dp[i][j] += dp[i - j][j];
            } 
            dp[i][j] %= mod;
        }
        for(int j = i + 1; j <= n; j++) dp[i][j] = dp[i][j - 1];
    }
    int ans = dp[n][n]%mod;
    cout<<ans<<'\n';
}