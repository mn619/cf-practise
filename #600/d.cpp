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

int n, m, mx;
vector <int> v[maxn + 1];
bool vis[maxn + 1];

void dfs(int node){
	vis[node] = 1;
	mx = max(mx, node);
	for(auto x: v[node]){
		if(vis[x]) continue;
		dfs(x);
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
    	v[a].pb(b);
    	v[b].pb(a);
    }

    int ans = 0;
    fr(i, 1, n + 1){
    	int s = i;
    	if(!vis[i]) dfs(i);
    	while(i < mx){
    		if(!vis[i]) {dfs(i); ans++;}
    		i++;
    	}
    	mx = 0;
    }

    cout<<ans<<'\n';
}