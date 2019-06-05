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
int n,a[101];
signed main()
{
 	//start_routine
 	cin>>n;
 	int i;
 	fr(i,1,n+1)cin>>a[i];
 	sort(a+1,a+n+1);
 	int sum=0;
 	fr(i,1,n+1)sum+=a[i];
 	float f=1.0*4.5*n-1.0*sum;
 	int req;
 	req=ceil(f);
 	if(req<=0)cout<<0;
	else
	{
		int x=0;
		int cnt=0;
		for(int j=1;j<=n;j++)
		{
			x+=5-a[j];
			cnt++;
			if(x>=req)break;
		}
		cout<<cnt;
	}
	//end_routine
}



