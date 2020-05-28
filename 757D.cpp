#include<bits/stdc++.h>
#define mod 1000000007
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); //freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
using namespace std;

int n, dp[76][1<<20];
string s;
signed main()
{
    #ifndef ONLINE_JUDGE
    FILEIO
    #endif
    FLASH

    cin>>n>>s;
    
    reverse(s.begin(), s.end());
    s += '$';
    reverse(s.begin(), s.end());


    for(int i = 0; i <= n; i++)
    	dp[i][0] = 1;
    
    int ans = 0;
    for(int i = 0; i <= n; i++){
    	for(int j = 0; j < 1<<20; j++){
    		if(dp[i][j] == 0) continue;
    		int num = 0;
    		for(int k = i + 1; k <= n; k++){
    			num = 2*num + (s[k] == '1');
    			if(num == 0){
    				continue;
    			}
    			if(num > 20) break;
    			dp[k][j|(1<<(num - 1))] += dp[i][j];
    			dp[k][j|(1<<(num - 1))] %= mod;
    		}
    	}

    	for(int p = 2; p < 1<<20; p *= 2)
    		ans += dp[i][p - 1], ans %= mod;
    }
    cout<<ans<<'\n';
}