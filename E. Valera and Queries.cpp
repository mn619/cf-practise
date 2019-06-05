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
int n,m,x[1000010]={0},cnt[1000010]={0};
signed main()
{
 	//start_routine
 	cin>>n>>m;
 	int i;
 	map <int,bool> mp;
 	fr(i,0,n)
 	{
 		int l,r;
 		cin>>l>>r;
 		x[l]++;
 		x[r+1]--;
 		mp[r]=1;
 	}
 	fr(i,1,1000001)x[i]+=x[i-1];
 	fr(i,1,11)cout<<x[i]<<" ";
 	cout<<"\n";
 	fr(i,1,1000002)
 	{
 		if(mp.count(i-1))cnt[i]++;
 	}
 	fr(i,1,1000001)cnt[i]+=cnt[i-1];
 	fr(i,1,11)cout<<cnt[i]<<" ";

 	cout<<"\n";
 	fr(i,0,m)
 	{
 		int len;
 		cin>>len;
 		vector <int> pt;
 		pt.pb(0),pt.pb(1000000);
 		int j;
 		fr(j,0,len)
 		{
 			int xxx;
 			cin>>xxx;
 			pt.pb(xxx);
 		}
 		sort(pt.begin(),pt.end());
		int ans=n;
		fr(j,1,pt.size())
		{
			ans=ans-(cnt[pt[j]]-cnt[pt[j-1]])+x[pt[j-1]];
		}
		cout<<ans<<"\n";
 	}
	//end_routine
}



