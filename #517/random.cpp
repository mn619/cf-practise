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
	cout<<(2&3)<<"\n";
	int tests = 1;
	//cin>>tests;

	while(tests--)
	{
		int i;
		fr(i,1,100000)
		{
			if(i*(i+1)/2 > 2*1000000000) {cout<<i<<"\n"; break;}
		}
	}

 	//end_routine
}
