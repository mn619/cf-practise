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

using namespace std;
int n,m,a[200001];

signed main()
{
 	//start_routine
	cin>>n>>m;
	int ans[n], last = 0;
	int i;
	
	fr(i,0,n)
	{
		cin>>a[i];
		ans[i] = (last + a[i])/m;
		last = (last + a[i])%m;
	}
	fr(i,0,n)cout<<ans[i]<<" ";
 	//end_routine
}



