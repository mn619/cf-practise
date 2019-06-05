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
int n,q,s[200010]={0},len[200010]={0};
bool in[200001]={0};
vector <int> v[200001];
int cnt=1;

int dfs(int node)
{
	in[node]=1;
	s[cnt++] = node;
	int i;
	fr(i,0,v[node].size())
	{
		if(in[v[node][i]]==0)
		{
			dfs(v[node][i]);
		}
	}
}

int dfs2(int node)
{
	
	in[node]=1;
	if(v[node].empty())
	{
		len[node]=1;
		return 1;
	}
	else
	{
	int i;
	fr(i,0,v[node].size())
	{
		if(in[v[node][i]]==0)
		len[node]+=dfs2(v[node][i]);
	}
	}
	len[node]++;
	return len[node];
}

signed main()
{
 	//start_routine
 	cin>>n>>q;
 	int i;

 	fr(i,2,n+1)
 	{
 		int p;
 		cin>>p;
 		v[p].pb(i);
 	}
 	fr(i,1,n+1)sort(v[i].begin(),v[i].end());

 	dfs(1);
 	fr(i,1,n+1)in[i]=0;
 	dfs2(1);
 	
 	map<int,int> m;
 	fr(i,1,n+1)
 	{
 		m[s[i]]=i;
 	}
 	
 	fr(i,0,q)
 	{
 		int u,k;
 		cin>>u>>k;
 		if(k>len[u] || m[u]+k-1>n)cout<<-1<<"\n";
 		else cout<<s[m[u]+k-1]<<"\n";
 	}
 	//end_routine
}



