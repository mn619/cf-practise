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

signed main()
{
	//FILEIO
 	//start_routine
	
	int t = 1;
	cin>>t;

	while(t--)
	{
		int n,x,y,d;
		cin>>n>>x>>y>>d;
		if(y%d != x%d && y%d != 1 && y%d != n%d)
		{
			cout<<-1<<'\n';
			continue;
		}
		int ans = mod;
		if(y%d == x%d)
		{
			int l = abs(y-x);
			ans = l/d;
		}

		if(y%d == 1)
		{
			int l = (y-1)/d + ((x-1)/d + (x%d != 1));
			ans = min(ans, l);
		}

		if(y%d == n%d)
		{
			int l = (n-y)/d + (n-x)/d + ((n-x)%d != 0);
			ans = min(ans, l);
		}

		cout<<ans<<'\n';
	}

 	//end_routine
}
