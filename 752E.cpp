#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

using namespace std;

int n, k;
int a[1000001];
int dp[10000001];

int cnt(int x){

    for(int i = 1; i < x; i++) dp[i] = 0;
    for(int i = x; i <= 10000000; i++){
        if(x == 1){
            dp[i] = i;
            continue;
        }

        if(i&1){
            int a = (i>>1);
            int b = a + 1;
            if(a < x and b < x)
                dp[i] = 1;
            else
                dp[i] = ((a >= x)? dp[a]: 0) + ((b >= x)? dp[b]: 0); 
        }
        else{
            int a = i>>1;
            if(a >= x)
                dp[i] = (dp[a] << 1);
            else
                dp[i] = 1;
        }
    }

    int ans = 0;
    for(int i = 1; i <= n; i++)
        ans += dp[a[i]];
    
    return ans;
}

signed main()
{
    // freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin);
    FLASH

    cin>>n>>k;  
    for(int i = 1; i <= n; i++) cin>>a[i];
    int l = 1, r = 1e7, ans = -1;

    while(l <= r){
        int mid = (l + r)>>1;
        if(cnt(mid) >= k){
            ans = mid;
            l = mid + 1;
        }
        else r = mid - 1;
    }

    cout<<ans<<'\n';
}