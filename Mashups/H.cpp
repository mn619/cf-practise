#include<bits/stdc++.h>
#define ll long long int
#define pb push_back

using namespace std;


void dij(int source,int n,vector<int> v[],int l[][101],int dist[])
{
	for(int i=1;i<=n;i++)dist[i]=INT_MAX;
	//cout<<"in dij\n";
	dist[source]=0;
	
	bool in[n+1]={0};
	in[source]=1;
	
	int k=1;
	while(k<n)
	{
		int min=INT_MAX;
		int mindex;
		for(int i=1;i<=n;i++)
		{
			if(in[i])
			{
				for(int j=0;j<v[i].size();j++)
				{
					if (dist[i]+l[i][v[i][j]]<min && in[v[i][j]]==0){mindex=v[i][j]; min=dist[i]+l[i][v[i][j]];}
				}
			}
		}
		//cout<<mindex<<" "<<min<<endl;
		dist[mindex]=min;
		k++;
		in[mindex]=1;
		
	}
	
}
int main()
{
 	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin>>t;
	int casex=0;
	while(t--)
	{
		casex++;
		int n,m,f;
		cin>>n>>m>>f;
		int l[n+1][101]={0};
		vector <int> v[n+1];
		ll ans=0;
		for(int i=1;i<=m;i++)
		{
			int x,y,z;
			cin>>x>>y>>z;
			v[x].pb(y);
			v[y].pb(x);
			l[x][y]=z;
			l[y][x]=z;
		}
		
		int fs[f+1],dist[n+1];
		for(int i=1;i<=f;i++)cin>>fs[i];
		
		
		
		dij(1,n,v,l,dist);
		//cout<<"hello";
		int min=INT_MAX;
		int next;
	

	
		for(int i=1;i<f;i++)
		{
			if(dist[fs[i]]<min)
			{
				min=dist[fs[i]];
				next=fs[i];
			}
		}
		ans+=min;
		
		bool b[n+1]={0};
		b[next]=1;
		
		for(int i=1;i<f;i++)
		{
			dij(next,n,v,l,dist);
			min=INT_MAX;
			
			for(int j=1;j<=f;j++)
			{
				if(dist[fs[j]]<min && b[fs[j]]==0)
				{
					min=dist[fs[j]];
					next=fs[j];
				}
			}
		
			ans+=min;
			b[next]=1;
		}
		
		
		dij(next,n,v,l,dist);
		
		ans+=dist[n];
		
		cout<<"Case "<<casex<<": "<<ans<<"\n";
	}

}


