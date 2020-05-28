#include<bits/stdc++.h>
#define int long long
#define pwr 1024
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); //freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
using namespace std;

int x, K, p;
double dp[2][1<<10][2][250];

signed main()
{
    #ifndef ONLINE_JUDGE
    FILEIO
    #endif
    FLASH

    cin>>x>>K>>p;
    int q = (100 - p);

    if(x < pwr) x |= (1<<13);
    if(x>>10&1){
        int cnt = 0;
        for(int j = 10; j < 31; j++) if(x>>j&1) cnt++; else break;
        dp[0][x%pwr][1][cnt] = 1;
    }
    else{
        int cnt = 0;
        for(int j = 10; j < 31; j++) if((x>>j&1) == 0) cnt++; else break;
        dp[0][x%pwr][0][cnt] = 1;
    }

    for(int i = 0; i < K; i++){
        for(int mask = 0; mask < pwr; mask++){
            for(int cnt = 1; cnt <= 240; cnt++){
                dp[!(i&1)][mask][0][cnt] = dp[!(i&1)][mask][1][cnt] = 0;
            }
        }

        for(int mask = 0; mask < pwr; mask++){
            for(int cnt = 1; cnt <= 240; cnt++){
                int mul = mask*2, add = mask + 1;
                if(mul < pwr){
                    dp[!(i&1)][mul][0][cnt + 1] += dp[i&1][mask][0][cnt]*p/100;
                    dp[!(i&1)][mul][0][1] += dp[i&1][mask][1][cnt]*p/100;
                }
                else{
                    dp[!(i&1)][mul%pwr][1][cnt + 1] += dp[i&1][mask][1][cnt]*p/100;
                    dp[!(i&1)][mul%pwr][1][1] += dp[i&1][mask][0][cnt]*p/100;
                }
                if(add < pwr){
                    dp[!(i&1)][add][0][cnt] += dp[i&1][mask][0][cnt]*q/100;
                    dp[!(i&1)][add][1][cnt] += dp[i&1][mask][1][cnt]*q/100;
                }
                else{
                    dp[!(i&1)][add%pwr][1][1] += dp[i&1][mask][0][cnt]*q/100;
                    dp[!(i&1)][add%pwr][0][cnt] += dp[i&1][mask][1][cnt]*q/100;
                }
            }
        }
    }


    double ans = 0;

    for(int mask = 0; mask < pwr; mask++){
        if(mask == 0){
            for(int cnt = 1; cnt <= 240; cnt++){
                ans += dp[K&1][mask][0][cnt]*(cnt + 10);
                ans += dp[K&1][mask][1][cnt]*10;
            }
            continue;
        }
        int c = 0;
        int temp = mask;
        while(temp%2 == 0) temp /= 2, c++;

        for(int cnt = 0; cnt <= 240; cnt++){
            ans += dp[K&1][mask][0][cnt]*c;
            ans += dp[K&1][mask][1][cnt]*c;
        }
    }

    cout<<fixed<<setprecision(15)<<ans<<'\n';
}