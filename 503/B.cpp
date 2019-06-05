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
 	int n,i;
 	cin>>n;
 	int p[n+1];
 	fr(i,1,n+1)
 	{
 		cin>>p[i];
 	}
 	bool in[n+1] = {0};
 	fr(i,1,n+1)
 	{
 		int j;
 		fr(j,1,n+1) in[j] = 0;
 		int temp = i;
 		while(in[temp] !=1)
 		{
 			in[temp] = 1;
 			temp = p[temp];
 		}
 		cout<<temp<< " ";
 	}
 	//end_routine
}



