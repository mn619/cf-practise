#include<bits/stdc++.h>
#define int long long
#define maxn 200000
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); //freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
using namespace std;
int n, dp[maxn + 1][2], ecnt[maxn + 1], ocnt[maxn + 1], e, o, t;
vector <int> v[maxn + 1];

void dfs(int node, int par){
	int o1 = 0, e1 = 0;
	ecnt[node]++;

	for(auto x: v[node]){
		if(x == par) continue;
		dfs(x, node);

		o1 += dp[node][0]*ecnt[x] + dp[node][1]*ocnt[x] + (dp[x][0] + ecnt[x])*ecnt[node] + (dp[x][1] + ocnt[x])*ocnt[node];
		e1 += dp[node][0]*ocnt[x] + dp[node][1]*ecnt[x] + (dp[x][0] + ecnt[x])*ocnt[node] + (dp[x][1] + ocnt[x])*ecnt[node];
        t  += ocnt[node]*ocnt[x] + ecnt[node]*ecnt[x];

		dp[node][0] += dp[x][1] + ocnt[x];
		dp[node][1] += dp[x][0] + ecnt[x];

		ocnt[node] += ecnt[x];
		ecnt[node] += ocnt[x];
	}

	e += e1;
	o += o1;
}

signed main()
{
    FILEIO
	cin>>n;
	for(int i = 1; i < n; i++){
		int a, b;
		cin>>a>>b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	dfs(1, 1);

	cout<<e/2 + (o + t)/2;
}