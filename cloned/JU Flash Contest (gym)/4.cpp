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
	int n,m,k;
	cin>>n>>m>>k;
	int i;
	int a[n+ 1];
	bool in  = 0;
	fr(i,1,n +1){cin>>a[i]; if(a[i] == m)in = 1;}
	sort(a + 1, a + n + 1);
	int ind = n+1;
	fr(i,1,n + 1)if(a[i] > m){ind = i - 1; break;}
	if(ind != n + 1)
	{
		if(n - ind > k)
		{
			cout<<"NO";
			return 0;
		}
		return cout<<"YES\n",0;
	}

	if(in || k > 0)
	{
		cout<<"YES\n";
		return 0;
	}

	cout<<"NO";

 	//end_routine
}
