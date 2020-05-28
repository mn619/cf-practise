#include<bits/stdc++.h>
#define int long long
#define inf 100000000000000
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); //freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
using namespace std;

int t, dp[31][31][51];

signed main()
{
    #ifndef ONLINE_JUDGE
    FILEIO
    #endif
    FLASH
    for(int i = 1; i <= 30; i++)
    	for(int j = 1; j <= 30; j++)
    		for(int k = 1; k <= 50; k++)
    			dp[i][j][k] = inf;

    for(int i = 1; i <= 30; i++){
    	for(int j = 1; j <= 30; j++){
    		for(int k = 1; k <= min(i*j, (int)50); k++){
    			if(k == i*j){
    					dp[i][j][k] = 0;
    					continue;
				}

    			for(int l = 1; l <= i - 1; l++){
    				for(int m = 0; m <= k; m++){
    					dp[i][j][k] = min(dp[i][j][k], j*j + dp[i - l][j][m] + dp[l][j][k - m]);
    				}
    			}

    			for(int l = 1; l <= j - 1; l++){
    				for(int m = 0; m <= k; m++){
    					dp[i][j][k] = min(dp[i][j][k], i*i + dp[i][l][m] + dp[i][j - l][k - m]);
    				}
    			}
    		}
    	}
    }

    int t;

    cin>>t;

	while(t--){
		int n, m, k;
    	cin>>n>>m>>k;
    	cout<<dp[n][m][k]<<'\n';
	}	
}