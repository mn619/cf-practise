#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
#define logN 20

using namespace std;

int q, dp[200001][logN], las = 0, cur = 1, level[200001];


void update(int node, int par){
	dp[node][0] = par;
	level[node] = level[par] + 1;
	int x = par;
	fr(i, 1, 20){
		dp[node][i] = dp[x][i - 1];
		x = dp[x][i - 1];
	}
}


int lca(int node1, int node2)
{
	if(level[node1] < level[node2]) swap(node1, node2);

	int d = level[node1] - level[node2];

	fr(i,0,logN)
		if(d&(1<<i)) node1 = dp[node1][i];
		

	if(node1 == node2) return node1;

	for(int i = logN - 1; i>=0; i--)
	{
		if(dp[node1][i] != dp[node2][i])
		{
			node1 = dp[node1][i], node2 = dp[node2][i];
		}
	}
	return dp[node1][0];
}

int queri(int a, int b){

	return level[a] + level[b] - 2*level[lca(a, b)];
}
signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

 	cin>>q;

 	level[1] = 1;
 	fr(i, 0, 20) dp[1][i] = 1;

 	while(q--){
 		int t;
 		cin>>t;
 		if(t == 1){
 			int p;
 			cin>>p;
 			p = (p + las)%cur + 1;
 			cur++;
 			update(cur, p);
 			las = level[cur];
 		}
 		else{
 			int u, v;
 			cin>>u>>v;

 			u = (u + las)%cur + 1;
 			v = (v + las)%cur + 1;

 			las = queri(u, v) + 1;
 		}
 		cout<<las<<'\n';
 	}
}