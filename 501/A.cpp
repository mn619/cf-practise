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
 	int n,m,i;
 	cin>>n>>m;
 	bool in[m+1] = {0};
 	fr(i,0,n)
 	{
 		int l,r;

 		cin>>l>>r;
 		int j;
 		fr(j,l,r+1)
 		{
 			in[j] = 1;
 		}
 	}

 	vector <int> v;
 	fr(i,1,m+1)
 	{
 		if(!in[i])v.pb(i);
 	}
 	cout<<v.size()<<"\n";
 	fr(i,0,v.size())cout<<v[i]<<" ";
 	//end_routine
}



