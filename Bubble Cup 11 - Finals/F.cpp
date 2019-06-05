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
int n;
int a[200001];
int x,f;

signed main()
{
 	//start_routine
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	int i;
	cin>>n;
	fr(i,1,n+1) cin>>a[i];
	cin>>x>>f;
	int ans = 0;

	//x*f
	fr(i,1,n+1)
	{
		if(a[i] > x)
		{
			int req = a[i] - x;
			int l = 1, r = req/x+1;
			int ans1 = 0;

			while(l<=r)
			{
				int mid = (l+r)>>1;
				int temp = f*mid;

				if(mid*x +  temp >= req) {ans1 = mid*f; r = mid-1;}
				else l = mid + 1;
			}
			ans+=ans1;
		}
	}
	cout<<ans<<"\n";


 	//end_routine
}
