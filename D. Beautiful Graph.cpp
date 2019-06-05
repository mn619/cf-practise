#include<bits/stdc++.h>
#define start_routine cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false); int begtime = clock();
#define end_routine int endtime = clock(); cerr << endl << "Time elapsed: " << (endtime - begtime)*1000/CLOCKS_PER_SEC << " ms"; return 0;
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define int long long
#define mp make_pair
#define fr(i,a,b) for(i=a;i<b;i++)
#define mod 998244353
#define FILEIO freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
using namespace std;

int n,m,w = 0,cnt = 0, clr[1000001], vis[1000001] = {0}, ans = 1;
vector <int> v[1000001];
bool ok = 1;

int power(int a,int b, int m)
{
	if (b==0)
	return 1;
	int temp = power(a,b/2,m);
	temp = (temp*temp)%m;
	if (b&1)
	return (temp*(a%m))%m; 
	return temp;
}

void dfs(int node, int c)
{
	vis[node] = 1;
	clr[node] = c;
	cnt++, w+=c;

	int i;
	fr(i,0,v[node].size())
	{
		if(vis[v[node][i]] == 1 && clr[v[node][i]] == c) {ans = 0; return;}
		if(vis[v[node][i]]) continue;

		dfs(v[node][i], !c);
	}
}

void reset()
{
	int i;
	fr(i,1,n +1)
	{
		vis[i] = 0;
		v[i].clear();
	}
	ans = 1, w = 0, cnt = 0;
}

signed main()
{
	//FILEIO
 	start_routine
	
	int tests = 1;
	cin>>tests;

	while(tests--)
	{
		cin>>n>>m;
		int i;
		fr(i,1,m + 1)
		{
			int a,b;
			cin>>a>>b;
			v[a].pb(b);
			v[b].pb(a);
		}

		fr(i,1,n +1)
		{
			if(vis[i] == 0)
			{
				cnt = 0, w = 0;
				dfs(i,0);
				if(ok == 0) {ans = 0; break;}
				ans *= power(2,w,mod) + power(2,cnt-w,mod);
				ans%= mod;
			}
		}
		cout<<ans<<"\n";
		reset();
	}

 	end_routine
}
	