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
#define FILEIO freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
using namespace std;

signed main()
{
	//FILEIO
 	//start_routine
	int n,s ;
	cin>>n>>s;
	int v[n + 1];
	int i;
	fr(i,1,n + 1)cin>>v[i];
	sort(v + 1, v+  n +1);
	reverse(v + 1, v + n +1);

	int sum = 0;
	fr(i,1,n +1)
	{
		sum += v[i] - v[n];
	}


	if(sum >= s)
	{
		cout<<v[n];
		return 0;
	}

	int d = s - sum;
	int ans = v[n] - (d/n) - (d%n!=0);
	if(ans >= 0) cout<<ans<<'\n';
	else cout<<-1;

 	//end_routine
}
