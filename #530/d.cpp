#include<bits/stdc++.h>
#define start_routine cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false); int begtime = clock();
#define end_routine int endtime = clock(); cerr << endl << "Time elapsed: " << (endtime - begtime)*1000/CLOCKS_PER_SEC << " ms"; return 0;
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define int long long
#define mp make_pair
#define fr(i,a,b) for(i=a;i<b;i++)
#define inf 1000000007
#define FILEIO freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
using namespace std;


vector <int> v[100001];
int n, s[100001];
int a[100001] = {0};

bool ok = 1;
void dfs(int node, int parent)
{
	int i;
	if(s[node] != -1)
	{
		a[node] = s[node] - s[parent];
	}
	else
	{
		int temp = inf;
		fr(i,0,v[node].size())
		{
			if(v[node][i] == parent) continue;
			temp = min(s[v[node][i]] - s[parent], temp);
		}
		if(temp == inf) temp = 0;
		a[node] = temp;
		s[node] = s[parent] + a[node];
	}
	fr(i,0,v[node].size())
	{
		if(v[node][i] == parent) continue;
		dfs(v[node][i], node);
	}
}
signed main()
{
	//FILEIO
 	start_routine
	
	cin>>n;
	int i;
	fr(i,2,n + 1)
	{
		int p;
		cin>>p;
		v[i].pb(p);
		v[p].pb(i);
	}
	fr(i,1,n + 1)cin>>s[i];

	dfs(1,0);

	int ans = 0;
	fr(i,1,n + 1)
	{
		ans +=a[i];
		if(a[i] < 0) return cout<<-1,0;
	}
	cout<<ans;
 	end_routine
}