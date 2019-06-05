#include<bits/stdc++.h>
#define ll long long int
#define pb push_back

using namespace std;

int n;
vector <int> v[100002];
bool visited[100002]={0};
vector <int> height[100002];
vector <int> depth[100002];
int maxdc[100002]={0};

void read()
{
	cin>>n;
	for(int i=1;i<n;i++)
	{
		int a,b;
		cin>>a>>b;
		v[a].pb(b);
		v[b].pb(a);
	}
}

void dfsH(int node)
{
	int maxdcans;
	int h=1;
	visited[node]=1;
	for(int i=0;i<v[node].size();i++)
	{
		if(visited[v[node][i]]==0)
		{
			dfsH(v[node][i]);
			if(height[v[node][i]][0]+1>h)
			{
				h=height[v[node][i]][0]+1;
				maxdcans=v[node][i];
			}
		}		
	}
	height[node].pb(h);
	height[node].pb(node);
	if(h==1)maxdc[node]=-1;
	else maxdc[node]=maxdcans;
}

void dfsD(int node)
{
	visited[node]=1;
	//cout<<node<<" "<<depth[node][0]<<"\n";
	
	for(int i=0;i<v[node].size();i++)
	{
		if(visited[v[node][i]]==0)
		{
			depth[v[node][i]].pb(depth[node][0]+1);
			depth[v[node][i]].pb(v[node][i]);
			dfsD(v[node][i]);
		}
	}
}


void solve()
{
	depth[1].pb(1);depth[1].pb(1);
	
	dfsD(1);
	
//	cout<"hello";
	sort(depth+1,depth+1+n);
	for(int i=1;i<=n;i++)visited[i]=0;		
	
	dfsH(depth[n][1]);
	
	int h[n+1];
	for(int i=1;i<=n;i++)h[i]=height[i][0];
	//for(int i=0;i<n;i++)cout<<h[i+1]<<"\n";
	
	sort(height+1,height+1+n);
	int ans=1;
	cout<<ans<<" ";
	int j=1;
	
	//for(int i=n;i>=1;i--)cout<<height[i][0]<<" "<<maxdc[i]<<"\n";
	//cout<<height[n][0]<<" "<<height[n][1]<<"\t"<<height[1][0]<<height[1][1]<<"\n\n";
	h[height[n][1]]=0;
	//for(int i=1;i<=n;i++)cout<<height[i][1]<<"\n";
	for(int i=n;i>=1;i--)
	{
		if(h[height[i][1]]!=0)
		{
			//cout<<height[i][1]<<"\t";
			ans+=h[height[i][1]];
			cout<<ans<<" ";
			j++;
			int x = height[i][1];
			while(1)
			{
				h[x]=0;
				x=maxdc[x];
			//	cout<<x<<"\n";
				if(x==-1) break;
			}
		}
	}
	while(j<n){cout<<n<<" "; j++;}
	
}
int main()
{
 	//ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	read();
	solve();
}


