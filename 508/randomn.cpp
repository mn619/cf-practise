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
	int n;
	cin>>n;
	int a[n+1];
	int i;
	fr(i,1,n+1) cin>>a[i];
	if(n==1) return cout<<a[1]<<"\n",0;
	if(n==2)
	{
		int temp = a[1]-a[2];
		if(temp>=0) return cout<<temp<<"\n",0;
		else return cout<<-temp<<"\n",0;
	}

	sort(a+1, a+n+1);

	int ans = 0, j = 1;
	if(a[1]>0) {j = 2; ans-=a[1];}
	if(a[1]<=0 && a[n]<=0)
	{
		ans+=a[n];
		j=2;
		reverse(a+1, a+n+1);
	}
	
	fr(i,j,n+1)
	{
		if(a[i]>0) ans+=a[i];
		else ans-=a[i];
	}
	cout<<ans<<"\n";
 
 	//end_routine
}

