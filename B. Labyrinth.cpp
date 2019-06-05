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


struct node
{
	int vis, lef, rig;
};
node dp[2001][2001];
char c[2001][2001];

int n,m,rw,cl,x,y;


int solve()
{

	queue < pair <int,int> > q;

	dp[rw][cl] = {1,0,0};
	q.push({rw,cl});

	while(!q.empty())
	{
		int i = q.front().first, j = q.front().second;
		
		q.pop();
		if(j > 1 && c[i][j-1] == '.' && dp[i][j].lef < x && dp[i][j-1].vis == 0)
		{
			q.push({i, j - 1});
			dp[i][j-1] = {1, dp[i][j].lef + 1,  dp[i][j].rig};
		}
		if(j < m && c[i][j+1] == '.' && dp[i][j].rig < y && dp[i][j + 1].vis == 0)
		{
			q.push( {i, j + 1});
			dp[i][j+1] = {1, dp[i][j].lef, dp[i][j].rig + 1};
		}
		if(i>1 && c[i-1][j] == '.' && dp[i - 1][j].vis == 0)
		{
			q.push( {i - 1, j} );
			dp[i - 1][j] = {1, dp[i][j].lef, dp[i][j].rig};
		}
		if(i < n && c[i + 1][j] == '.' && dp[i + 1][j].vis == 0)
		{
			q.push({i + 1, j});
			dp[i + 1][j] = {1, dp[i][j].lef, dp[i][j].rig};
		}
	}

	int i,j;
	int ans = 0;
	cout<<'\n';
	fr(i,1,n+1)
	{
		fr(j,1,m+1)
		{
			if(dp[i][j].vis) cout<<"+";
			else cout<<'*';
			ans+=dp[i][j].vis;
		}
		cout<<'\n';
	}

	return ans;
}

signed main()
{
	//FILEIO
 	start_routine
	
	int tests = 1;
	//cin>>tests;

	while(tests--)
	{
		cin>>n>>m>>rw>>cl>>x>>y;

		int i;
		fr(i,1,n+1)
		{
			int j;
			fr(j,1,m+1)
			{
				cin>>c[i][j];
				dp[i][j] = {0,-1,-1};
 			}
		}

		if( y > x )
		{
			fr(i,1,n+1)
			{
				stack <char> s;
				int j;
				fr(j,1,m+1)
				{
					s.push(c[i][j]);
				}

				fr(j,1,m+1)
				{
					c[i][j] = s.top();
					s.pop();
				}
			}

			cl = m + 1 - cl;
			swap(x, y);
		}

		int ans = 0;
		ans = solve();
		cout<<ans;
	}

 	end_routine
}