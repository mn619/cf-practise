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
	int q;
	cin>>q;
	while(q--)
	{
		int x,y,k;
		cin>>x>>y>>k;
	 	int temp = min(x,y);
	 	y = max(x,y);
	 	x = temp;

	 	if(k<y) cout<<-1<<"\n";

	 	else
	 	{
	 		if((x+y)%2 == 1)
	 		cout<<k-1<<"\n";
	 		else
	 		{
	 			if(k%2 == (y)%2) cout<<k<<"\n";
	 			else cout<<k-2<<"\n";
	 		}
	 	}
 	}	
 	//end_routine
}



