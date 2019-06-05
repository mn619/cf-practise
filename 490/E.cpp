#include<bits/stdc++.h>
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define int long long
#define mp make_pair
#define fr(i,a,b) for(i=a;i<b;i++)
#define mod 1000000007

using namespace std;
int n,m,s,cnt;
bool vis[5001]={0};
vector <int> v[5001];

void dfs(int src)
{
	vis[src]=1;
	int i;
	cnt++;
	fr(i,0,v[src].size())
	{
		if(vis[v[src][i]]==0)
		{
			dfs(v[src][i]);
		}
	}
}
signed main()
{
 	//ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin>>n>>m>>s;
	int i;
	fr(i,1,m+1)
	{
		int a,b;
		cin>>a>>b;
		v[a].pb(b);
	}
	vector <int> size[n+1];

	fr(i,1,n+1)
	{
		cnt=0;
		dfs(i);
		int j;
		fr(j,1,n+1)vis[j]=0;
		size[i].pb(-cnt);
		size[i].pb(i);
	}
	sort(size+1,size+n+1);
	dfs(s);
	int ans=0;
	fr(i,1,n+1)if(vis[size[i][1]]==0){ans++; dfs(size[i][1]);}
	cout<<ans;
}



