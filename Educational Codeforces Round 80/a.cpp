#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

#define F first
#define S second
#define pb push_back
#define int long long
#define maxn 300000
#define mod 1000000007
#define inf 1000000000000000000

#define fr(i,a,b) for(int i=a;i<b;i++)
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); //freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
#define all(x) begin(x), end(x)
#define PII pair<int, int>
#define VI vector<int>
#define VII vector<PII>

using namespace std;

int n, m, a[maxn + 1][10];
pair <int, int> dp[300];

signed main()
{
    #ifndef ONLINE_JUDGE
    FILEIO
    #endif
    FLASH

    cin>>n>>m;
    fr(i, 1, n + 1){
    	fr(j, 0, m) cin>>a[i][j];

    	for(int mask = 0; mask < (1<<m); mask++){
    		int mn = inf;
    		fr(k, 0, m){
    			if(mask&(1<<k)){
    				mn = min(mn, a[i][k]);
    			}
    		}
    		if(dp[mask].F < mn){
    			dp[mask] = {mn, i};
    		}
    	}
    }


    int ans = 0, ind1, ind2;
    fr(mask, 0, 1<<m){
    	int rev = 0;
    	fr(j, 0, m) 
    	if(!(mask&(1<<j))) rev += (1<<j);

    	if(min(dp[mask].F, dp[rev].F) > ans){
    		ans = min(dp[mask].F, dp[rev].F);
    		ind1 = dp[mask].S;
    		ind2 = dp[rev].S;
    	}
    }

    cout<<ind1<<" "<<ind2;

}