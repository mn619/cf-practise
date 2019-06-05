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
int n,m;

signed main()
{
 	//start_routine
 	cin>>n>>m;
 	int p[n+1];
 	int ind=0;
 	int i;
 	fr(i,1,n+1)
 	{
 		cin>>p[i];
 		if(p[i]==m)ind=i;
 	}
 	int ans=1;
 	
 	int s=0,l=0;


 	int a[n+1];
 	fr(i,1,n+1)
 	{
 		if(p[i]==m)a[i]=0;
 		if(p[i]>m)a[i]=1;
 		if(p[i]<m)a[i]=-1;
 	}
 	int pre[n+1]={0};
 	pre[ind]=0;

 	for(int i=ind-1;i>=1;i--)pre[i]=pre[i+1]+a[i];
 	fr(i,ind+1,n+1)pre[i]=pre[i-1]+a[i];

 	map <int,int> fi,sec;

 	fr(i,ind+1,n+1)
 	{
 		sec[pre[i]]++;
 	}

 	fr(i,1,ind+1)
 	{
 		
 		if(pre[i]==0)
 			{
 				ans+=sec[0]15 8
1 15 2 14 3 13 4 8 12 5 11 6 10 7 9
;
 				ans+=sec[1];
 			}
 		else
 		{
 			if(pre[i]<0)
 			{
 				ans+=sec[-pre[i]];
 				ans+=sec[-pre[i]+1];
 			}
 			if(pre[i]>0)
 			{
 				if(pre[i]==+1)ans++;
 				ans+=sec[-pre[i]];
 				ans+=sec[-pre[i]+1];
 			}
 		}
 	}

 	cout<<ans;

 	//end_routine
}



