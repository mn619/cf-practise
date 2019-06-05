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

using namespace std;

int r,cl;
int dist[1001][1001]={{0}},vis[1001][1001]={{0}};
char c[1001][1001];
void bfs(int i,int j)
{
	queue <pair <int,int>> q;
	q.push(make_pair(i,j));
	dist[i][j]=0;
	while(!q.empty())
	{
		pair<int,int>  p=q.front();
		q.pop();
		if(p.first<r && dist[p.first+1][p.second]==-1 && c[p.first+1][p.second]!='T')
			dist[p.first+1][p.second]=dist[p.first][p.second]+1,q.push(mp(p.first+1,p.second));
		if(p.first>1 && dist[p.first-1][p.second]==-1 && c[p.first-1][p.second]!='T')
			dist[p.first-1][p.second]=dist[p.first][p.second]+1,q.push(mp(p.first-1,p.second));
		if(p.second<cl && dist[p.first][p.second+1]==-1 && c[p.first][p.second+1]!='T')
			dist[p.first][p.second+1]=dist[p.first][p.second]+1,q.push(mp(p.first,p.second+1));
		if(p.second>1 && dist[p.first][p.second-1]==-1 && c[p.first][p.second-1]!='T')
			dist[p.first][p.second-1]=dist[p.first][p.second]+1,q.push(mp(p.first,p.second-1));
	}
}
signed main()
{
 	//start_routine
 	cin>>r>>cl;
 	pair <int,int>  pos[2];
 	int i,j;
 	fr(i,1,r+1)
 	{
 		fr(j,1,cl+1)
 		{
 			dist[i][j]=-1;
 			cin>>c[i][j];
 			if(c[i][j]=='S')pos[0]=mp(i,j);
 			if(c[i][j]=='E')pos[1]=mp(i,j);
 		}
 	}
 bfs(pos[1].first,pos[1].second);
 int dis=dist[pos[0].first][pos[0].second];
 int ans=0;
 fr(i,1,r+1)fr(j,1,cl+1)if(c[i][j]!='S'&&c[i][j]!='T'&&c[i][j]!='E')if(dist[i][j]<=dis && dist[i][j]!=-1)ans+=c[i][j]-'0';
 cout<<ans;
	//end_routine
}



