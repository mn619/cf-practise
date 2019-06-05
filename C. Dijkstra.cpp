/*
*	Dij using priority queue
*	1-indexed
*
*/


#include<bits/stdc++.h>
#define pb push_back
#define int long long
#define mp make_pair
#define inf 10000000000000

using namespace std;

int n,m,source,end;
vector <int> v[100001];
priority_queue <pair<int,int> > pq;
int dist[100001];
bool in[100001]={0};
int parent[100001]={0};//stores parent in the shortest path from source
map <pair<int,int> ,int> w;

void dij(int source)
{
	pq.push(mp(0,source));
	for(int i=1;i<=n;i++)dist[i]=inf,in[i]=0;
	int cnt=1;
	dist[1]=0;
	while(!pq.empty())
	{
		int u=pq.top().second;
		pq.pop();
		if(in[u])continue;
		in[u]=1;
		
		for(int i=0;i<v[u].size();i++)
		{
			if(dist[v[u][i]]>dist[u]+w[mp(u,v[u][i])]&& !in[v[u][i]])
			{
				dist[v[u][i]]=dist[u]+w[mp(u,v[u][i])];
				pq.push(mp(-dist[u]-w[mp(u,v[u][i])],v[u][i]));
				parent[v[u][i]]=u;
			}
		}
		
	}
}

signed main()
{
 	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin>>n>>m>>source>>end;// n=vertices, m=edges
	
	for(int i=0;i<m;i++)
	{
		int x,y,e;
		cin>>x>>y>>e;//weight e between edges x,y(undirected graph)
		v[x].pb(y);
		v[y].pb(x);
		w[mp(x,y)]=e;
		w[mp(y,x)]=e;
	}
	
	dij(source);//starting at source
	cout<<dist[end];
}



