#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("C:/Users/Aman/Desktop/kachda/input.txt", "r", stdin); freopen("C:/Users/Aman/Desktop/kachda/output.txt", "w", stdout);

using namespace std;
int k,n,m;
char c[1001][1001];
int vis[1001][1001] = {0}, t = 1, ans[1000001] = {0}, vis2[1001][1001] = {0};
void read()
{
	cin>>n>>m>>k;

	fr(i,1,n + 1)
	{
		fr(j,1,m + 1)
		{
			cin>>c[i][j];
		}
	}
}


void dfs(int i, int j)
{
	if(vis[i][j] > 0) return;
	vis[i][j] = t;
	if(c[i + 1][j] != '*') dfs(i + 1, j);
	if(c[i - 1][j] != '*') dfs(i - 1, j);
	if(c[i][j + 1] != '*') dfs(i, j + 1);
	if(c[i][j - 1] != '*') dfs(i,j - 1);
}

int dfs2(int i, int j)
{
	vis2[i][j] = t;
	if(c[i][j] == '*') {vis2[i][j] = 0; return 1;}
	int temp = 0;
	if(vis2[i - 1][j] != t) temp += dfs2(i - 1, j);
	if(vis2[i + 1][j] != t) temp += dfs2(i + 1, j);
	if(vis2[i][j - 1] != t) temp += dfs2(i, j - 1);
	if(vis2[i][j + 1] != t) temp += dfs2(i, j + 1);

	return temp;
}
signed main()
{
	FILEIO
 	FLASH
	read();
	fr(i,1,n + 1)
	{
		fr(j,1,m + 1)
		{
			if(vis[i][j] == 0 && c[i][j] == '.')
			{
				dfs(i,j);
				t++;
			}

		}
	}

	t = 1;
	fr(i,1,n + 1)
	{
		fr(j,1,m + 1)
		{
			if(vis[i][j] == t) {ans[t] = dfs2(i,j); t++;}
		}
	}

	while(k--)
	{
		int x,y;
		cin>>x>>y;
		cout<<ans[vis[x][y]]<<'\n';
	}
}	