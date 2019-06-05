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
int n,a[1001];

signed main()
{
 	//start_routine
	cin>>n;
	int i;
	fr(i,0,n)
	{
		cin>>a[i];
		if(a[i]%2==0) a[i]--;
	}
	fr(i,0,n)cout<<a[i]<<" ";

 	//end_routine
}



