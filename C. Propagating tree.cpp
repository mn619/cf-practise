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
int n,m;
vector <int> v[200001];
int add[200001]={0}, a[200001], x;

void dfs(int node, int par,int val)
{
	int i;
	a[node]+=add[node]+val;
	val+=add[node];
	add[node] = 0;
	if(node == x) return;

	fr(i,0,v[node].size())
	{
		if(v[node][i]==par)continue;
		else
		{
			dfs(v[node][i], node, -val);
		}
	}
}


void read()
{
	cin>>n>>m;
	int i;
	fr(i,1,n+1)
	{
		cin>>a[i];
	}
	fr(i,1,m)
	{
		int x,y;
		cin>>x>>y;
		v[x].pb(y);
		v[y].pb(x);
	}
}

void solve()
{
	int type,val;
	while(m--)
	{
		cin>>type;
		if(type==1)
		{
			cin>>x>>val;
			add[x]+=val;
		}
		else 
		{
			cin>>x;
			dfs(1,0,0);
			cout<<a[x]<<'\n';
		}
	}
}
signed main()
{
 	//start_routine
	read();
	solve();
 	//end_routine
}



