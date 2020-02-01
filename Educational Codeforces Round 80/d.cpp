#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

#define F first
#define S second
#define pb push_back
#define int long long
#define maxn 300001
#define mod 1000000007
#define inf 1000000000000000000

#define fr(i,a,b) for(int i=a;i<b;i++)
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); //freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
#define all(x) begin(x), end(x)
#define PII pair<int, int>
#define VI vector<int>
#define VII vector<PII>

using namespace std;

int n, m, a[maxn][10];
pair<pair<int, int>, int> dp[300];

signed main()
{
    #ifndef ONLINE_JUDGE
    FILEIO
    #endif
    FLASH

    cin>>n>>m;

    fr(i, 0, n){
    	fr(j, 0, m) cin>>a[i][j];
    }

    for(int mask = 0; mask < (1<<m); mask++){
    	if(__builtin_popcount(mask) == 1){
    		int bit = 1;
    		fr(j, 0, m + 1){
    			if(mask&(1<<j)){
    				bit = j;
    				break;
    			}
    		}
    		vector <pair<int, int>> v;

    		fr(i, 0, n){
    			v.pb({a[i][bit], i});
    		}

    		sort(all(v));
    		dp[mask] = {{v[n - 2].S, v[n - 1].S}, v[n - 2].F};
    		cout<<
    	}
    	else{
    		dp[mask] = {{0, 0}, inf};
    		for(int j = 0; j < m; j++){
    			if(!(mask&(1<<j))) continue;
    			if(dp[mask^(1<<j)].S < dp[mask].S){
    				dp[mask] = dp[mask^(1<<j)];
    			}
    		}
    	}

    	cout<<mask<<" "<<dp[mask].F.F + 1<<" "<<dp[mask].F.S + 1<<'\n';
    }

}