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
	int a[101] = {0};
	int i;
	fr(i,1,n +1)
	{
		int x;
		cin>>x;
		a[x]++;
	}
	int ans = 0;
	int las = 0;
	bool in = 0;

	fr(i,1,101)
	{
		if(!in)
		{
			if(a[i]%2) {las = i; in = 1; continue;}
		}
		else if(in)
		{
			if(a[i]%2)
			{
				ans += i - las;
				in = 0;
			}
		}
	}
	cout<<ans<<'\n';

 	//end_routine
}