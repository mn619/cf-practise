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

	while(tests--)
	{
		int n,m,k,l;
		cin>>n>>m>>k>>l;
		int mx = n-k;
		if(mx < l || m > n || l+k>n)
		{
			cout<<-1;
			return 0;
		}
		int temp = (l+k)/m;
		if((l+k)%m == 0)
		{
			cout<<temp<<"\n";
		}
		else if( (temp+1)*m <= n)
		{
			cout<<temp+1<<'\n';
		}
		else cout<<-1;
	}

 	//end_routine
}
