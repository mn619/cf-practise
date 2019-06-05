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
 	/*
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	*/

	int n;
	cin>>n;
	int l[n+1], r[n+1];
	int ans[n+1];
	int i;
	fr(i,1,n+1) cin>>l[i];
 	fr(i,1,n+1) cin>>r[i];
 	int in[n+1] = {0};

 	vector <int> v;
 	set <int> s;
 	fr(i,1,n+1)
 	{
 		if(l[i] == 0 && r[i] == 0)
 		{
 			v.pb(i);
 			in[i] = 1;
 		}
 	}

 	int cnt = 0, t = n, add = v.size();

 	while(cnt<n)
 	{
 		if(v.size() == 0) return cout<<"NO\n",0;
 		cnt+=v.size();
 		fr(i,0,v.size())
 		{
 			ans[v[i]] = t;
 			int j;
 			fr(j,v[i]+1,n+1)
 			{
 				if(!in[j]) l[j]--;
 			}

 			fr(j,1,v[i])
 			{
 				if(!in[j]) r[j]--;
 			}
 		}
 		t--;
 		v.clear();

 		fr(i,1,n+1) 
 		{
 			if(l[i] == 0 && r[i] == 0 && !in[i])
 			{
 				in[i] = 1;
 				v.pb(i);	
 			}
 		}
 	}

 	cout<<"YES\n";
 	fr(i,1,n+1) cout<<ans[i]<<" ";
 	//end_routine
}
