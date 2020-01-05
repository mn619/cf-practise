#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); //freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
#define maxn 200000

using namespace std;

int n, m, k, cnt = 0;

bool ans = 1;

inline pair<int, int>  nex(int x, int y, int dir){
	if(dir == 1){
		y++; 
	}
	else if(dir == 2){
		x++;
	}
	else if(dir == 3){
		y--;
	}
	else x--;

	return {x, y};
}

void dfs(vector <vector<int>> & a,int x, int y, int dir){
	cnt++;
	a[x][y] = 1;
	auto p = nex(x, y, dir);
	if(p.first > n or p.second > m or p.first < 1 or p.second < 1) {
		dir++;
		if(dir == 5) dir = 1;
		p = nex(x, y, dir);
	}
	else if(a[p.first][p.second] == -1){
		dir++;
		if(dir == 5) dir = 1;
		p = nex(x, y, dir);
	}
	if(a[p.first][p.second] == -1 or a[p.first][p.second] == 1) return;
	dfs(a, p.first, p.second, dir);
}

signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

 	cin>>n>>m>>k;
	vector <vector<bool>> a(n + 1);
	fr(i, 1, n + 1){
		a[i].resize(m + 1, 0);
	}
	fr(i, 1, k + 1){
		int x, y;
		cin>>x>>y;
		a[x][y] = -1;
	}

	dfs(a, 1, 1, 1);
	if(cnt == n*m - k) cout<<"Yes\n";
	else cout<<"No\n";
}