#include<bits/stdc++.h>
#define ll long long int
#define pb push_back

using namespace std;

int main()
{
	int n,m,a,b,c;
	
	cin>>n>>m;
	vector <int> v[n+1][m+1];
	
	
	for(int i=1;i<=m;i++)
	{
		cin>>a>>b>>c;
		v[a][c].pb(b);
		v[b][c].pb(a);
	}
	
	
	int t;
	
	
	cin>>t;
	
	while(t)
	{	
		int start, end;
		cin>>start>>end;
		
		int ans=0;
		for(int c=1;c<=m;c++)
		{
			
			bool visited[n+1]={0};
			queue <int> q;
			
						
			q.push(start);
			
			while(!q.empty())
			{
				int p=q.front();
				q.pop();
			
				for(int i=0;i<v[p][c].size();i++)
				{
					if(visited[v[p][c][i]]==false)
					{
						visited[v[p][c][i]]=true;
						q.push(v[p][c][i]);	
					}
				}
			}
			if(visited[end]==true) ans++;
		}
		cout<<ans<<"\n";
		
		t--;
	}
}

