#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

#define F first
#define S second
#define pb push_back
#define int long long
#define maxn 200001
#define maxlg 20
#define mod 1000000007
#define inf 1000000000000000000

#define fr(i,a,b) for(int i=a;i<b;i++)
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); //freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
#define all(x) begin(x), end(x)
#define PII pair<int, int>
#define VI vector<int>
#define VII vector<PII>

using namespace std;

int n, a[maxn], ans[maxn], dp[maxn][maxlg + 1], level[maxn];
VII v[maxn];

void dfs(int node, int par, int l){
	level[node] = l;
	dp[node][0] = par;
	fr(i, 1, maxlg + 1){
		dp[node][i] = dp[dp[node][i - 1]][i - 1];
	}

	for(auto x: v[node]){
		if(x.F == par) continue;
		dfs(x.F, node, l + x.S);
	}
}

int kth_par(int node, int k){
	for(int i = maxlg; i >= 0; i--){
		if(k&(1<<i)) node = dp[node][i];
	}
	return node;
}

void dfs2(int node, int par){
	for(auto x: v[node]){
		if(x.F == par) continue;
		dfs2(x.F, node);
		ans[node] += ans[x.F];
	}
}

signed main()
{
    #ifndef ONLINE_JUDGE
    FILEIO
    #endif
    FLASH
	
	cin>>n;
	fr(i, 1, n + 1){
		cin>>a[i];
	}

	fr(i, 1, n){
		int p, w;
		cin>>p>>w;
		v[i + 1].pb({p, w});
		v[p].pb({i + 1, w});
	}

	dfs(1, 0, 0);

	fr(i, 1, n + 1){
		int l = 1, r = n;
		int ans1 = i;

		while(l <= r){
			int mid = (l + r)>>1;
			int anc = kth_par(i, mid);
			if(level[i] - level[anc] <= a[i]){
				ans1 = anc;
				l = mid + 1;
			}
			else r = mid - 1;
		}

		ans[dp[i][0]]++;
		ans[dp[ans1][0]]--;
	}

	dfs2(1, 0);

	fr(i, 1, n + 1) cout<<ans[i]<<' ';
}