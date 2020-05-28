#include<bits/stdc++.h>
#define int long long
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); //freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
using namespace std;
int n, m;
char c[1010][1010];
bool l[1010][1010], r[1010][1010], u[1010][1010], d[1010][1010], vis[1010][1010];

void dfs(int x, int y){
	if(c[x][y] == '.') return;
	vis[x][y] = 1;
	if(!vis[x - 1][y] and x > 1)
		dfs(x - 1, y);
	if(!vis[x + 1][y] and x < n)
		dfs(x + 1, y);
	if(!vis[x][y - 1] and y > 1)
		dfs(x, y - 1);
	if(!vis[x][y + 1] and y < m)
		dfs(x, y + 1);
}
signed main()
{
    #ifndef ONLINE_JUDGE
    FILEIO
    #endif
    FLASH

    cin>>n>>m;

    bool in = 0;
    for(int i = 1; i <= n; i++){
    	for(int j = 1; j <= m; j++){ cin>>c[i][j]; in |= (c[i][j] == '#');}
    }
	if(!in) return cout<<"0\n", 0;

	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			l[i][j] = (c[i][j] == '#' or l[i][j - 1]);
		}
	}

	for(int i = 1; i <= n; i++){
		for(int j = m; j >= 1; j--){
			r[i][j] = (c[i][j] == '#' or r[i][j + 1]);
		}
	}

	for(int j = 1; j <= m; j++){
		for(int i = 1; i <= n; i++){
			u[i][j] = (c[i][j] == '#' or u[i - 1][j]);
		}
	}

	for(int j = 1; j <= m; j++){
		for(int i = n; i >= 1; i--){
			d[i][j] = (c[i][j] == '#' or d[i + 1][j]);
		}
	}

	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(c[i][j] == '#') continue;
			if((l[i][j] and r[i][j]) or (u[i][j] and d[i][j])) return cout<<"-1\n", 0;
			if((r[i][1] == 0) or (d[1][j] == 0)) return cout<<"-1\n", 0;
		}
	}

	int ans = 0;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(vis[i][j] or c[i][j] == '.') continue;
			dfs(i, j);
			ans++;
		}
	}

	cout<<ans<<'\n';
}