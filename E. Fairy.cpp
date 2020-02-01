#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

#define F first
#define S second
#define pb push_back
#define int long long
#define maxn 200000
#define maxlg 14
#define mod 1000000007
#define inf 1000000000000000000

#define fr(i,a,b) for(int i=a;i<b;i++)
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); //freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
#define all(x) begin(x), end(x)
#define PII pair<int, int>
#define VI vector<int>
#define VII vector<PII>

using namespace std;

int n, m, dp[maxn][maxlg + 1];
VI t[maxn], level(maxn);
vector <bool> in(maxn);
map <PII, int> e;

void spanning_tree(){
	VI parent(n + 1);
	auto find_set = [&](int node) {
		while(parent[node] != node){
			node = parent[node] = parent[parent[node]];
		}
		return node;
	};

	auto union_sets = [&](int a, int b) {
	    a = find_set(a);
	    b = find_set(b);
	    if (a != b)
	        parent[b] = a;
	};

	for(int i = 1; i <= n; i++)
		parent[i] = i;
	
	for(auto x: e){
		if(find_set(x.F.F) == find_set(x.F.S)) continue;

		in[x.S] = 1;
		t[x.F.F].pb(x.F.S);
		t[x.F.S].pb(x.F.F);
		union_sets(x.F.F, x.F.S);
	}
}

void dfs(int node, int par, int d){
	level[node] = d;
	dp[node][0] = par;

	for(int i = 1; i <= maxlg; i++)
		dp[node][i] = dp[dp[node][i - 1]][i - 1];
	
	for(auto x: t[node]){
		if(x == par) continue;
		dfs(x, node, d + 1);
	}
}

int lca(int a, int b){
	if(level[a] < level[b]) swap(a, b);
	int d = level[a] - level[b];

	for(int i = maxlg; i >= 0; i--)
		if(d&(1<<i)) b = dp[b][i];

	if(a == b) return a;
	
	for(int i = maxlg; i >= 0; i--){
		if(dp[a][i] != dp[b][i])
			a = dp[a][i], b = dp[b][i];
	}

	return dp[a][0];
}

signed main()
{
    #ifndef ONLINE_JUDGE
    FILEIO
    #endif
    FLASH

    cin>>n>>m;

    fr(i, 1, m + 1){
    	int a, b;
    	cin>>a>>b;
    	e[{a, b}] = i;
    	e[{b, a}] = i;
    }

    spanning_tree();

    dfs(1, 1, 1);
    auto dist = [&](int a, int b){
    	return level[a] + level[b] - 2*level[lca(a, b)];
    };

    for(int i = 1; i <= m; i++) cout<<in[i]<<'\n';
    	
    vector <int> ans;	
    bool found = 0;
    for(auto x: e){
    	if(in[x.S]) continue;
    	int a = x.F.F, b = x.F.S;

    	int len = dist(a, b) + 1;

    	if(found and (len&1))
    		return cout<<"0\n", 0;
    	
    	if(len&1) found = 1;

    	int l = lca(a, b);
    	ans.pb(e[{a, b}]);
    	while(a != l)
    		ans.pb(e[{a, dp[a][0]}]), a = dp[a][0];
    	while(b != l)
    		ans.pb(e[{b, dp[b][0]}]), b = dp[b][0];
    }

    if(!found){
    	cout<<m<<'\n';
    	fr(i, 1, m + 1) 
    		cout<<i<<" ";
    	return 0;
    }

    cout<<ans.size()<<'\n';
    for(auto x: ans) cout<<x<<" ";
}