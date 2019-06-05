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
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	
	int n,w,b;
	cin>>n>>w>>b;
	int c[n+1];
	int i;
	fr(i,1,n+1)cin>>c[i];
	fr(i,1,n/2+1)
	{
		if( (c[i]==1 && c[n-i+1]==0 )|| (c[i]==1 && c[n-i+1]==0))
		{
			return cout<<-1,0;
		}
	}
	int ans = 0;
	fr(i,1,n/2+1)
	{
		if(c[i] == 2 || c[n-i+1] == 2)
		{
			if(c[i]==1)
			{
				ans+=b;
			}
			else if(c[i] == 0)
			{
				ans+=w;
			}
			else 
			{
				if(c[n-i+1] == 2)
					ans+=2*min(w,b);
				else if(c[n-i+1] == 1) ans+=b;
				else ans+=w;
			}
		}
	}
	if(n%2)
	{
		if(c[n/2+1] == 2) ans+=min(w,b);
	}
	cout<<ans<<"\n";
 
 	//end_routine
}



