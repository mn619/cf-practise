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
	
	int n;
	cin>>n;
	int a[n + 1];
	int i;
	fr(i,0,n)
	{
		cin>>a[i];
	}


	fr(i,0,(1<<n))
	{
		int mask = i;
		int cnt = 0;
		int sum = 0;
		while(cnt < n)
		{
			if(mask&1) sum += a[cnt];
			else sum -= a[cnt];
			mask /= 2;
			cnt++;
		}
		if(sum%360 == 0) return cout<<"Yes\n", 0;
	}
	return cout<<"NO\n", 0;


 	//end_routine
}
