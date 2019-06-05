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
	
	int tests = 1;
	//cin>>tests;

	int a[101];
	int n;
	cin>>n;
	int i;
	fr(i,1,n +1)
	{
		cin>>a[i];
	}

	int ans = mod;
	fr(i,1,n+1)
	{
		int j;
		int temp = 0;
		fr(j,1,n + 1)
		{
			temp += 2*a[j]*(abs(i - j) + abs(i - 1) + abs(j - 1));
		}
		ans = min(temp, ans);
	}
	cout<<ans<<'\n';

 	//end_routine
}
