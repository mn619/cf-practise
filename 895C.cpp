#include<bits/stdc++.h>
#define maxn 100000
#define mod 1000000007
#define int long long
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); //freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
using namespace std;


int n, cnt[71], m[71], pwr[maxn + 1];
vector <int> p = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37 ,41, 43, 47, 53, 57, 59, 61, 67};

vector <vector<int> > dp(2, vector<int>(1<<20, 0));

signed main()
{
    #ifndef ONLINE_JUDGE
    FILEIO
    #endif
    FLASH
    pwr[0] = 1;
    for(int i = 1; i <= maxn; i++) pwr[i] = (2*pwr[i - 1])%mod;

    cin>>n;

    for(int i = 1; i <= 70; i++){
        int temp = i;

        int mask = 0;
        for(int j = 0; j < 20; j++){
            bool ok = 0;
            while(temp%p[j] == 0){
                ok ^= 1;
                temp /= p[j];
            }
            if(ok) mask |= (1<<j);
        }
        m[i] = mask;
    }

    for(int i = 1; i <= n; i++){
        int a;
        cin>>a;
        cnt[a]++;
    }
    dp[0][0] = 1;
    for(int i = 1; i <= 70; i++){
        if(cnt[i] == 0) continue;
        for(int j = 0; j < (1<<20); j++){
            dp[1][j] = pwr[cnt[i] - 1]*(dp[0][j] +  dp[0][m[i]^j]);
            dp[1][j] %= mod;
        }
        dp[0] = dp[1];
    }
    int ans = mod + dp[0][0] - 1;
    ans %= mod;
    cout<<ans;
}