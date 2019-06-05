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
signed main()
{
 	//start_routine
 	int n;
 	cin>>n;
 	int a[n];
 	int i;
 	fr(i,0,n)cin>>a[i];
 	vector <int> ans;
 	int cnt=0;
 	fr(i,0,n)
 	{
 		if(a[i]==1)
 		{
 			cnt++;
 			if(i>0)
 			{
 				ans.pb(a[i-1]);
 			}
 		}
 	}
 	ans.pb(a[n-1]);
 	cout<<cnt<<"\n";
 	fr(i,0,ans.size())
 	{
 		cout<<ans[i]<<" ";
 	}
 	//end_routine
}



