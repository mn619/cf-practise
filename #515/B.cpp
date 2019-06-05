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

 	int n,r;
 	cin>>n>>r;
 	bool a[n+1];
 	int i;
 	fr(i,1,n+1)cin>>a[i];

 	int las  = -1, range = 0, ans =0;
 	fr(i,1,n+1)
 	{
 		if(a[i] == 0 && range<i)
 		{
 			if(las!=-1)
 			{
	 			range=las+r-1;
	 			las=-1;
	 			ans++;
 			}
 			if(range-i>r) return cout<<-1,0;
 		}

 		if(a[i] == 1)
 		{
 			if(range<i)
 			{
 				if(range-i>r) 
 					{
 						if(las == -1) return cout<<-1,0;
 						else 
 						{
 							if(las+r-1<i) return cout<<-1,0;
 							else range = las+r-1;
 						}
 					}
 				else 
 				{	
 					las = -1;
 					range = i+r-1;
 					ans++;
 				}
 			}
 			else 
 			{
 				las = i;
 				range = i+r-1;
 			}
 			
 		}

 	}
 	if(ans!=0) cout<<ans<<"\n";
 	else cout<<-1;
 	//end_routine
}
