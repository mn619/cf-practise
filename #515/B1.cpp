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
 	
 	int l;
 	int in[n+1] = {0};
 	int ans  = 0, range = 0;;
 	i = 1;

 	int k = 0;
 	fr(i,1,n+1)
 	{
 		if(a[i] == 1 && i>r) return cout<<-1,0;
 		if(a[i] == 1) {k = i; break;}
 	}

 	for(i = n; i>=0;i--)
 	{
 		if(a[i] == 1 && n-i>r) return cout<<-1,0;
 		if(a[i] == 1) break;
 	}
 	i=k;

 	while(i<=n)
 	{
 		if(a[i] == 1)
 		{
 			int j;
 			bool b = 0, bb  = 0;
 			int temp ;
 			fr(j,max((int) 1,i-r+1),i)
 			{
 				if(a[j] == 1) bb = 1;
 				if(a[j] == 1 && in[j] == 0)
 				{
 					temp = j;
 					range = j+r-1;
 					b = 1;
 				}
 			}
 			if(bb == 0)
 			{
 				in[i] = 1;
 				range = i+r-1;
 			}

 			if(b)in[temp] = 1;
 			else if(b == 0)
 			{
 				fr(j,i+1,i+r)
 				{
 					if(a[j] == 1)
 					{
 						temp = j;
 						range = j+r-1;
 						b = 1;
 					}
 				}
 			}
 			if(b) in[temp] = 1;
 			else if(b == 0)
 			{
 				in[i] = 1;
 				range = i+r-1;
 			}
 			i  = range+1;
 		}
 		else i++;
 		
 	}

 	fr(i,1,n+1) ans+=in[i];
 	if(ans!=0)cout<<ans<<"\n";
 	else cout<<-1;
 	//end_routine
}
