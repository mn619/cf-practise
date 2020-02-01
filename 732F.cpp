#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

#define F first
#define S second
#define pb push_back
#define int long long
#define maxn 400000
#define mod 1000000007
#define inf 1000000000000000000

#define fr(i,a,b) for(int i=a;i<b;i++)
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); //freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
#define all(x) begin(x), end(x)
#define PII pair<int, int>
#define VI vector<int>
#define VII vector<PII>

using namespace std;

vector <PII> v[maxn + 1];
PII e[maxn + 1]; 
int low[maxn + 1], tin[maxn + 1], comp[maxn + 1], sz[maxn + 1];
int tim = 0;
vector <bool> is_bridge(maxn + 1, 0), vis(maxn + 1, 0), rev(maxn + 1, 0), vis_e(maxn + 1);
int n, m;

void dfs(int node, int par = -1){
	tin[node] = ++tim;
	low[node] = tim;
	vis[node] = 1;

	for(auto x: v[node]){
		if(x.F == par) continue;
		if(vis[x.F]){
			low[node] = min(tin[x.F], low[node]);
		}
		else{
			dfs(x.F, node);
			low[node] = min(low[node], low[x.F]);
			if(low[x.F] > tin[node]) is_bridge[x.S] = 1;
		}
	}
}

void dfs2(int node, int c){
	comp[node] = c;
	vis[node] = 1;
	sz[c]++;	
	for(auto x: v[node]){
		if(vis[x.F] or is_bridge[x.S]) continue;
		dfs2(x.F, c);
	}
}

void dfs3(int node, int par = -1){
	vis[node] = 1;
	for(auto x: v[node]){
		if(x.F == par or vis_e[x.S]) continue;
		if(is_bridge[x.S]){
			if(e[x.S].F == node){
				rev[x.S] = 1;
			}
		}
		else{
			if(e[x.S].F != node){
				rev[x.S] = 1;
			}
		}
		vis_e[x.S] = 1;
		if(vis[x.F]) continue;
		dfs3(x.F, node);
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
    	e[i] = {a, b};
    	v[a].pb({b, i});
    	v[b].pb({a, i});
    }

    dfs(1);

    tim = 0;
    int ans = 0;
    fr(i, 1, n + 1) vis[i] = 0;

    fr(i, 1, n + 1){
    	if(vis[i]) continue;
    	dfs2(i, ++tim);
    	if(sz[tim] > sz[comp[ans]])
    		ans = i;
    }
    
    fr(i, 1, n + 1) vis[i] = 0;
    dfs3(ans);

    cout<<sz[comp[ans]]<<'\n';
    fr(i, 1, m + 1){
    	if(rev[i]){
    		cout<<e[i].S<<" "<<e[i].F<<'\n';
    	}
    	else cout<<e[i].F<<" "<<e[i].S<<'\n';
    }
}	
