#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

#define F first
#define S second
#define pb push_back
#define int long long
#define maxn 200000
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

int n, m;
set <int> v[maxn];
set <int> indSet;
vector <bool> vis(maxn, 0);
vector <int> t[maxn];
int level[maxn], dp[maxn][maxlg + 1], cnt[maxn];


void dfs(int node){
	for(auto x: v[node]){
		if(vis[x]) continue;

	}
}
void dfsTree(int node, int par, int d){
	level[node] = d;
	dp[node][0] = par;
	for(int i = 1; i <= maxlg; i++){
		dp[node][i] = dp[dp[node][i - 1]][i - 1];
	}

	for(auto x: t[node]){
		dfsTree(x, node, d + 1);
	}
}

int lca(int a, int b){
	if(level[a] < level[b]) swap(a, b);
	int d = level[b] - level[a];

	for(int i = 0; i < maxlg; i++){
		if(d>>i&1)
			a = dp[a][i];
	}

	if(a == b) return a;

	for(int i = 0; i < maxlg; i++){
		if(dp[a][i] != dp[b][i]) a = dp[a][i], b = dp[b][i];
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

    for(int i = 1; i <= m; i++){
    	int a, b;
    	cin>>a>>b;
    	v[a].insert(b);
    	v[b].insert(a);
    }

    int k = 1;
    while(k*k < n){
    	k++;
    }

    // for(auto x: indSet) cout<<x<<" ";
    // return 0;

    dfsTree(1, 1, 1);
	// for(int i = 1; i <= n; i++){
	// 	cout<<i<<" "<<level[i]<<'\n';
	// }

    vector <int> ans;
	for(int i = 1; i <= n; i++){
		for(auto x: v[i]){
			if(level[i] != level[x] - 1 and (level[i] - level[x]) >= k){
				int node = i;
				while(true){
					ans.pb(node);
					if(node == x) break;
					node = dp[node][0];
				}
				cout<<ans.size()<<'\n';
				for(auto y: ans){
					cout<<y<<' ';
				}
				return 0;
			}
		}
	}

	

	vector <int> leaf;

	for(int i = 1; i <= n; i++){
		for(auto x: v[i]){
			if(level[x] == level[i] + 1) cnt[i]++;
		}
		if(cnt[i] == 0){
			leaf.push_back(i);
		}
	}


	for(auto x: leaf){
		int temp = k;
		int node = x;
		cout<<x<<'\n';
		for(int i = 0; i < maxlg; i++){
			if(temp>>i&1) node = dp[node][i];
		}

		if(!indSet.count(temp)){
			indSet.insert(x);
		}
	}

	cout<<1<<'\n';
	for(auto x: indSet){
		cout<<x<<" ";
		k--;
		if(k == 0) return 0;
	}


		
}