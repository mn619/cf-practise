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
int a[101][101] = {{0}};

signed main()
{
	//FILEIO
 	//start_routine
	
	int tests = 1;
	//cin>>tests;
	int i;

	fr(i,0,101) a[0][i] = 1;

	while(tests--)
	{
		cin>>n;
		fr(i,1, n+1)
		{
			int r;
			cin>>r;
			int j;
			fr(j,1,r+1)
			{
				int x;
				cin>>x;
				if(a[i-1][x] == 1) a[i][x] = 1;
			}
		}

		fr(i,1,101) if(a[n][i] == 1)cout<<i<<" ";
	}

 	//end_routine
}
