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
	
	int tests;
	cin>>tests;

	while(tests--)
	{
		int s,a,b,c;
		cin>>s>>a>>b>>c;
		int k = a*c;
		int ans = 0;
		int temp = (s/k);
		ans+=temp*b + temp;
		s-=temp*c;
		ans+=s/c;
		cout<<ans<<'\n';
	}


 
 	//end_routine
}
