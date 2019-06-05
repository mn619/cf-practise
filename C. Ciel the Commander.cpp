#include<bits/stdc++.h>
#define start_routine cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false); int begtime = clock();
#define end_routine int endtime = clock(); cerr << endl << "Time elapsed: " << (endtime - begtime)*1000/CLOCKS_PER_SEC << " ms"; return 0;
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define int long long
#define mp make_pair
#define fr(i,a,b) for(i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
using namespace std;

vector <int> v[100001];
int ans[100001], siz[100001],n;
bool vis[100001] = {0};

int dfs1(int node, int par)
{
	siz[node] = 1;
	int i;
	fr(i,0,v[node].size())
	{
		if(v[node][i] != par && vis[v[node][i]] == 0) siz[node] += dfs1(v[node][i], node);
	}
	return siz[node];
}

void dfs2(int node, int par, int las )
{
	int i;
	fr(i,0,v[node].size())
	{
		if(v[node][i] != par && vis[v[node][i]] == 0 && siz[v[node][i]]*2 > siz[las])
		{
			return dfs2(v[node][i], node, las);
		}
	}

	ans[node] = (vis[las] == 0)? 1 : ans[las]  + 1;
	vis[node] = 1;

	fr(i,0,v[node].size())
	{
		if(vis[v[node][i]] == 0 )
		{
			dfs1(v[node][i],node);
			dfs2(v[node][i], node, node);
		}
	}
}
void solve()
{
	dfs1(1,0);
	dfs2(1,0,1);	
	int i;

	fr(i,1,n+1)
	{
		cout<<char(ans[i]-1+'A')<<" ";
	}
}
signed main()
{
	//FILEIO
 	//start_routine

	int tests = 1;
	//cin>>tests;

	while(tests--)
	{
		cin>>n;
		int i;
		fr(i,1,n)
		{
			int x,y;
			cin>>x>>y;
			
			v[x].pb(y);
			v[y].pb(x);
		}

		solve();
	}

 	//end_routine
}
