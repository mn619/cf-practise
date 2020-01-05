#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define ll long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
#define maxn 200000

using namespace std;

typedef long long LL;
 
struct Edge {
  ll from, to, cap, flow, index;
  Edge(ll from, ll to, ll cap, ll flow, ll index) :
    from(from), to(to), cap(cap), flow(flow), index(index) {}
};
 
struct PushRelabel {
  ll N;
  vector<vector<Edge> > G;
  vector<LL> excess;
  vector<ll> dist, active, count;
  queue<ll> Q;
 
  PushRelabel(ll N) : N(N), G(N), excess(N), dist(N), active(N), count(2*N) {}
 
  void AddEdge(ll from, ll to, ll cap) {
    G[from].push_back(Edge(from, to, cap, 0, G[to].size()));
    if (from == to) G[from].back().index++;
    G[to].push_back(Edge(to, from, 0, 0, G[from].size() - 1));
  }
 
  void Enqueue(ll v) { 
    if (!active[v] && excess[v] > 0) { active[v] = true; Q.push(v); } 
  }
 
  void Push(Edge &e) {
    ll amt = (ll)(min(excess[e.from], LL(e.cap - e.flow)));
    if (dist[e.from] <= dist[e.to] || amt == 0) return;
    e.flow += amt;
    G[e.to][e.index].flow -= amt;
    excess[e.to] += amt;    
    excess[e.from] -= amt;
    Enqueue(e.to);
  }
  
  void Gap(ll k) {
    for (ll v = 0; v < N; v++) {
      if (dist[v] < k) continue;
      count[dist[v]]--;
      dist[v] = max(dist[v], N+1);
      count[dist[v]]++;
      Enqueue(v);
    }
  }
 
  void Relabel(ll v) {
    count[dist[v]]--;
    dist[v] = 2*N;
    for (ll i = 0; i < G[v].size(); i++) 
      if (G[v][i].cap - G[v][i].flow > 0)
  dist[v] = min(dist[v], dist[G[v][i].to] + 1);
    count[dist[v]]++;
    Enqueue(v);
  }
 
  void Discharge(ll v) {
    for (ll i = 0; excess[v] > 0 && i < G[v].size(); i++) Push(G[v][i]);
    if (excess[v] > 0) {
      if (count[dist[v]] == 1) 
  Gap(dist[v]); 
      else
  Relabel(v);
    }
  }
 
  LL GetMaxFlow(ll s, ll t) {
    count[0] = N-1;
    count[N] = 1;
    dist[s] = N;
    active[s] = active[t] = true;
    for (ll i = 0; i < G[s].size(); i++) {
      excess[s] += G[s][i].cap;
      Push(G[s][i]);
    }
    
    while (!Q.empty()) {
      ll v = Q.front();
      Q.pop();
      active[v] = false;
      Discharge(v);
    }
    
    LL totflow = 0;
    for (ll i = 0; i < G[s].size(); i++) totflow += G[s][i].flow;
    return totflow;
  }
};
 
int n, t, d[11][11], sx, sy;
char a[11][11], b[11][11];
vector <pair<int, int>> v[11][11];

void bfs(){
	fr(i, 1, n + 1) fr(j, 1, n + 1)  d[i][j] = (a[i][j] != 'Y')*100;

	queue <pair<int, int>> q;
	d[sx][sy] = 0;
	q.push({sx, sy});
	while(!q.empty()){
		int x = q.front().first, y = q.front().second;
		q.pop();
		if(x < n and d[x + 1][y] > d[x][y] + 1 and a[x + 1][y] != 'Y'){
			d[x + 1][y] = d[x][y] + 1;
			q.push({x + 1, y});
		}
		if(y < n and d[x][y + 1] > d[x][y] + 1 and a[x][y + 1] != 'Y'){
			d[x][y + 1] = d[x][y] + 1;
			q.push({x, y + 1});
		}
		if(x > 1 and d[x - 1][y] > d[x][y] + 1 and a[x - 1][y] != 'Y'){
			d[x - 1][y] = d[x][y] + 1;
			q.push({x - 1, y});
		}
		if(y > 1 and d[x][y - 1] > d[x][y] + 1 and a[x][y - 1] != 'Y'){
			d[x][y - 1] = d[x][y] + 1;
			q.push({x, y - 1});
		}				
	}
}

