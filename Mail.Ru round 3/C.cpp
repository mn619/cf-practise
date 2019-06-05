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
#define FILEIO freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
using namespace std;

int n;
vector <int> v[100001];
int ans[100001] = {0}, child[100001] = {0};
vector <int>  leaf[100001];
int depth[100001];



void dfs(int node, int parent, int d)
{
	int i;
	int s = 1, l = 0;
	depth[node] = d;

	fr(i,0,v[node].size())
	{
		if(v[node][i] != parent) 
			{
				dfs(v[node][i], node, d + 1);
				s += child[v[node][i]];
				l += leaf[v[node][i]][0];
			}
	}

	child[node] = s;
	if(s == 1) l = 1;
	leaf[node].pb(l);
	leaf[node].pb(node);

}

signed main()
{
	//FILEIO
 	//start_routine
	
	int tests = 1;
	//cin>>tests;

	while(tests--)
	{
		cin>>n;
		int i;
		fr(i,2,n+1)
		{
			int p;
			cin>>p;
			v[i].pb(p);
			v[p].pb(i);
		}

		dfs(1, 0, 0);


		sort(leaf + 1, leaf + 1 + n);

		int cnt[n+1]={0};
		int las = 1;
		fr(i, 1, n + 1)
		{
			if(leaf[i][0] > las) cnt[las] = i - 1;
			las = leaf[i][0];
		}
		cnt[las] = n;

		las = 0;

		fr(i,1,n+1)
		{

			int k = cnt[i] - las;
			if(k>=0) las = cnt[i];
			
			int j;
			fr(j,1,k + 1) cout<<i<<" ";
		}
	}

 	//end_routine
}
