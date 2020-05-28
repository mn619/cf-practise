#include<bits/stdc++.h>
#define int long long
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); //freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
using namespace std;

int n, m;
vector <int> v[200001];
vector <pair<int, bool>> comp;
vector <int> clr(200001, -1);
bool vis[200001], ans[200001];

void dfs(int node, bool b = 0){
	comp.push_back({node, b});
	vis[node] = 1;
	for(auto x: v[node]){
		if(vis[x] and clr[x] == b) {
			cout<<"-1\n";
			exit(0);
		}
		if(vis[x]) continue;
		dfs(x, !b);
	}
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
    	v[a].push_back(b);
    	v[b].push_back(a);
    }

    for(int i = 1; i <= n; i++){
    	if(vis[i]) continue;
    	dfs(i);
    	int a = 0, b = 0;
    	for(auto x: comp){
    		if(x.second) a++;
    		else b++;
    	}

    	if(a > b){
    		for(auto x: comp){
    			if(x.second){
    				ans[x.first] = 1;
    			}
    			else ans[x.first] = 0;
    		}
    	}
    	else{
    		for(auto x: comp){
    			if(x.second){
    				ans[x.first] = 0;
    			}
    			else ans[x.first] = 1;
    		}
    	}

    	comp.clear();
    }

    int cnt = 0;
    for(int i = 1; i <= n; i++) cnt += ans[i];
    cout<<cnt<<'\n';
	for(int i = 1; i <= n; i++){
		if(ans[i]) cout<<'A';
		else cout<<'E';
	}
}