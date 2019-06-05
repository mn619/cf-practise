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
int n,m;
vector <int> v;

signed main()
{
 	//start_routine
	cin>>n;
	int i;
	map <int,int> mp;

	fr(i,1,n+1)
	{
		int temp;
		cin>>temp;
		v.pb(temp);
		if(i!=0) v[i-1] = v[i-1]+ temp;
	}
	cin>>m;
	int ans[m];

	fr(i,0,m)
	{
		int q;
		cin>>q;
		vector <int> iterator
	}
	fr(i,0,m)cout<<ans[i]<<" ";
 	//end_routine
}



