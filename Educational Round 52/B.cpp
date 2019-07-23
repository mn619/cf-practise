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
int k =0;

signed main()
{
 	//start_routine
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	int n,m;
	cin>>n>>m;
	if(m == 0)
	{
		cout<<n<<" "<<n<<"\n";
		return 0;
	}
	
	int mn,mx;
	mn = max((int)0, n-2*m);
	
	int i = 0;
	while(i*(i-1)/2<=m) i++;
	i--;
	k = i;
	m-=k*(k-1)/2;
	while(m>0)
	{
		m-=k;
		k++;
	}
	cout<<mn<<" "<<max((int)0,n-k)<<"\n";
 	//end_routinex
}
