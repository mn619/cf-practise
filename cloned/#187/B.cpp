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
	FILEIO
 	//start_routine
	int n,m;
	cin>>n>>m;
	int a[n + 1];
	int s[n + 1] = {0};

	int sum = 0;
	int i;
	fr(i,1,n +1)cin>>a[i];

	fr(i,1,m +1)
	{
		int t;
		cin>>t;
		if(t == 1)
		{
			int v,x;
			cin>>v>>x;
			s[v] = -sum;
			a[v] = x;
		}
		if(t == 2)
		{
			int y;
			cin>>y;
			sum+=y;
		}
		if(t == 3) 
		{
			int q;
			cin>>q;
			cout<<a[q] + sum + s[q]<<'\n'; 
		}
	}
 	//end_routine
}
