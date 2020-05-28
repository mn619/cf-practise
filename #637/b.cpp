#include<bits/stdc++.h>
#define  inf 1e15
#define int long long
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); //freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
using namespace std;

int f(vector <int> t){
	int ans = 0;
	for(auto x: t) ans += (1<<(x - 1));
	return ans;
}

int n, k, cnt[2001][10], dp[2001][2001];
string s[2001];
int dig[10];

signed main()
{
    #ifndef ONLINE_JUDGE
    FILEIO
    #endif
    FLASH

    cin>>n>>k;
    dig[0] = f({1, 2, 3, 5, 6, 7});
    dig[1] = f({3, 6});
    dig[2] = f({1, 3, 4, 5, 7});
    dig[3] = f({1, 3, 4, 6, 7});
    dig[4] = f({2, 3, 4, 6});
    dig[5] = f({1, 2, 4, 6, 7});
    dig[6] = f({1, 2, 4, 5, 6, 7});
    dig[7] = f({1, 3, 6});
    dig[8] = f({1, 2, 3, 4, 5, 6, 7});
    dig[9] = f({1, 2, 3, 4, 6, 7});
    

    for(int i = 1; i <= n; i++){
    	cin>>s[i];
    	int val = 0;
    	for(int j = 0; j < 7; j++){
    		if(s[i][j] == '1') val += (1<<j);
    	}

    	for(int j = 0; j < 10; j++){
    		int c = 0;
    		for(int k = 0; k < 7; k++){
    			if(!(dig[j]>>k&1)and (val>>k&1)) {
    				c = inf;
    				break;
    			}
    			c += ((dig[j]>>k&1) and !(val>>k&1));
    		}

    		cnt[i][j] = c;
    	}
    }

    for(int i = n; i >= 1; i--){
    	for(int j = 0; j <= k; j++){
    		dp[i][j] = -1;
    		if(i == n){
    			for(int k1 = 0; k1 < 10; k1++){
    				dp[i][j] = (cnt[i][k1] == j)? k1: dp[i][j];
    			}
    			continue;
    		}
    		for(int k1 = 0; k1 < 10; k1++){
    			if(cnt[i][k1] > j) continue;
    			if(cnt[i][k1] != inf and dp[i + 1][j - cnt[i][k1]] != -1){
    				dp[i][j] = k1;
    			}
    		}
    	}
    }

    if(dp[1][k] == -1) return cout<<"-1\n", 0;

    for(int i = 1; i <= n; i++){
    	cout<<dp[i][k];
    	k -= cnt[i][dp[i][k]];
    }

}