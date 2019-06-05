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

int n,m;
int x[300001], y[300001];
int ans[300001] = {0};
int prex[300010] = {0}, suffy[300010] = {0};
pair <int, int> p[300001];



void solve()
{
	vector <int> v[n + 1];
	int i;
	fr(i,1,n+1)v[i].pb(x[i] - y[i]), v[i].pb(x[i]), v[i].pb(y[i]), v[i].pb(i);
	sort(v + 1, v + n + 1);

	fr(i,1,n+1) prex[i] = prex[i - 1] + v[i][1];
	for(i = n; i >= 1; i--) suffy[i] = suffy[i + 1] + v[i][2];

	fr(i,1,n+1)
		ans[v[i][3]] = v[i][2]*(i - 1) + prex[i - 1] + suffy[i + 1] + v[i][1]*(n - i);

	fr(i,1,m+1)
	{
		int i1 = p[i].first, i2 = p[i].second;
		ans[i1] -= min(x[i1] + y[i2], y[i1] + x[i2]);
		ans[i2] -= min(x[i1] + y[i2], y[i1] + x[i2]);
	}
}
signed main()
{
 	start_routine
	
	cin>>n>>m;
	int i;
	fr(i,1,n+1)cin>>x[i]>>y[i];
	fr(i,1,m+1)cin>>p[i].first>>p[i].second;

	solve();
	fr(i,1,n+1)cout<<ans[i]<<" ";

 	end_routine
}
