#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("C:/Users/Aman/Desktop/kachda/input.txt", "r", stdin); freopen("C:/Users/Aman/Desktop/kachda/output.txt", "w", stdout);

using namespace std;
int n, m, p, s[10];
int a[1001][1001] = {{0}};
queue <pair <pair <int, int>, pair<int, int>> > q, q1;
vector <pair<int, int> > v[10];

signed main()
{
	FILEIO
 	FLASH
	
	cin>>n>>m>>p;
	fr(i,1,p + 1) cin>>s[i];

	fr(i,1,n + 1)
	{
		fr(j,1,m + 1)
		{
			char c;
			cin>>c;
			if(c == '.') continue;
			a[i][j] = c - '0';
			if(a[i][j] == -13) a[i][j] = -1;
			if(a[i][j] > 0) v[a[i][j]].pb({i,j});
		}
	}


	fr(i,1,p + 1)
	{
		fr(j,0,v[i].size())q.push({{i,0},{v[i][j].first, v[i][j].second}});
	}


	while(!q.empty())
	{
		int player = q.front().first.first;
		while(q.front().first.first == player && !q.empty())
		{
			q1.push(q.front());
			q.pop();
		}
		while(!q1.empty())
		{
			int d = q1.front().first.second, speed = s[player], x = q1.front().second.first, y = q1.front().second.second;
			q1.pop();
			
			if(d == speed) continue;
			if(a[x + 1][y] == 0 && x + 1 <= n) {q1.push({{player, d + 1},  {x + 1, y}}); q.push({{player, 0},  {x + 1, y}});a[x + 1][y] = player;}
			if(a[x - 1][y] == 0 && x - 1 >= 1) {q1.push({{player, d + 1}, {x - 1, y}});  q.push({{player, 0}, {x - 1, y}}); a[x - 1][y] = player;}
			if(a[x][y + 1] == 0 && y + 1 <= m) {q1.push({{player, d + 1}, {x, y + 1}});  q.push({{player, 0}, {x, y + 1}}); a[x][y + 1] = player;}
			if(a[x][y - 1] == 0 && y - 1 >= 1) {q1.push({{player, d + 1}, {x, y - 1}});  q.push({{player, 0}, {x, y - 1}}); a[x][y - 1] = player;}
		}
	}

	int ans[10] = {0};

	fr(i,1,n+1)
	{
		fr(j,1,m + 1)
		{
			if(a[i][j] != -1)
			{
				ans[a[i][j]]++;
			}
		}
	}

	fr(i,1,p + 1) cout<<ans[i]<<" "; 



}