#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

#define F first
#define S second
#define pb push_back
#define int long long
#define maxn 200000
#define mod 1000000007
#define inf 1000000000000000000

#define fr(i,a,b) for(int i=a;i<b;i++)
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); //freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
#define all(x) begin(x), end(x)
#define PII pair<int, int>
#define VI vector<int>
#define VII vector<PII>

using namespace std;

int n, m, dp[1011][1001], sm[1011][1011];
signed main()
{
    #ifndef ONLINE_JUDGE
    FILEIO
    #endif
    FLASH

    cin>>n>>m;

    fr(l, 1, m + 1){
	    fr(i, 1, n + 1){
	    	fr(j, 1, i + 1){
	    		if(l == 1){
	    			dp[i][j] = 1;
	    			continue;
	    		}
	    		dp[i][j] = sm[i][j];
	    	}
	    }

	    for(int i = n; i >= 1; i--){
	    	for(int j = 1; j <= i; j++){
	    		sm[i][j] = sm[i][j - 1] + dp[i][j];
	    		sm[i][j] %= mod;
	    	}
	    }

	    for(int i = n; i >= 1; i--){
	    	for(int j = 1; j <= i; j++){
	    		sm[i][j] += sm[i + 1][j];
	    		sm[i][j]  %= mod;
	    	}
	    }
	}


	int ans = 0;
	fr(i, 1, n + 1){
		for(int j = 1; j <= i; j++){
			ans += dp[i][j];
			ans %= mod;
		}
	}

	cout<<ans<<'\n';
}