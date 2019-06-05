#include<bits/stdc++.h>
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define int long long
#define mp make_pair
#define mod 1000000007

using namespace std;

int n,m,a[100002],vis[100002]={0};
bool path[100002]={0};

vector <int> v[100005];

void dfs(int node, int cnt)
{
	vis[node]=1;
	if(cnt>m)path[node]=1;
	for(int i=0;i<v[node].size();i++)
	{
		if(!vis[v[node][i]])
		{
			if(path[node])path[v[node][i]]=1;
			if(a[v[node][i]])dfs(v[node][i],cnt+1);
			else dfs(v[node][i],0);
		}
	}
}
signed main()
{
 	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	
	
	for(int i=1;i<n;i++)
	{
		int x,y;
		cin>>x>>y;
		v[x].pb(y); v[y].pb(x);
	}
	
	a[1]?dfs(1,1):dfs(1,0);
	int ans=0;
	for(int i=2;i<=n;i++)if(v[i].size()==1 && !path[i])ans++;
	cout<<ans;
}



