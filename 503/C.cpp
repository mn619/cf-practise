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
 	int n,m;
 	cin>>n>>m;
 	int p[n+1],c[m+1];
 	int i;
 	int ans[n+1] = {0}, max = 0,sum = 0;
 	int vote[m+1] =  {0};
 	set < pair<int,int> > s;

 	fr(i,1,n+1)
 	{
 		cin>>p[i]>>c[i];
 		vote[p[i]]++;
 		if(vote[p[i]]>vote[max]) max = p[i];
 		if(p[i]!=1) s.insert(mp(c[i],p[i]));
 		if(max!=1)
 			{
 				
 			}
 		else ans[i] = sum;
 	}
 	cout<<ans<<'\n';
 	

 	
 	//end_routine
}



