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
 	string s,t;
 	cin>>s>>t;
 	int n=s.size();
 	int m=t.size();
 	int i=0;

 	while(1)
 	{
 		if(s[n-i-1]!=t[m-i-1])break;
 		i++;
 		if(i>=min(n,m))break;
 	}

 	int ans=n+m-2*i;
 	cout<<ans;
 	//end_routine
}



