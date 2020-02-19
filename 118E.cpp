#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

#define F first
#define S second
#define pb push_back
#define int long long
#define maxn 200000
#define mod 1000000007
#define inf 1000000000000000000

#define fr(i,a,b) for(int i=a;i<b;i++)
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); //freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
#define all(x) begin(x), end(x)
#define PII pair<int, int>
#define VI vector<int>
#define VII vector<PII>

using namespace std;

int n, m, tin[maxn], low[maxn];

vector <PII> v[maxn];

vector <pair<int, int>> ans;
vector <bool> vis(maxn, 0), used(2*maxn);
int tim;

void dfs(int node, int par = 0){
	vis[node] = 1;
	tin[node] = low[node] = ++tim;

	for(auto x: v[node]){
		if(x.F == par) continue;

		if(vis[x.F]){
			low[node] = min(low[node], tin[x.F]);
		}
		else{
			dfs(x.F, node);
			low[node] = min(low[x.F], low[node]);
		}	
		if(low[x.F] > tin[node]){
				cout<<"0\n";
				exit(0);
		}
		if(!used[x.S])
			ans.pb({node, x.F}), used[x.S] = 1;;
	}
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

    	v[a].pb({b, i});
    	v[b].pb({a, i});
    }
    
    dfs(1);
    for(auto x: ans) cout<<x.F<<" "<<x.S<<'\n';
}