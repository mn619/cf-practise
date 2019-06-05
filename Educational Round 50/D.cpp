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

 	int t;
 	cin>>t;
 	while(t--)
 	{
 		int l,r;
 		cin>>l>>r;
 		l--;
 		int l1 = 0, l2 = 0, x1, x2;
 		int temp = l;
 		if(l==0) x1  = 0;
 		while(temp)
 		{
 			if(temp/10 == 0) x1 = temp;
 			l1++;
 			temp/=10;
 		}
 		temp = r;
 		while(temp)
 		{
 			if(temp/10 == 0) x2 = temp;
 			l2++;
 			temp/=10;
 		}

 		l1--;
 		l2--;
 		cout<<x1<<" "<<x2<<' '<<l1<<" "<<l2<<'\n'; 
 		int ans = 1000*(x2*(l2*(l2-1)*(l2-2))/6 - x1*(l1*(l1-1)*(l1-2))/6) ;
 		cout<<ans<<'\n';
 	}
 }
 	//end_routine\
}



