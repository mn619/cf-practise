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

int a[1001], n, m;


void compute()
{
	int i;
	fr(i,1,m + 1)
	{
		a[i] = (i*i)%m;
	}
}
signed main()
{
	//FILEIO
 	//start_routine
	
	int tests = 1;
	//cin>>tests;

	while(tests--)
	{
		cin>>n>>m;
		compute();
		vector < pair< int, int > > v;
		int i;

		fr(i,1,m + 1)
		{
			int j;
			fr(j,1,m + 1)
			{
				if((a[i] + a[j])%m == 0)
				{
					v.pb({i,j});
				}
			}
		}

		int c = n/m;
		int ans = 0;

		fr(i,0,v.size())
		{
			int x = v[i].first; 
			int y = v[i].second;
			int fcnt = c, scnt = c;

			if(n%m >= x) fcnt++;
			if(n%m >= y) scnt++;

			ans+=fcnt*scnt;
		}
		cout<<ans<<'\n';
	}

 	//end_routine
}
