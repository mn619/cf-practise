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
 	int n,k;
 	cin>>n>>k;

 	if(k>2*n-1) return cout<<0,0;

 	if(k<=n)
 	{
 		cout<<k/2 - !(k%2)<<'\n';
 		return 0;
 	}

 	cout<<(2*n-k+1)/2;

 	//end_routine
}



