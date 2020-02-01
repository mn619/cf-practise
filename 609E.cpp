#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

#define F first
#define S second
#define pb push_back
#define int long long
#define maxn 200000
#define maxlg 18
#define mod 1000000007
#define inf 1000000000000000000

#define fr(i,a,b) for(int i=a;i<b;i++)
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); //freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
#define all(x) begin(x), end(x)
#define PII pair<int, int>
#define VI vector<int>
#define VII vector<PII>

using namespace std;

int n, m, mst_wt;
map <pair<int, int>, bool> in;

pair<int, PII> e[maxn + 1];
int dp[maxn + 1][maxlg + 1], p[maxn + 1][maxlg + 1], level[maxn + 1];

priority_queue <pair<int, pair<int, int>>> q;
VII v[maxn + 1];

void mst(){
	vector <int> parent(n + 1);
	fr(i, 1, n + 1) parent[i] = i;

	auto find_set = [&](int node){
		while(parent[node] != node){
			node = parent[node] = parent[parent[node]];
		}
		return node;
	};

	auto union_set = [&](int a, int b){
		a = find_set(a), b = find_set(b);
		parent[a] = b;
	};

	while(!q.empty()){
		int a = q.top().S.F, b = q.top().S.S, c = -q.top().F;
		q.pop();
		if(find_set(a) == find_set(b)) continue;
		mst_wt += c;
		in[{a, b}] = in[{b, a}] = 1;
		v[a].pb({b, c});
		v[b].pb({a, c});
		union_set(a, b);
	}
}

void dfs(int node, int par, int l){
	level[node] = l;
	for(int i = 1; i <= maxlg; i++){
		p[node][i] = p[p[node][i - 1]][i - 1];
		dp[node][i] = dp[node][i - 1];
		if(dp[p[node][i - 1]][i - 1] > dp[node][i]){
			dp[node][i] = dp[p[node][i - 1]][i - 1];
		}
	}

	for(auto x: v[node]){
		if(x.F == par) continue;
		dp[x.F][0] = x.S;
		p[x.F][0] = node;
		dfs(x.F, node, l + 1);
	}
}

int lca(int a, int b){
	if(level[a] < level[b]) swap(a, b);
	int d = level[a] - level[b];

	for(int i = maxlg; i >= 0; i--){
		if(d&(1<<i)) a = p[a][i];
	}

	if(a == b) return a;

	for(int i = maxlg; i >= 0; i--){
		if(p[a][i] != p[b][i]){
			a = p[a][i];
			b = p[b][i];
		}
	}

	assert(p[a][0] == p[b][0]);
	return p[a][0];
}

int max_wt(int a, int b){
	int l = lca(a, b);

	int d1 = level[a] - level[l], d2 = level[b] - level[l];
	int ans = 0;

	for(int i = maxlg; i >= 0; i--){
		if(d1&(1<<i)){
			ans = max(ans, dp[a][i]);
			a = p[a][i];
		}
		if(d2&(1<<i)){
			ans = max(ans, dp[b][i]);
			b = p[b][i];
		}
	}

	assert(a == b);
	return ans;
}

signed main()
{
    #ifndef ONLINE_JUDGE
    FILEIO
    #endif
    FLASH

    cin>>n>>m;

    fr(i, 1, m + 1){
    	int a, b, c;
    	cin>>a>>b>>c;
    	e[i] = {c, {a, b}};
    	q.push({-c, {a, b}});
    }

    mst();
    dfs(1, 1, 0);

    // cout<<lca(2, 4)<<' '<<dp[2][0]<<" "<<dp[2][1]<<" ";
    // return 0;

    fr(i, 1, m + 1){
    	int a = e[i].S.F, b = e[i].S.S, c = e[i].F;

    	if(in[{a, b}]) {
    		cout<<mst_wt<<'\n';
    	}
    	else {
	    	int ans = mst_wt + c - max_wt(a, b);
	    	cout<<ans<<'\n';
    	}
    }

}