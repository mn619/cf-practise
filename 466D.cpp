#include<bits/stdc++.h>
#define mod 1000000007
#define int long long
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); //freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
using namespace std;


int n, h, a[2010];
int dp[2011];

signed main()
{
    #ifndef ONLINE_JUDGE
    FILEIO
    #endif
    FLASH

    cin>>n>>h;
    for(int i = 1; i <= n; i++){
        cin>>a[i];
        a[i] = h - a[i];
    }
    dp[0] = 1;

    for(int i = 1; i <= n + 1; i++){
        if(abs(a[i] - a[i - 1]) > 1 or (a[i] < 0)) return cout<<"0\n", 0;
        if(a[i] == a[i - 1])
            dp[i] = dp[i - 1] + dp[i - 1]*a[i - 1];
        else if(a[i] == a[i - 1] - 1)
            dp[i] = a[i - 1]*dp[i - 1];
        else if(a[i] == a[i - 1] + 1)
            dp[i] = dp[i - 1];

        dp[i] %= mod;
    }

    cout<<dp[n + 1]<<'\n';
}