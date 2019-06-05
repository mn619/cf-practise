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
int n,m,x,d;
long double ans=0;

int f(int d)
{
	int temp = (n+1)/2;
	if(d>0)
	{
		temp = 1;
		return n*(n-1);
	}

	return  (temp-1)*temp + (n-temp)*(n-temp+1);
}

signed main()
{
 	//start_routine
 	cin>>n>>m;
 	int i,temp = 0;
 	fr(i,1,m+1)
 	{
 		cin>>x>>d;
 		ans=ans+1.0*x;
 		temp += 1.0*(d*f(d));
 	}
 	ans += 1.0*temp/(2*n);
 	cout<<setprecision(20)<<ans;
 	//end_routine
}



