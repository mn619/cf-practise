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
#define double long double

signed main()
{
	//FILEIO
 	//start_routine
	cout<<setprecision(1001);
	int tests = 1;
	//cin>>tests;
	double n = 1;
	int i;
	fr(i,1,101)
	{
		n*=i;
	}
	cout<<n;

		//end_routine
}
