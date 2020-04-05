#include<bits/stdc++.h>
#define int long long
#define maxn 200000
#define inf 10000000000
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); //freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
using namespace std;

vector <pair<int, int>> dp[maxn];
int n, m;

void update(int a, int b, int c){
	int l = 0, r = (int)dp[a].size() - 1, ind = -1;
	while(l <= r){
		int mid = (l + r)>>1;
		if(dp[a][mid].first < c){
			l = mid + 1;
			ind = mid;
		}
		else r = mid - 1;
	}

	int ans = 0;

	while(ind){
		ans = max(ans, dp[a][ind].second);
		ind -= ind&-ind;
	}
	l = 1, r = (int)dp[b].size() - 1, ind = -1;

	while(l <= r){
		int mid = (l + r)>>1;
		if(dp[b][mid].first <= c){
			l = mid + 1;
			ind = mid;
		}
		else r = mid - 1;
	}

	assert(ind != -1);

	while(ind <= (int)dp[b].size() - 1) {
		dp[b][ind].second = max(dp[b][ind].second, ans + 1);
		ind += ind&-ind;
	}

}
signed main()
{
    #ifndef ONLINE_JUDGE
    FILEIO
    #endif
    FLASH

    cin>>n>>m;
    vector <pair<pair<int, int>, int>> e;
    for(int i = 1; i <= n; i++) dp[i].push_back({-inf, -inf});

    for(int i = 1; i <= m; i++){
    	int a, b, c;
    	cin>>a>>b>>c;
    	e.push_back({{a, b}, c});
    	dp[b].push_back({c, -inf});
    }

    for(int i = 1; i <= n; i++) sort(dp[i].begin(), dp[i].end());

    for(int i = 0; i < m; i++){
    	int a = e[i].first.first, b = e[i].first.second, c = e[i].second;
    	update(a, b, c);
    }

    int ans = 0;
    for(int i = 1; i <= n; i++){
    	for(auto x : dp[i]) ans = max(ans, x.second);
    }

	cout<<ans<<'\n';
}