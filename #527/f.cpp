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

int n, a[200001], s = 0;
vector <int> v[200001];
int val[200001] = {0}, sum[200001] = {0};
int ans = 0;

void dfs1(int node, int parent)
{
	int i;
	sum[node] = a[node];
	fr(i,0,v[node].size())
	{
		if(v[node][i] == parent)continue;
		dfs1(v[node][i], node);
		val[node] += val[v[node][i]] + sum[v[node][i]];
		sum[node] += sum[v[node][i]];
	}
}

void dfs2(int node, int parent)
{
	int i;
	fr(i,0,v[node].size())
	{
		if(v[node][i] == parent) continue;
		int temp = val[node] - val[v[node][i]] - sum[v[node][i]] + (s - sum[v[node][i]]) + val[v[node][i]];
		ans = max(ans, temp);
		val[v[node][i]] = temp;
		dfs2(v[node][i], node);
	}
}

signed main()
{
	FILEIO
 	//start_routine
	cin>>n;
	int i;
	fr(i,1,n +1){cin>>a[i]; s+=a[i];}
	fr(i,1,n)
	{
		int x,y;
		cin>>x>>y;
		v[x].pb(y);
		v[y].pb(x);
	}
	v[0].pb(1);
	dfs1(0,0);
	

	dfs2(0,0);

	cout<<ans<<'\n';
 	//end_routine
}
