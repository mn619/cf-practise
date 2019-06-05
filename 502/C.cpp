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
 	int n;
 	cin>>n;
 	vector <int> v[n];
 	int i;
 	fr(i,0,n)
 	{
 		int a,b,c,d;
 		cin>>a>>b>>c>>d;
 		int sum = a+b+c+d;
 		sum=-sum;
 		v[i].pb(sum);
 		v[i].pb(i);
 	}

 	sort(v,v+n);

 	fr(i,0,n)
 	{
 		if(v[i][1]==0)
 		{
 			cout<<i+1;
 			return 0;
 		}
 	}
 	//end_routine
}



