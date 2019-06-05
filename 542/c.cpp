#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);

using namespace std;

int n, m, r1, r2, c1, c2;
char c[51][51];
bool vis[51][51] = {{0}};
vector <pair<int, int> > v1, v2;

void dfs(int i, int j)
{
	if(vis[i][j] == 1) return;
	//cout<<"here "<<i<<" "<<j<<'\n';
	v1.pb({i,j});
	vis[i][j] = 1;
	if(c[i - 1][j] == '0' && i - 1 > 0) dfs(i - 1, j);
	if(c[i + 1][j] == '0' && i + 1 <= n) dfs(i + 1, j);
	if(c[i][j - 1] == '0' && j - 1 > 0) dfs(i, j - 1);
	if(c[i][j + 1] == '0' && j + 1 <= n) dfs(i, j + 1);
}


void dfs2(int i, int j)
{
	if(vis[i][j] == 1) return;
	//cout<<"int "<<i<<" "<<j<<'\n';
	v2.pb({i,j});
	vis[i][j] = 1;
	if(c[i - 1][j] == '0' && i - 1 > 0) dfs2(i - 1, j);
	if(c[i + 1][j] == '0' && i + 1 <= n) dfs2(i + 1, j);
	if(c[i][j - 1] == '0' && j - 1 > 0) dfs2(i, j - 1);
	if(c[i][j + 1] == '0' && j + 1 <= n) dfs2(i, j + 1);
}



int dist(pair< int, int> a, pair<int, int> b)
{
	return (a.first - b.first)*(a.first - b.first) + (a.second - b.second)*(a.second - b.second);
}
signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

 	cin>>n>>r1>>c1>>r2>>c2;

 	fr(i,1,n + 1)
 	{
 		fr(j,1,n + 1)
 		{
 			cin>>c[i][j];
 		}
 	}

 	dfs(r1, c1);
 	if(vis[r2][c2] == 1) return cout<<0, 0;
 	dfs2(r2, c2);

 	int ans = mod;

 	
 	
 	fr(i,0,v1.size())
 	{
 		fr(j,0,v2.size())
 		{ 
 			//if(ans > dist(v1[i], v2[j])) cout<<v1[i].first<<" "<<v1[i].second<<' '<< dist(v1[i], v2[j])<<'\n';
 			ans = min(ans, dist(v1[i], v2[j]));
 		}
 	}

 	cout<<ans<<'\n';
}