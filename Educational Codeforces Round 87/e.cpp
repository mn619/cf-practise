#include<bits/stdc++.h>
#define int long long
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); //freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
using namespace std;


int n, m, a, b, c, cnt[5001][2], comp[5001], t;
int ptr[5001][5001];
vector <int> clr(5001, -1);
vector <int> v[5001];

void dfs(int node, int c){
	comp[node] = t;
	cnt[t][c]++;
	clr[node] = c;

	for(auto x: v[node]){
		if(clr[x] == c) {
			cout<<"NO\n";
			exit(0);
		}
		if(clr[x] != -1) continue;

		dfs(x, 1 - c);
	}
}

signed main()
{
    #ifndef ONLINE_JUDGE
    FILEIO
    #endif
    FLASH

    cin>>n>>m;
    cin>>a>>b>>c;

    for(int i = 1; i <= m; i++){
    	int x, y;
    	cin>>x>>y;
    	v[x].push_back(y);
    	v[y].push_back(x);

    }

    for(int i = 1; i <= n; i++){
    	if(clr[i] == -1) t++, dfs(i, 0);
    }

    vector <vector<bool>> dp(n + 1, vector <bool> (n + 1, 0));

    dp[0][0] = 1;
    for(int i = 1; i <= t; i++){
    	for(int j = 0; j <= n; j++){
    		if(j >= cnt[i][0] and dp[i - 1][j - cnt[i][0]]){
    			dp[i][j] = dp[i - 1][j - cnt[i][0]];
    			ptr[i][j] = 0;
    		}
    		if(j >= cnt[i][1] and dp[i][j] == 0 and dp[i - 1][j - cnt[i][1]]){
    			dp[i][j] = dp[i - 1][j - cnt[i][1]];
    			ptr[i][j] = 1;
    		}
    	}
    }


    if(dp[t][b] == 0){
    	cout<<"NO\n";
    	return 0;
    }

    vector <int> ans(n + 1, -1);
	cout<<"YES\n";
	
	int x = t;
	while(x >= 1){
		if(cnt[x][0] == 0 and cnt[x][1] == 0){
			x--;
			continue;
		}

 		assert(dp[x][b]);

		if(ptr[x][b] == 0){
			for(int i = 1; i <= n; i++){
				if(comp[i] == x and clr[i] == 0){
					ans[i] = 2;
					b--;
				}
			}
		}
		else if(ptr[x][b] == 1){
			for(int i = 1; i <= n; i++){
				if(comp[i] == x and clr[i] == 1){
					ans[i] = 2;
					b--;
				}
			}
		}

		x--;
	}

    assert(b == 0);


    for(int i = 1; i <= n; i++){
    	if(ans[i] == 2) continue;
    	if(a > 0) ans[i] = 1, a--;
    	else ans[i] = 3;
    }

    for(int i = 1; i <= n; i++) cout<<ans[i];
}