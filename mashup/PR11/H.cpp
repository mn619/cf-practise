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
 	char c[n+1][n+1];
 	int i,j;
 	fr(i,1,n+1)
 	{
 		fr(j,1,n+1)cin>>c[i][j];
 	}
 	char x=c[1][1],y=c[1][2];
 	fr(i,1,n+1)
 	{
 		if(c[i][i]!=x)return cout<<"NO",0;
 	}
 	fr(i,1,n+1)
 	{
 		if(c[i][n-i+1]!=x)return cout<<"NO",0;
 	}
 	fr(i,1,n+1)
 	{
 		fr(j,1,n+1)
 		{
 			if(i==j || j==n-i+1) continue;
 			if(c[i][j]==x||c[i][j]!=y)return cout<<"NO",0;
 		}
 	}
 	cout<<"YES";
	//end_routine
}



