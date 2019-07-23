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
	int n,k;
	cin>>n>>k;
	int i;
	int a[n+1], mn = mod;
	fr(i,1,n+1)
	{
		cin>>a[i];
		if(mn>a[i]) mn = a[i];
	}

	fr(i,1,n+1)
	{
		a[i]-=mn;
	}

	sort(a+1, a+n+1);
	reverse(a+1, a+n+1);

	int pre[n+1] = {0};
	fr(i,1,n+1)
	{
		pre[i] = pre[i-1] + a[i];
	}

	int ans = 0;
	int sum = 0;
	int s = 0;
	int las = 0;


	fr(i,1,n+1)
	{
		cout<<a[i]<<" ";
		if(sum - las > k)
		{
			ans+=(sum-las)/k + ((sum-las)%k!=0);
		}

		sum = s-a[i]*(i-1);
		s+=a[i];
		las += ((sum-las)/k)*(k+1) - (sum-las)%k;
		cout<<i<<" "<<ans<<" "<<sum<<" "<<s<<' '<<las<<"\n"; 
	}

	cout<<ans<<"\n";
 	//end_routine
}
