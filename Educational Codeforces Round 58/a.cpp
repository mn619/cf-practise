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
#define FILEIO freopen("C:/Users/Aman/Desktop/kachda/input.txt", "r", stdin); freopen("C:/Users/Aman/Desktop/kachda/output.txt", "w", stdout);

using namespace std;

signed main()
{
	//FILEIO
 	//start_routine
	
	int tests = 1;
	cin>>tests;

	while(tests--)
	{
		int l, r, d;
		cin>>l>>r>>d;
		int x = (l/d)*d - (l%d == 0)*d;
		x = min(x,d);
		if(x == 0)
		{
			x = (r/d)*d + d;
		}

		cout<<x<<"\n";
	}

 	//end_routine
}