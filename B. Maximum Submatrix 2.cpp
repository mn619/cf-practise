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
int n,m; char a[5001][5001];
signed main()
{
 	//start_routine
 	cin>>n>>m;
  	int i,j;
 	fr(i,1,n+1)fr(j,1,m+1)cin>>a[i][j];

 	int r[n+10][m+1]={{0}};
 	fr(i,1,n+1)
 	{
 		int cnt=0;
 		for(j=m;j>=1;j--)
 		{
 			if(a[i][j]=='1'){r[i][j]=++cnt;continue;}
 			r[i][j]=cnt=0;
 		}
 	}
 	int ans=0;
 	int in[5001]={0};

 	fr(j,1,m+1)
 	{
 		int cnt=0,k=0;
 		fr(i,1,n+1)
 		{
 			in[r[i][j]]++;
 		}
 		for(int i=5000;i>=1;i--){if(in[i] && i*(k+in[i])>ans){ans=i*(k+in[i]);}k+=in[i];in[i]=0;}
 	}
 	cout<<ans;
	//end_routine
}



