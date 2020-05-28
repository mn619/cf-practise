#include<bits/stdc++.h>
#define int long long
#define inf 1000000000000000001
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); //freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
using namespace std;

int n, m, a[101][101], dp[101][101], mn;
bool b[101][101];

int dfs(int x, int y){
	if(dp[x][y] != -1) return dp[x][y];
	if(x == n and y == m){
		return a[n][m];
	}
	int ans1 = inf;
	if(x == n){
		ans1 = dfs(x, y + 1);
		b[x][y] = 0;
	}
	else if(y == m){
		ans1 = dfs(x + 1, y);
		b[x][y] = 1;
	}
	else{
		int temp1 = dfs(x + 1, y), temp2 = dfs(x, y + 1);
		ans1 = max(temp1, temp2);
		if(temp1 > temp2){
			b[x][y] = 1;
		}
		else b[x][y] = 0;
	}

	return dp[x][y] = min(a[x][y], ans1);
}

void solv(){
	cin>>n>>m;

	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			{cin>>a[i][j]; a[i][j] -= (j + i); dp[i][j] = -1;}

	int t = dfs(1, 1);

	for(int i = 1; i <= n; i++){
		for(int j = 1; j <=m; j++)
			cout<<b[i][j]<<" ";
		cout<<'\n';
	}
	cout<<t<<'\n';
	int ans = 0, x = 1, y = 1;
	while(x != n or y != m){
		ans += a[x][y] - t;
		if(b[x][y]) x = x + 1;
		else y = y + 1;
	}
	ans += a[n][m] - t;
	cout<<ans<<'\n';
}

signed main()
{
    #ifndef ONLINE_JUDGE
    FILEIO
    #endif
    FLASH

    int t;
    cin>>t;

    while(t--) solv();
}