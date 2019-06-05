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
int n,m,a[100001],len[100002];
signed main()
{
 	//start_routine
 	cin>>n>>m;
 	int i;
 	a[0]=0;
 	fr(i,1,n+1){cin>>a[i]; len[i]=a[i]-a[i-1];}
 	len[n+1]=m-a[n];

 	int post[n+4][2]={{0}},pre[n+4][2]={{0}};
 	post[n+1][(n+1)&1]=len[n+1];
 	post[n][n&1]=len[n];
 	pre[1][1]=len[1];
 	pre[2][0]=len[2];
 	for(int i=n-1;i>=1;i--)
 	{
 		post[i][i&1]=post[i+2][(i)&1]+len[i];
 	}
 	fr(i,3,n+2)
 	{
 		pre[i][i&1]=pre[i-2][i&1]+len[i];
 	}
 	int ans=max(post[1][1],post[2][0]);
 	
 	fr(i,1,n+2)
 	{
 		if(i&1)
 		{
 			if(pre[i-2][i&1]+len[i]-1+post[i+1][(i+1)&1]>ans && i-2>=0)ans=pre[i-2][(i-2)&1]+len[i]-1+post[i+1][(i+1)&1];
 		}
 		else
 		{
 			if(pre[i-1][(i-1)&1]+len[i]-1+post[i+2][(i+2)&1]>ans)ans=pre[i-1][(i-1)&1]+len[i]-1+post[i+2][(i+2)&1];
 		}
 	}
 	cout<<ans;
	//end_routine
}



