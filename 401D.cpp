#include<bits/stdc++.h>
#define int long long
#define mod 1000000007
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); //freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
using namespace std;

string s;
int m, dp[1<<18][101];


signed main()
{
	FILEIO
    FLASH

    cin>>s>>m;
    int n = s.size();
    vector <int> a;
    for(int i = 0; i < n; i++) a.push_back(s[i] - '0');

    for(int i = 1; i < (1<<n); i++){
		if(__builtin_popcount(i) == 1){
			for(int k = 0; k < n; k++){
				if((i>>k&1) and (a[k] != 0)){
					dp[i][a[k]%m] += 1;
				}
			}
		}
    	for(int j = 0; j < m; j++){
    		for(int k = 0; k < n; k++){
    			if(i>>k&1)
    				continue;
    			dp[i|(1<<k)][(j*10 + a[k])%m] += dp[i][j];
    		}
		}
    }
    
    int cnt[10] = {0};
    for(int i = 0; i < n; i++){
    	cnt[a[i]]++;
    }
    int ans = dp[(1<<n) - 1][0];

    for(int i = 0; i < 10; i++)
    	for(int j = 2; j <= cnt[i]; j++) ans /= j;
    
    cout<<ans<<'\n';
}