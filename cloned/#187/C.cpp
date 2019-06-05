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
	int n,k;
	cin>>n>>k;
	int j = 1;
	int las = 0;


 	int i;
 	int a[n +1] = {0};
	fr(i,1,n +1)cin>>a[i];
	int d[n + 1] = {0};

	int m = n;
	fr(i,0,n)
	{
		d[i + 1] = d[i] + (i - 1)*a[i] - i*(n -  i - 1)*(a[i + 1]) + (n - i)*(i - 1)*a[i];
	}
	fr(i,1,n +1)
	{
		if(d[i] < k) cout<<i<<"\n";
	}
 	//end_routine
}
