#include<bits/stdc++.h>
#define start_routine cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false); int begtime = clock();
#define end_routine int endtime = clock(); cerr << endl << "Time elapsed: " << (endtime - begtime)*1000/CLOCKS_PER_SEC << " ms"; return 0
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define int long long
#define mp make_pair
#define fr(i,a,b) for(i=a;i<b;i++)
#define mod 1000000007

using namespace std;
int n,m,ans=0,vis[200001]={0},vis2[200001]={0};
vector <int> v[200001];

void dfs1(int src)
{
	int i;
	vis[src]=1;
	vis2[src]=1;
	fr(i,0,v[src].size())if(vis2[v[src][i]]==0)dfs1(v[src][i]);
}

int dfs(int src)
{
	vis[src]=1;
	if(v[src].empty())return 0;
	if(v[src].size()!=2)
	{
		dfs1(src);
		return 0;
	}
	if(vis[v[src][0]]==0)return dfs(v[src][0]);
	else if(vis[v[src][1]]==0) return dfs(v[src][1]);
	else return 1;
}

signed main()
{
 	start_routine
	cin>>n>>m;
	int i;
	fr(i,0,m)
	{
		int x,y;
		cin>>x>>y;
		v[x].pb(y);
		v[y].pb(x);
	}	
	
	fr(i,1,n+1)if(!vis[i])ans+=dfs(i);
	cout<<ans;
	end_routine;
}



