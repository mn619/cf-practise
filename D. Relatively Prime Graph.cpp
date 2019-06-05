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
int n,m,cnt[100001],mx=0;
void compute()
{
	int i;
	fr(i,1,100001)cnt[i]=i;

	fr(i,2,100001)
	{
		if(cnt[i]==i)
		{
			int j=i;
			while(j<=100000){cnt[j]=cnt[j]-cnt[j]/i; j+=i;}
		}
	}
}
signed main()
{
 	//start_routine
 	cin>>n>>m;
 	
 	compute();
 	int i;
 	fr(i,2,n+1){mx+=cnt[i];}
 	if(m>mx || m<n-1)
 		return cout<<"Impossible",0;
 	cout<<"Possible\n";
 	fr(i,2,n+1)cout<<1<<" "<<i<<"\n";
 	m=m-n+1;
 	fr(i,2,n+1)
 	{
 		int j;
 		fr(j,2,i)
 		if(__gcd(i,j)==1)
 		{
 			cout<<i<<" "<<j<<"\n";
 			m--;
 			if(m==0)break;
 		}
 	if(m==0)break;
 	}
 	//end_routine
}



