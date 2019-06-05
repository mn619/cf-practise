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

int a[11][100001];
int mm[11][100001];
signed main()
{
	//FILEIO
 	//start_routine
	
	int tests = 1;
	//cin>>tests;

	while(tests--)
	{
		int n,m;
		cin>>n>>m;

		int i;;
		fr(i,1,m+1)
		{
			int j;
			fr(j,1,n+1)
			{
				cin>>a[i][j];
				if(j>1)
				{
					mm[i][a[i][j-1]]  = a[i][j];
				}
			}
		}

		int ans = 0;
		int j = 2, len = 1;

		while(j<=n)
		{

			bool b = 1;
			fr(i,2,m+1)
			{
				if(mm[i][a[1][j-1]] != a[1][j])
				{
					b = 0;
					break;
				}
			}

			if(b)
			{
				len++;
				j++;
			}
			else 
			{
				ans+=len*(len+1)/2;
				len = 1;
				j++;
			}
		}

		ans+=len*(len+1)/2;

		cout<<ans<<'\n';
	}

 	//end_routine
}
