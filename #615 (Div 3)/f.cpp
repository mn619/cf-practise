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

vector <int> v[maxn + 1];
int dist[maxn + 1], parent[maxn + 1];
queue <pair<int, int>> q;
int n;

void dfs(int node, int par, int d){
	dist[node] = d;
	parent[node] = par;
	for(auto x: v[node]){
		if(x == par) continue;
		dfs(x, node, d + 1);
	}
}

signed main()
{
    #ifndef ONLINE_JUDGE
    FILEIO
    #endif
    FLASH

    cin>>n;

    fr(i, 1, n +1 ){
    	int a, b;
    	cin>>a>>b;
    	v[a].pb(b);
    	v[b].pb(a);
    }

    dfs(1, 1, 0);

    int new_root = 1;
    fr(i, 1, n + 1) if(dist[i] > dist[new_root]) new_root = i;

    dfs(new_root, 0, 0);

    int a = new_root;
    
    fr(i, 1, n + 1){
    	if(dist[i] > dist[new_root]) new_root = i;
    }
    int b = new_root;

    int ans = dist[b];

    int cur = b;
    fr(i, 1, n + 1) dist[i] = inf;
    while(cur != a){
    	dist[cur] = 0;
    	q.push({cur, 0});
    	cur = parent[cur];
    }
    q.push({a, 0});

    dist[a] = 0;

    while(!q.empty()){
    	int node = q.front().F, d = q.front().S;
    	q.pop();
    	for(auto x: v[node]){
    		if(dist[x] > d + 1){
    			q.push({x, d + 1});
    			dist[x] = d + 1;
    		}
    	}
    }	

    int c = 1;
    fr(i, 1, n + 1){
    	if(dist[c] < dist[i]){
    		c = i;
    	}
    }

    if(ans == n - 1){
    	fr(i, 1, n + 1) if(i != a and i != b) c = i;
    }
    ans += dist[c];
    cout<<ans<<'\n';
    cout<<a<<" "<<b<<" "<<c<<'\n';
}