void bfs2(int nx, int ny){
	int d1[n + 1][n + 1];
	bool vis[n + 1][n + 1];

	fr(i, 1, n + 1){
		fr(j, 1, n + 1) d1[i][j] = vis[i][j] = 0;

	}

	d1[nx][ny] = 0;
	queue<pair<int, int>> q;
	q.push({nx, ny});
	
	while(!q.empty()){
		int x = q.front().first, y = q.front().second;
		q.pop();
		vis[x][y] = 1;
		if(b[x][y] != 'Y' and b[x][y] != 'Z' and b[x][y] != '0' and d[x][y] >= d1[x][y]){
			v[x][y].pb({nx, ny});
		}
		if(d[x][y] == d1[x][y] or b[x][y] == 'Z' or b[x][y] == 'Y' or d1[x][y] == t) continue;
		if(x < n and d[x + 1][y] >= d1[x][y] + 1 and !vis[x + 1][y]){
			d1[x + 1][y] = d1[x][y] + 1;
			q.push({x + 1, y});
		}
		if(y < n and d[x][y + 1] >= d1[x][y] + 1 and !vis[x][y + 1]){
			d1[x][y + 1] = d1[x][y] + 1;
			q.push({x, y + 1});
		}
		if(x > 1 and d[x - 1][y] >= d1[x][y] + 1 and !vis[x - 1][y]){
			d1[x - 1][y] = d1[x][y] + 1;
			q.push({x - 1, y});
		}
		if(y > 1 and d[x][y - 1] >= d1[x][y] + 1 and !vis[x][y - 1]){
			d1[x][y - 1] = d1[x][y] + 1;
			q.push({x, y - 1});
		}
	}
}

signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

 	cin>>n>>t;
 	fr(i, 1, n + 1){
 		fr(j, 1, n + 1){
 			cin>>a[i][j];
 		}
 	}

 	fr(i, 1, n + 1){
 		fr(j, 1, n + 1){
 			cin>>b[i][j];
 			if(b[i][j] == 'Z') sx = i, sy =j;
 		}
 	} 	

 	bfs();

 	fr(i, 1, n + 1){
 		fr(j, 1, n + 1){
 			if(a[i][j] == 'Y' or a[i][j] == 'Z' or a[i][j] == '0') continue;
 			bfs2(i, j);
 		}
 	}

 	PushRelabel pr(n*n + n*n + 2);

 	fr(i, 1, n + 1){
 		fr(j, 1, n + 1){
 			for(auto x: v[i][j]){
 				pr.AddEdge(n*(x.first - 1) + x.second, n*n + n*(i - 1) + j, mod);
 			}
 		}
 	}

 	fr(i, 1, n + 1){
 		fr(j, 1, n + 1){
 			if(a[i][j] != 'Y' and a[i][j] != 'Z' and a[i][j] != '0' ){
 				pr.AddEdge(0, n*(i - 1) + j, a[i][j] - '0');
 			}
 			if(a[i][j] != 'Y' and a[i][j] != 'Z' and b[i][j] != '0'){
 				pr.AddEdge(n*n + n*(i - 1) + j, n*n + n*n + 1,b[i][j] - '0');
 			}
 		}
 	}

 	// fr(i, 1, n + 1){
 	// 	fr(j, 1, n + 1){
 	// 		// if(b[i][j] == 'Y' or b[i][j] == 'Z' or b[i][j] == '0') continue; 
 	// 		if(v[i][j].empty()) continue;
 	// 		cout<<i<<" "<<j<<'\n';
 	// 		for(auto x: v[i][j]) cout<<x.first<<" "<<x.second<<'\n';
		// 	cout<<'\n';	
 	// 	}
 	// }

 	cout<<pr.GetMaxFlow(0, n*n + n*n + 1);
}