#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
#define maxn 200000
#define pii pair<int,int>

using namespace std;

struct BipartiteMatcher {
  vector<vector<int>> G;
  vector<int> L, R, Viz;
  
  BipartiteMatcher(int n, int m) :
  G(n + 1), L(n + 1, -1), R(m + 1, -1), Viz(n + 1) {}
  
  void AddEdge(int a, int b) {
    G[a].push_back(b);
  }
  
  bool Match(int node) {
    if (Viz[node])
      return false;
    Viz[node] = true;
    
    for (auto vec : G[node]) {
      if (R[vec] == -1) {
        L[node] = vec;
        R[vec] = node;
        return true;
      }
    }
    
    for (auto vec : G[node]) {
      if (Match(R[vec])) {
        L[node] = vec;
        R[vec] = node;
        return true;
      }
    }
    
    return false;
  }
  
  int Solve() {
    int ok = true;
    while (ok--) {
      fill(Viz.begin(), Viz.end(), 0);
      for (int i = 0; i < (int)L.size(); ++i)
        if (L[i] == -1)
          ok |= Match(i);
    }
    
    int ret = 0;
    for (int i = 0; i < L.size(); ++i)
      ret += (L[i] != -1);
    return ret;
  }
};
//https://github.com/bicsi/code_snippets/blob/master/bipartite_match.cpp

int n, m, w[101][101], s, b, k, h, ans;
vector<pair<int, pii>> S;

signed main()
{
	FILEIO
 	FLASH

 	cin>>n>>m;
    fr(i, 1, n + 1)fr(j, 1, n + 1)w[i][j] = mod;
    fr(i, 1, n + 1) w[i][i] = 0;

    fr(i, 1, m + 1){
        int a, b;
        cin>>a>>b;
        if(a == b) continue;
        w[a][b] = 1;
        w[b][a] = 1;
    }

    fr(k, 1, n + 1)
        fr(i, 1, n + 1)
            fr(j, 1, n + 1){
                w[i][j] = min(w[i][j], w[i][k] + w[k][j]);
            }

    cin>>s>>b>>k>>h;
    BipartiteMatcher bm(s, b);

    ans = s*h;

    fr(i, 1, s + 1){
        int x, a, f;
        cin>>x>>a>>f;
        S.pb({x, {a, f}});
    }

    fr(i, 1, b + 1){
        int x, d;
        cin>>x>>d;
        fr(j, 0, s){
            if(S[j].second.first >= d and S[j].second.second >= w[S[j].first][x]){
                bm.AddEdge(j + 1, i);
            }
        }
    }
    
    ans = min(ans, bm.Solve()*k);
    cout<<ans;
}