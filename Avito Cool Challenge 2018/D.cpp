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

int n,m,k;
int x[100001],  vis[100001] = {0};
priority_queue <pair<int,int>> b[100001];
vector <int> v[100001];
map <pair<int,int> , int> w;
priority_queue <pair<int, pair<int, int>> > pq;

void dfs(int node, int parent, int wt, int root)
{
	vis[node] = 1;
	int i;
	if(!b[node].empty())
	if(b[node].top().second == root)
	{
		b[node].pop();
	}
	b[node].push({wt, root});
	fr(i,0,v[node].size())
	{
		if(v[node][i] == parent || vis[v[node][i]]) continue;
		if(w[{node, v[node][i]}] <= wt)
		{
			dfs(v[node][i], node, wt, root);
		}
	}
	vis[node] = 0;
}
signed main()
{
	FILEIO
 	//start_routine
	cin>>n>>m>>k;
	int i;
	fr(i,1,k + 1)
	{
		int temp;
		cin>>temp;
		x[temp] = 1;
	}

	fr(i,1,m + 1)
	{
		int a,b,c;
		cin>>a>>b>>c;
		v[a].pb(b);
		v[b].pb(c);
		w[{a,b}] = w[{b,a}] = c;
		if(x[a] == 1 || x[b] == 1) pq.push({c,{a,b}});
	}

	cout<<"\n";
	while(!pq.empty())
	{
		int a = pq.top().second.first, b = pq.top().second.second;
		int wt = pq.top().first;
		pq.pop();
		if(a == b) continue;
		cout<<a<<" "<<b<<" "<<wt<<'\n';
		if(x[b])dfs(a,b,wt, b);
		if(x[a])dfs(b,a,wt,a);
	}

	fr(i,1,n + 1)
	{
		if(x[i]) cout<<b[i].top().first<<" ";
	}

 	//end_routine
}
