#include<bits/stdc++.h>
#define int long long
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); //freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
#define inf 1000000000000000001
using namespace std;

int dist[1010][1010];
int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};
int n, m, t;
char c[1010][1010];
queue <pair<int, int>> q;

signed main()
{
    #ifndef ONLINE_JUDGE
    FILEIO
    #endif
    FLASH

    cin>>n>>m>>t;
    for(int i = 1; i <= n; i++){
    	for(int j = 1; j <= m; j++) {cin>>c[i][j]; dist[i][j] = inf;}
    }

	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			bool ok = 0;
			for(int k = 0; k < 4; k++) ok |= c[i + dx[k]][j + dy[k]] == c[i][j];
			if(ok){
				q.push({i, j});
				dist[i][j] = 1;
			}
		}
	}

	while(!q.empty()){
		int x = q.front().first, y = q.front().second;
		q.pop();
		for(int k = 0; k < 4; k++){
			if(c[x + dx[k]][y + dy[k]] != c[x][y] and dist[x + dx[k]][y + dy[k]] > dist[x][y] + 1){
				q.push({x + dx[k], y +  dy[k]});
				dist[x + dx[k]][y + dy[k]] = dist[x][y] + 1;
			}
		}
	}

	// for(int i = 1; i <= n; i++){
	// 	for(int j = 1; j <= m; j++) cout<<dist[i][j]<<" ";
	// 		cout<<'\n';
	// }

	for(int i = 1; i <= t; i++){
		int x, y, p;
		cin>>x>>y>>p;
		if(p < dist[x][y] or ((p - dist[x][y])&1)){
			cout<<c[x][y]<<'\n';
		}
		else{
			if(c[x][y] == '0') cout<<"1\n";
			else cout<<"0\n";
		}
	}
}