#include<bits/stdc++.h>
#define int long long
#define mod 998244353
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); //freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
using namespace std;

int n, k, dp[501][501], sm[501][501];
signed main()
{
    #ifndef ONLINE_JUDGE
    FILEIO
    #endif
    FLASH

    cin>>n>>k;
    dp[0][0] = 1;
    for(int i = 0; i <= n; i++) sm[0][i] = 1;

    for(int i = 1; i <= n; i++){
    	dp[i][1] = 1;
    	for(int j = 2; j <= i; j++){
    		for(int k = 1; k < j; k++){
    			dp[i][j] += dp[i - k][j];
    			dp[i][j] %= mod;
    		}
    		dp[i][j] += sm[i - j][j];
    	}
    	for(int j = 1; j <= n; j++){
    		sm[i][j] = dp[i][j] + sm[i][j - 1];
    		sm[i][j] %= mod;
    	}
    }

    int ans = 0;

    for(int i = 1; i <= n;i++){
    	ans += dp[n][i]*sm[n][min(n, k/i - (k%i == 0))];
    	ans %= mod;
    }

    ans *= 2;
    ans %= mod;
    cout<<ans;
}