#include<bits/stdc++.h>
#define int long long
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); //freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
using namespace std;

int n, a[200001], dp[200001];

signed main()
{
    #ifndef ONLINE_JUDGE
    FILEIO
    #endif
    FLASH

    cin>>n;

    int sm = 0;
    for(int i = 1; i <= n; i++){
    	cin>>a[i];
    	sm += a[i];
    }


    dp[n] = sm;
    int mx = sm;
    int ans = sm;
    for(int i = n - 1; i >= 2; i--){
    	sm -= a[i + 1];
    	dp[i] = sm - mx;
    	ans = max(ans, dp[i]);
    	mx = max(mx, dp[i]);
    }
    cout<<ans<<'\n';
}