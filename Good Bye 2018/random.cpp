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
	
	int r,y,b;
	cin>>y>>b>>r;
	int ans = 0;
	if(b >= y + 1 && r >= y + 2)
	{
		ans = max(ans, y + y + 1 + y + 2);
	}
	if(y >= b - 1 && r >= b + 1)
	{
		ans = max(ans, 3*b);
	}
	if(y >= r - 2 && b >= r - 1) ans = max(ans, 3*r - 3);

	cout<<ans<<'\n';
 	//end_routine
}
