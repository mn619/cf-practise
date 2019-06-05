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
	int n,m;
	int i;
	cin>>n;
	int a[n+1];
	fr(i,1,n+1)cin>>a[i];
	cin>>m;
	int b[m+1];
	fr(i,1,m+1) cin>>b[i];

	int j = 1, x = 0, y = 0, ans = 0;
	i = 1;
	while(i<=n || j<=m)
	{
		if(i == n +1)
		{
			y+=b[j];
			j++;
		}
		else if(j==m +1)
		{
			x+=a[i];
			i++;
		}
		else
		{
			if(x+a[i]<=y) {x+=a[i]; i++;}
			else {y+=b[j]; j++;}
		}
		cout<<i<<" "<<j<<" "<<x<<" "<<y<<"\n";
		if(x == y )
		{
			ans++;
			x = 0; 
			y = 0;
		}
	}
	cout<<ans<<'\n';
 
 	//end_routine
}



